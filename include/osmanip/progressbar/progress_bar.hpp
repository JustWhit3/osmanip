//====================================================
//     File data
//====================================================
/**
 * @file progress_bar.hpp
 * @author Gianluca Bianco
 * (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_PROGRESSBAR_HPP
#define OSMANIP_PROGRESSBAR_HPP

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/manipulators/common.hpp>
#include <osmanip/manipulators/cursor.hpp>
#include <osmanip/utility/iostream.hpp>

// Extra headers
#include <arsenalgear/constants.hpp>
#include <arsenalgear/math.hpp>
#include <arsenalgear/operators.hpp>
#include <arsenalgear/utils.hpp>

// STD headers
#include <stdint.h>

#include <chrono>
#include <cmath>
#include <mutex>
#include <ratio>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace osm {

    //====================================================
    //     Aliases
    //====================================================
    using string_set_map = std::unordered_map<std::string, std::unordered_set<std::string>>;
    using steady_clock = std::chrono::steady_clock;
    using duration = std::chrono::duration<float, steady_clock::period>;

    //====================================================
    //     ProgressBar
    //====================================================
    /**
     * @brief Template class used to create
     * customized progress bars.
     *
     * @tparam bar_type It is the type of the
     * progress bar.
     */
    template <typename bar_type>
    class ProgressBar {
        public:

            //====================================================
            //     Constructors and destructors
            //====================================================

            // Default constructor
            /**
             * @brief Construct a new ProgressBar
             * <bar_type>::ProgressBar object.
             * Default constructor which set to
             * null values the main attributes.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            ProgressBar()
                : max_(0),
                  min_(0),
                  style_(""),
                  type_(""),
                  message_(""),
                  time_count_(duration::zero().count()),
                  brackets_open_(""),
                  brackets_close_(""),
                  begin_timer(steady_clock::now()),
                  color_(feat(rst, "color")),
                  color_name_(""),
                  ticks_occurred(0),
                  time_flag_("off") {}

            // Parametric constructor
            /**
             * @brief Construct a new ProgressBar
             * <bar_type>::ProgressBar object.
             * Parametric constructor which set to
             * null values the main attributes
             * except max_ and min which will be
             * initialized respectively with max
             * and min.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param min The minimum value of the
             * ProgressBar.
             * @param max The maximum value of the
             * ProgressBar.
             */
            explicit ProgressBar(const bar_type &min, const bar_type &max)
                : max_(max),
                  min_(min),
                  style_(""),
                  type_(""),
                  message_(""),
                  time_count_(duration::zero().count()),
                  brackets_open_(""),
                  brackets_close_(""),
                  begin_timer(steady_clock::now()),
                  color_(feat(rst, "color")),
                  color_name_(""),
                  ticks_occurred(0),
                  time_flag_("off") {}

            //====================================================
            //     Setters
            //====================================================

            // setMax
            /**
             * @brief Set the maximum value of the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param max The maximum value of the
             * ProgressBar.
             */
            void setMax(bar_type max) { max_ = max; }

            // setMin
            /**
             * @brief Set the minimum value of the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param min The minimum value of the
             * ProgressBar.
             */
            void setMin(bar_type min) { min_ = min; }

            // setStyle first overload
            /**
             * @brief Set the type and style of
             * the ProgressBar. Available:
             * "indicator" ("%", "/100"), "loader"
             * ("#", "■"), "spinner"
             * ("/-\\|").
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param type The type (flavor) of
             * the ProgressBar.
             * @param style The style of the
             * ProgressBar. Available:
             */
            void setStyle(const std::string &type, const std::string &style) {
                try {
                    if (styles_map_.at(type).find(style) != styles_map_.at(type).end()) {
                        style_ = style;
                        type_ = type;
                    } else if (styles_map_.at(type).find(style) == styles_map_.at(type).end()) {
                        throw agr::except_error_func(
                            "Inserted "
                            "ProgressBar "
                            "style",
                            style,
                            "is not "
                            "supported for "
                            "this type!");
                    } else {
                        throw agr::except_error_func(
                            "Inserted "
                            "ProgressBar "
                            "type",
                            type,
                            "is not "
                            "supported!");
                    }
                } catch (std::out_of_range const &exception) {
                    throw agr::except_error_func(
                        "Inserted ProgressBar "
                        "type",
                        type, "is not supported!");
                }
            }

            // setStyle second overload
            /**
             * @brief Set the style of the
             * complete ProgressBar. Available:
             * "indicator" ("%", "/100"), "loader"
             * ("#", "■"), "spinner"
             * ("/-\\|") and "complete" with both
             * indicator first and loader second.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param type The type (flavor) of
             * the ProgressBar.
             * @param style_p The style of the
             * percentage part of the progress
             * bar.
             * @param style_l The style of the bar
             * part of the progress bar.
             */
            void setStyle(const std::string &type, const std::string &style_p, const std::string &style_l) {
                if (styles_map_.at("indicator").find(style_p) != styles_map_.at("indicator").end() &&
                    styles_map_.at("loader").find(style_l) != styles_map_.at("loader").end() && type == "complete") {
                    style_ = style_p + style_l;
                    style_p_ = style_p;
                    style_l_ = style_l;
                    type_ = type;
                } else if (styles_map_.at("indicator").find(style_p) == styles_map_.at("indicator").end()) {
                    throw agr::except_error_func(
                        "Inserted indicator "
                        "style",
                        style_p,
                        "is not supported for "
                        "this type!");
                } else if (styles_map_.at("loader").find(style_l) == styles_map_.at("loader").end()) {
                    throw agr::except_error_func("Inserted loader style", style_l,
                                                 "is not supported for "
                                                 "this type!");
                } else {
                    throw agr::except_error_func(
                        "Inserted ProgressBar "
                        "type",
                        type, "is not supported!");
                }
            }

            // setMessage
            /**
             * @brief Set the message of the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param message The message of the
             * ProgressBar.
             */
            void setMessage(std::string_view message) { message_ = message; }

            // setBegin
            /**
             * @brief Set begin time count.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void setBegin() { begin = steady_clock::now(); }

            // setEnd
            /**
             * @brief Set end time count.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void setEnd() {
                end = steady_clock::now();
                time_count_ += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            }

            // setBrackets
            /**
             * @brief Set brackets of the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param brackets_open Open bracket.
             * @param brackets_close Close
             * bracket.
             */
            void setBrackets(std::string_view brackets_open, std::string_view brackets_close) {
                brackets_open_ = brackets_open, brackets_close_ = brackets_close;
            }

            // setColor
            /**
             * @brief Set the color of the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param color The color of the
             * ProgressBar.
             */
            void setColor(const std::string &color) {
                color_ = feat(col, color);
                color_name_ = color;
            }

            // setRemainingTimeFlag
            /**
             * @brief Set the remaining time of
             * the ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param time_flag The flag of the
             * remaining time.
             */
            void setRemainingTimeFlag(std::string_view time_flag) { time_flag_ = time_flag; }

            //====================================================
            //     Resetters
            //====================================================

            // resetAll
            /**
             * @brief Reset the ProgressBar
             * variables.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetAll() {
                max_ = static_cast<bar_type>(0), min_ = static_cast<bar_type>(0), style_ = "", type_ = "",
                message_ = "", time_count_ = 0, ticks_occurred = 0, begin_timer = steady_clock::now(),
                brackets_open_ = "", brackets_close_ = "", color_ = feat(rst, "color");
                color_name_ = "";
                time_flag_ = "off";
            }

            // resetMax
            /**
             * @brief Reset the ProgressBar Max
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetMax() { max_ = static_cast<bar_type>(0); }

            // resetMin
            /**
             * @brief Reset the ProgressBar Min
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetMin() { min_ = static_cast<bar_type>(0); }

            // resetStyle
            /**
             * @brief Reset the ProgressBar Style
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetStyle() {
                style_.clear();
                type_.clear();
            }

            // resetMessage
            /**
             * @brief Reset the ProgressBar
             * Message variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetMessage() { message_.clear(); }

            // resetTime
            /**
             * @brief Reset the ProgressBar time
             * count.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetTime() { time_count_ = duration::zero().count(); }

            // resetRemainingTime
            /**
             * @brief Reset the ProgressBar time
             * remaining count.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetRemainingTime() {
                ticks_occurred = 0;
                begin_timer = steady_clock::now();
            }

            // resetBrackets
            /**
             * @brief Reset the ProgressBar
             * brackets.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetBrackets() { brackets_open_.clear(), brackets_close_.clear(); }

            // resetColor
            /**
             * @brief Reset the ProgressBar color.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void resetColor() {
                color_ = feat(rst, "color");
                color_name_ = "";
            }

            //====================================================
            //     Getters
            //====================================================

            // getMax
            /**
             * @brief Get the ProgressBar Max
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar Max
             * variable.
             */
            bar_type getMax() const { return max_; }

            // getMin
            /**
             * @brief Get the ProgressBar Min
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar Min
             * variable.
             */
            bar_type getMin() const { return min_; }

            // getTime
            /**
             * @brief Get the ProgressBar current
             * time value.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar current
             * time value.
             */
            long long getTime() const { return time_count_; }

            // getIteratingVar
            /**
             * @brief Get the ProgressBar
             * iterating variable value.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar iterating
             * variable value.
             */
            bar_type getIteratingVar() const { return iterating_var_; }

            // getStyle
            /**
             * @brief Get the ProgressBar Style
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar Style
             * variable.
             */
            std::string getStyle() const { return style_; }

            // getStyleComplete
            /**
             * @brief Get the ProgressBar Style
             * variable for "complete" variable
             * type.
             *
             * @tparam bar_type The style of the
             * ProgressBar.
             * @return The ProgressBar Type
             * variable.
             */
            std::string getStyleComplete() const {
                if (type_ == "complete") {
                    return "Percentage: \"" + style_p_ + "\"\n" + "Loader: \"" + style_l_ + "\"\n";
                }
                return style_;
            }

            // getType
            /**
             * @brief Get the ProgressBar Type
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar Type
             * variable.
             */
            std::string getType() const { return type_; }

            // getMessage
            /**
             * @brief Get the ProgressBar Message
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar Message
             * variable.
             */
            std::string getMessage() const { return message_; }

            // getBrackets_open
            /**
             * @brief Get the ProgressBar
             * brackets_open variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar
             * brackets_open variable.
             */
            std::string getBrackets_open() const { return brackets_open_; }

            // getBrackets_close
            /**
             * @brief Get the ProgressBar
             * brackets_close variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar
             * brackets_close variable.
             */
            std::string getBrackets_close() const { return brackets_close_; }

            // getColor
            /**
             * @brief Get the ProgressBar color
             * variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar color
             * variable.
             */
            std::string getColor() const { return color_; }

            // getColorName
            /**
             * @brief Get the ProgressBar color
             * name variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar color name
             * variable.
             */
            std::string getColorName() const { return color_name_; }

            // getRemainingTimeFlag
            /**
             * @brief Get the ProgressBar time
             * remaining variable.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar time
             * remaining variable.
             */
            std::string getRemainingTimeFlag() const { return time_flag_; }

            //====================================================
            //     Other methods
            //====================================================

            // update
            /**
             * @brief Update the progress bar
             * indicator.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param value The value of the
             * progress bar indicator.
             */
            void update(bar_type iterating_var) {
                std::lock_guard<std::mutex> lock{mutex_};

                iterating_var_ = 100 * (iterating_var - min_) / (max_ - min_ - agr::one(iterating_var)),
                iterating_var_spin_ =
                    agr::isFloatingPoint(iterating_var) ? (agr::roundoff(iterating_var, 1) * 10) : iterating_var,
                width_ = (iterating_var_ + 1) / 4;

                // Update of the progress
                // indicator only:
                if (styles_map_.at("indicator").find(style_) != styles_map_.at("indicator").end()) {
                    output_ = feat(crs, "left", 100) + getColor() +
                              std::to_string(static_cast<int32_t>(round(iterating_var_++))) + feat(rst, "color") +
                              getStyle();

                    update_output(output_);
                }

                // Update of the loader indicator
                // only:
                else if (styles_map_.at("loader").find(style_) != styles_map_.at("loader").end()) {
                    output_ =
                        feat(crs, "left", 100) + getBrackets_open() + getColor() + getStyle() * width_ +
                        agr::empty_space<std::string> * ((agr::isFloatingPoint(iterating_var) ? 26 : 25) - width_) +
                        feat(rst, "color") + getBrackets_close();

                    update_output(output_);
                }

                // Update of the whole progress
                // bar:
                else if (style_.find(style_p_) != std::string::npos && style_.find(style_l_) != std::string::npos &&
                         type_ == "complete") {
                    output_ =
                        feat(crs, "left", 100) + getBrackets_open() + getColor() + style_l_ * width_ +
                        agr::empty_space<std::string> * ((agr::isFloatingPoint(iterating_var) ? 26 : 25) - width_) +
                        feat(rst, "color") + getBrackets_close() + getColor() + agr::empty_space<std::string> +
                        std::to_string(static_cast<int32_t>(round(iterating_var_++))) + feat(rst, "color") + style_p_;

                    update_output(output_);
                }

                // Update of the progress spinner:
                else if (styles_map_.at("spinner").find(style_) != styles_map_.at("spinner").end()) {
                    output_ = feat(crs, "left", 100) + getColor() +
                              getStyle()[static_cast<uint64_t>(iterating_var_spin_) & 3] + feat(col, "green") +
                              ((agr::roundoff(iterating_var, 1) == agr::roundoff(max_, 1) - agr::one(iterating_var))
                                   ? (static_cast<std::string>(feat(crs, "left", 100) + "0"))
                                   : "") +
                              feat(rst, "color");

                    update_output(output_);
                }

                else {
                    throw std::runtime_error(
                        "ProgressBar style has "
                        "not been set!");
                }
            }

            // print
            /**
             * @brief Prints on the screen the
             * progress bar variable values.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             */
            void print() const {
                osm::cout << "Max: " << max_ << "\n"
                          << "Min: " << min_ << "\n"
                          << "Time counter: " << time_count_ << "\n"
                          << "Style: " << style_ << "\n"
                          << "Type: " << type_ << "\n"
                          << "Message: " << message_ << "\n"
                          << "Brackets style: " << brackets_open_ << brackets_close_ << "\n"
                          << "Color: " << color_name_ << "\n"
                          << "Show remaining time: " << time_flag_ << "\n";
            }

            // addStyle
            /**
             * @brief Add customized styles to the
             * ProgressBar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param type The type of the
             * ProgressBar.
             * @param style The style of the
             * ProgressBar.
             */
            void addStyle(const std::string &type, const std::string &style) { styles_map_.at(type).insert(style); }

        private:

            //====================================================
            //     Private methods
            //====================================================

            // remaining_time
            /**
             * @brief Compute the remaining time
             * for the completion of the progress
             * bar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @return The ProgressBar remaining
             * time.
             */
            void remaining_time() {
                max_spin_ = agr::isFloatingPoint(max_) ? (agr::roundoff(max_ - min_, 1) * 10 + 1) : (max_ - min_ + 1);

                duration time_taken = steady_clock::now() - begin_timer;
                float percentage_done = static_cast<float>(ticks_occurred) / (max_spin_);
                duration time_left = time_taken * (1 / percentage_done - 1);
                std::chrono::minutes minutes_left = std::chrono::duration_cast<std::chrono::minutes>(time_left);
                std::chrono::seconds seconds_left =
                    std::chrono::duration_cast<std::chrono::seconds>(time_left - minutes_left);

                osm::cout << "["
                          << feat(sty, "italics") +
                                 "Estimated time "
                                 "left: " +
                                 feat(rst, "italics")
                          << feat(col, "green") << minutes_left.count() << feat(rst, "color") << "m "
                          << feat(col, "green") << seconds_left.count() << feat(rst, "color") << "s"
                          << "]" << feat(tcsc, "cln", 0);
            }

            // update_output
            /**
             * @brief Update the output of the
             * progress bar.
             *
             * @tparam bar_type The type of the
             * ProgressBar.
             * @param output The output of the
             * progress bar.
             */
            void update_output(std::string_view output) {
                osm::cout << output << getColor()
                          << ((message_ != agr::null_str<std::string>)
                                  ? (agr::empty_space<std::string> + message_ + agr::empty_space<std::string>)
                                  : agr::empty_space<std::string>)
                          << feat(rst, "color");

                if (time_flag_ == "on") {
                    ticks_occurred++;
                    remaining_time();
                }

                osm::cout << std::flush;
            }

            //====================================================
            //     Private static attributes
            //====================================================
            static string_set_map styles_map_;
            static std::vector<bar_type> counter_;
            static std::mutex mutex_;

            //====================================================
            //     Private attributes
            //====================================================
            long long time_count_;
            std::uint64_t ticks_occurred;
            bar_type max_, max_spin_, min_, iterating_var_, iterating_var_spin_, width_;
            std::string style_, style_p_, style_l_, type_, conct_, message_, brackets_open_, brackets_close_, output_,
                color_, time_flag_, color_name_;
            steady_clock::time_point begin, end, begin_timer;
    };

    //====================================================
    //     Operator << redefinition
    //====================================================
    /**
     * @brief Operator << used to print the
     * progress bar properties.
     *
     * @tparam bar_type It is the type of the
     * progress bar.
     * @param os It is the output stream used to
     * print the progress bar.
     * @param pb It is the progress bar object.
     * @return std::ostream& It is the output
     * stream with the given progress bar
     * properties printed out.
     */
    template <typename bar_type>
    std::ostream &operator<<(std::ostream &os, const ProgressBar<bar_type> &pb) {
        os << "Max: " << pb.getMax() << "\n"
           << "Min: " << pb.getMin() << "\n"
           << "Time counter: " << pb.getTime() << "\n"
           << "Style: " << pb.getStyle() << "\n"
           << "Type: " << pb.getType() << "\n"
           << "Message: " << pb.getMessage() << "\n"
           << "Brackets style: " << pb.getBrackets_open() << pb.getBrackets_close() << "\n"
           << "Color: " << pb.getColorName() << "\n"
           << "Show remaining time: " << pb.getRemainingTimeFlag() << "\n";

        return os;
    }

    //====================================================
    //     Static attributes declaration
    //====================================================
    template <typename bar_type>
    string_set_map ProgressBar<bar_type>::styles_map_{
        {"indicator", {"%", "/100"}},
        {"loader", {"#", "■"}},
        {"spinner", {"/-\\|"}},
    };

    template <typename bar_type>
    std::vector<bar_type> ProgressBar<bar_type>::counter_(2);

    template <typename bar_type>
    std::mutex ProgressBar<bar_type>::mutex_;
}  // namespace osm

#endif