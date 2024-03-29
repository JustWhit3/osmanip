//====================================================
//     File data
//====================================================
/**
 * @file multi_progress_bar.hpp
 * @author Gianluca Bianco
 * (biancogianluca9@gmail.com) & Ted Lyngmo
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_PROGRESSBAR_MULTIPROGRESSBAR_HPP
#define OSMANIP_PROGRESSBAR_MULTIPROGRESSBAR_HPP

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/manipulators/cursor.hpp>
#include <osmanip/utility/iostream.hpp>

// STD headers
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace osm {

    //====================================================
    //     Structs
    //====================================================

    // indices
    /**
     * @brief Type to generate indices for parameter packs.
     *
     * @tparam Is The indices to generate.
     */
    template <size_t... Is>
    struct indices {};

    // gen_indices
    /**
     * @brief Type to generate indices for parameter packs.
     *
     * @tparam I The index to generate.
     * @tparam Is The indices to generate.
     */
    template <size_t N, size_t... Is>
    struct gen_indices : gen_indices<N - 1, N - 1, Is...> {};

    // gen_indices specialization
    /**
     * @brief Type to generate indices for parameter packs.
     *
     * @tparam I The index to generate.
     * @tparam Is The indices to generate.
     */
    template <size_t... Is>
    struct gen_indices<0, Is...> : indices<Is...> {};

    //====================================================
    //     make_MultiProgressBar
    //====================================================
    /**
     * @brief Template class used to create multi progress bars.
     *
     * @tparam Indicators The parameter pack of the various progress bar types.
     */
    template <class... Indicators>
    class make_MultiProgressBar {
        public:

            // Parametric constructor
            /**
             * @brief Construct a new make MultiProgressBar object.
             *
             * @tparam Inds The parameter pack of the various progress bar types indicators.
             * @param bars The progress bars.
             */
            template <class... Inds>
            make_MultiProgressBar(Inds &&...bars) : bars_{std::forward<Inds>(bars)...}, last_updated_index(0) {}

            // size
            /**
             * @brief Return the number of the indicators.
             *
             * @return size_t The number of the indicators.
             */
            static size_t size() { return sizeof...(Indicators); }

            // for_one
            /**
             * @brief Method used to update the progress bar for one progress bar only.
             *
             * @tparam Func The type of the callable object (e.g., a function, lambda, or functor).
             * @tparam Args The types of the additional arguments that will be passed to the callable.
             *
             * @param idx The index of the progress bar to update.
             * @param func The callable object used to update the progress bar.
             * @param args Additional arguments to be passed to the callable.
             */
            template <class Func, class... Args>
            void for_one(size_t idx, Func &&func, Args &&...args) {
                call_one(idx, gen_indices<sizeof...(Indicators)>(), std::forward<Func>(func),
                         std::forward<Args>(args)...);
            }

            // for_each
            /**
             * @brief Method used to update progress bars simultaneously.
             *
             * @tparam Func The type of the callable object (e.g., a function, lambda, or functor).
             * @tparam Args The types of the additional arguments that will be passed to the callable.
             *
             * @param idx The index of the progress bar to update.
             * @param func The callable object used to update the progress bar.
             * @param args Additional arguments to be passed to the callable.
             */
            template <class Func, class... Args>
            void for_each(Func &&func, Args &&...args) {
                call_all(gen_indices<sizeof...(Indicators)>(), std::forward<Func>(func), std::forward<Args>(args)...);
            }

        private:

            // call_one
            /**
             * @brief Method used to call only one progress bar for update.
             *
             * @tparam Ids Variadic template parameter representing the indices of the progress bars to update.
             * @tparam Func The type of the callable object (e.g., a function, lambda, or functor).
             * @tparam Args The types of the additional arguments that will be passed to the callable.
             *
             * @param idx The index of the progress bar to update.
             * @param indices An instance of the "indices" template used to expand the variadic template parameter Ids.
             * @param func The callable object used to update the progress bar.
             * @param args Additional arguments to be passed to the callable.
             */
            template <size_t... Ids, class Func, class... Args>
            void call_one(size_t idx, indices<Ids...>, Func func, Args &&...args) {
                std::lock_guard<std::mutex> lock{mutex_};
                int32_t idx_delta = idx - last_updated_index;
                std::string direction;

                if (idx_delta < 0) {
                    direction = "up";
                    idx_delta = -idx_delta;
                } else {
                    direction = "down";
                }
                for (int32_t i = 0; i < idx_delta; i++) {
                    osm::cout << feat(crs, direction, 1);
                }
                last_updated_index = idx;
                [](...) {}

                ((idx == Ids &&
                  ((void)std::forward<Func>(func)(std::get<Ids>(bars_), std::forward<Args>(args)...), false))...);
            }

            // call_all
            /**
             * @brief Method used to call all progress bars for update.
             *
             * @tparam Ids Variadic template parameter representing the indices of the progress bars to update.
             * @tparam Func The type of the callable object (e.g., a function, lambda, or functor).
             * @tparam Args The types of the additional arguments that will be passed to the callable.
             *
             * @param indices An instance of the "indices" template used to expand the variadic template parameter Ids.
             * @param func The callable object used to update the progress bars.
             * @param args Additional arguments to be passed to the callable.
             */
            template <size_t... Ids, class Func, class... Args>
            void call_all(indices<Ids...>, Func func, Args &&...args) {
                std::lock_guard<std::mutex> lock{mutex_};
                auto dummy = {(func(std::get<Ids>(bars_), args...), 0)...};
                (void)dummy;
            }

            // Attributes
            std::tuple<Indicators &...> bars_;
            std::mutex mutex_;
            uint32_t last_updated_index;
    };

    //====================================================
    //     MultiProgressBar
    //====================================================
    /**
     * @brief Helper function used for deduction guides.
     *
     * @tparam Indicators The parameter pack of the various progress bar types.
     * @param inds The progress bars.
     * @return make_MultiProgressBar <typename std::remove_reference <Indicators>::type...> The update of the various
     * progress bars.
     */
    template <class... Indicators>
    make_MultiProgressBar<typename std::remove_reference<Indicators>::type...> MultiProgressBar(Indicators &&...inds) {
        return {std::forward<Indicators>(inds)...};
    }

    //====================================================
    //     type_identity
    //====================================================
    /**
     * @brief Struct used to to typedef the functor.
     *
     * @tparam T The type for which the type alias "type" will be created.
     */
    template <class T>
    struct type_identity {
            using type = T;
    };

    //====================================================
    //     updater
    //====================================================
    /**
     * @brief Functor used to call the ProgressBar class update method.
     *
     */
    struct updater {
            template <template <class> class PB, class bar_type>
            auto operator()(PB<bar_type> &pb, typename type_identity<bar_type>::type v) const
                -> decltype(pb.update(bar_type{})) {
                return pb.update(v);
            }
    };
}  // namespace osm

#endif