//====================================================
//     File data
//====================================================
/**
 * @file generic.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2023-07-25
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_UTILITY_GENERIC
#define OSMANIP_UTILITY_GENERIC

//====================================================
//     Headers
//====================================================

// STD
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

namespace osm {

    //====================================================
    //     Constants
    //====================================================
    template <typename T>
    inline const T null_str = "";

    template <typename T>
    inline const T empty_space = " ";

    //====================================================
    //     Enum classes
    //====================================================
    enum class ANSI_SEARCH { first, generic };

    //====================================================
    //     Functions
    //====================================================
    extern std::vector<std::string> split_string(const std::string& input, const std::string& regex);
    extern std::string getCommandOut(const char* command);

    //====================================================
    //     except_error_func
    //====================================================
    /**
     * @brief Function used to throw customized stdexception error. This function is extremely specific to my purposes
     * and you can find examples usages in other my projects lik "osmanip" or "SAFD-algorithm".
     * @tparam T_err The type of the exception error.
     * @param beg The first part of the error message.
     * @param var The variable to be inserted in the error message.
     * @param end The last part of the error message.
     * @return T_err The modified exception error.
     */
    template <typename T_err = std::runtime_error>
    inline T_err except_error_func(const std::string& beg = "", std::string var = nullptr,
                                   const std::string& end = "") {
        using namespace std::literals::string_literals;

        static std::ostringstream oss;
        oss.str("");
        oss.clear();
        oss << "\033[31m" << beg << " \""s
            << "\033[1m" << var << "\033[22m"
            << "\" "s << end << "\033[39m";

        return T_err(oss.str());
    }

    //====================================================
    //     is_escape
    //====================================================
    /**
     * @brief This method is used to check if an input variable is an ANSI escape sequency or not.
     *
     * @tparam T Template type of the input variable.
     * @param str The input variable.
     * @param flag A flag which let to return different things with respect to its value. If flag = ANSI_SEARCH::first
     * the ANSI is searched as the first substring of the str argument, otherwise, if flag = ANSI_SEARCH::generic the
     * ANSI is searched as a substring inside the str argument.
     * @return true If the input variable is an ANSI escape sequency.
     * @return false Otherwise.
     */
    template <typename T>
    bool is_escape(const T& str, const ANSI_SEARCH& flag) {
        if constexpr (std::is_convertible_v<T, std::string_view> && !std::is_same_v<T, std::nullptr_t>) {
            switch (flag) {
                case (ANSI_SEARCH::first): {
                    return (std::string_view(str).length() < 7) && (str[0] == '\033');
                }
                case (ANSI_SEARCH::generic): {
                    return (std::string_view(str).find('\033') != std::string_view::npos);
                }
            }
        }
        return false;
    }

    //====================================================
    //     roundoff
    //====================================================
    /**
     * @brief Function to round a floating point to n-th decimal place after comma.
     *
     * @tparam T The Type of the variable to be rounded.
     * @param value The variable to be rounded
     * @param prec Precision of the rounding.
     * @return T The rounded variable.
     */
    template <typename T>
    inline T roundoff(T value, unsigned char prec) {
        T pow_10 = std::pow(10.0f, static_cast<T>(prec));

        return round(value * pow_10) / pow_10;
    }

    //====================================================
    //     isFloatingPoint
    //====================================================
    /**
     * @brief Function to check if an expression (not a type) is a floating point or not. I know this function is almost
     * useless, but it has been created for lazy purposes and since it is used in other projects it cannot be eliminated
     * now in order to not break backward compatibility.
     * @tparam T The type of the expression.
     * @return bool True if the expression is a floating point, false otherwise.
     */
    template <typename T>
    inline bool isFloatingPoint(const T&) {
        return std::is_floating_point<T>::value;
    }

    //====================================================
    //     one
    //====================================================
    /**
     * @brief Function to find the incremented unit of a loop. Not easy to understand its purpose without context, but
     * it is used to get the loop incremented unit in case of loops with floating-point indexes. See example usage in
     * progress bars "update" method.
     * @tparam T The type of the iterating variable of the loop.
     * @param iterating_var The iterating variable of the loop.
     * @return T The incremented unit of the loop.
     */
    template <typename T>
    inline T one(const T& iterating_var) {
        std::vector<T> counter_;

        if (isFloatingPoint(iterating_var)) {
            if (counter_.size() < 2) counter_.push_back(iterating_var);
            if (counter_.size() == 2) return abs(abs(counter_.front()) - abs(counter_.back()));
            return static_cast<T>(0);
        }

        counter_.clear();
        return 1;
    }
}  // namespace osm

//====================================================
//     std::string * int
//====================================================
/**
 * @brief Function to multiply a string by an integer.
 *
 * @param generic_string The string to be multiplied.
 * @param integer The integer to be multiplied.
 * @return std::string The multiplied string.
 */
inline std::string operator*(const std::string& generic_string, unsigned int integer) {
    std::string output;
    output.reserve(integer * generic_string.size());

    while (integer--) {
        output += generic_string;
    }

    return output;
}

#endif