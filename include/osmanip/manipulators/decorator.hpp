//====================================================
//     File data
//====================================================
/**
 * @file decorator.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_DECORATOR_HPP
#define OSMANIP_DECORATOR_HPP

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/manipulators/common.hpp>
#include <osmanip/utility/iostream.hpp>

// Extra headers
#include <arsenalgear/utils.hpp>

// STD headers
#include <string>
#include <unordered_map>
#include <vector>

namespace osm {
    
    //====================================================
    //     Classes
    //====================================================

    // Decorator
    /**
     * @brief Class used to decorate an output stream. Each setting is set
     * permanently on the chosen output stream until the destructor is met or
     * one of the reset functions is called.
     *
     */
    class Decorator {
       public:
        //====================================================
        //     Constructors and destructors
        //====================================================
        Decorator();
        ~Decorator();

        //====================================================
        //     Setters
        //====================================================
        void setColor(const std::string& color, std::ostream& os = osm::cout);
        void setStyle(const std::string& style, std::ostream& os = osm::cout);

        //====================================================
        //     Resetters
        //====================================================
        void resetColor(std::ostream& os = osm::cout);
        void resetStyle(std::ostream& os = osm::cout);
        void removeStyle(const std::string& style,
                         std::ostream& os = osm::cout);
        void resetFeatures(std::ostream& os = osm::cout);

        //====================================================
        //     Getters
        //====================================================
        std::string getColor(std::ostream& os = osm::cout);
        std::string getStyle(std::ostream& os = osm::cout);
        std::unordered_map<std::ostream*, std::string> getColorList();
        std::unordered_map<std::ostream*, std::string> getStyleList();
        std::ostream& getCurrentStream();

        //====================================================
        //     Operators
        //====================================================
        const Decorator& operator()(std::ostream& os = osm::cout);

       private:
        //====================================================
        //     Attributes
        //====================================================
        std::unordered_map<std::ostream*, std::string> colors, styles;
        std::ostream* current_stream;
    };

    //====================================================
    //     Operator <<
    //====================================================
    /**
     * @brief Operator overload to output a modified ostream object which
     * properties are set thanks to the Decorator class.
     *
     * @tparam T The template parameter of the object sent into the output
     * stream.
     * @param my_shell The Decorator object.
     * @param elem The element sent into the output stream.
     * @return std::ostream& The modified output stream.
     */
    template <typename T>
    std::ostream& operator<<(Decorator my_shell, const T& elem) {
        if (my_shell.getColor(my_shell.getCurrentStream()) != "") {
            my_shell.getCurrentStream()
                << feat(col, my_shell.getColor(my_shell.getCurrentStream()));
        }
        if (my_shell.getStyle(my_shell.getCurrentStream()) != "") {
            std::vector<std::string> list_of_styles {agr::split_string(
                my_shell.getStyle(my_shell.getCurrentStream()), " ")};
            for (auto elem : list_of_styles) {
                my_shell.getCurrentStream() << feat(sty, elem);
            }
        }
        my_shell.getCurrentStream() << elem << feat(rst, "all");

        return my_shell.getCurrentStream();
    }
}  // namespace osm

#endif