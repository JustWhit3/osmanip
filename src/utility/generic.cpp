//====================================================
//     File data
//====================================================
/**
 * @file utils.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2023-07-25
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/generic.hpp>

// STD
#include <array>
#include <cstdio>
#include <map>
#include <memory>
#include <regex>
#include <string>
#include <vector>

namespace osm {

    //====================================================
    //     split_string
    //====================================================
    /**
     * @brief Function used to split a string based on a certain reges.
     *
     * @param input The input string.
     * @param regex The regex.
     * @return std::vector<std::string> The collection of string elements splitted by the regex.
     */
    std::vector<std::string> split_string(const std::string& input, const std::string& regex) {
        std::regex re(regex);
        std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
        return {first, last};
    }

    //====================================================
    //     getCommandOut
    //====================================================
    /**
     * @brief Function used to get the output of a shell command.
     *
     * @param command The command which output is required.
     * @return std::string The output of the command variable.
     */
    std::string getCommandOut(const char* command) {
        std::array<char, 128> buffer;
        std::string result;
#ifdef _WIN32
        std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command, "r"), _pclose);
#else
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);
#endif

        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }

        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }

        return result;
    }
}  // namespace osm