//====================================================
//     File data
//====================================================
/**
 * @file plot_2D.cpp
 * @author Miguel MJ (miguelmjvg@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/graphics/canvas.hpp>
#include <osmanip/graphics/plot_2D.hpp>

// STD headers
#include <stdint.h>

namespace osm {
    //====================================================
    //     Constructors
    //====================================================

    // Parametric constructor
    /**
     * @brief Construct a new Plot2D:: Plot2D object. The same as its parent,
     * the constructor requires the dimensions of the canvas.
     *
     * @param width Width of the canvas.
     * @param height Height of the canvas.
     */
    Plot2DCanvas::Plot2DCanvas(uint32_t w, uint32_t h) : Canvas(w, h) {
        offset_x_ = 0;
        offset_y_ = 0;
        scale_x_ = 1;
        scale_y_ = 1;
    }

    //====================================================
    //     Setters
    //====================================================

    // setOffset
    /**
     * @brief Set the offset_x and offset_y of the canvas.
     *
     * @param offset_x The offset_x of the canvas.
     * @param offset_y The offset_y of the canvas.
     */
    void Plot2DCanvas::setOffset(float xOff, float yOff) {
        offset_x_ = xOff;
        offset_y_ = yOff;
    }

    // setScale
    /**
     * @brief Set the scale_x and scale_y of the canvas.
     *
     * @param scale_x The scale_x of the canvas.
     * @param scale_y The scale_y of the canvas.
     */
    void Plot2DCanvas::setScale(float xScale, float yScale) {
        scale_x_ = xScale;
        scale_y_ = yScale;
    }

    //====================================================
    //     Getters
    //====================================================

    // getOffsetX
    /**
     * @brief Get the offset_x of the canvas.
     *
     * @return The offset_x of the canvas.
     */
    float Plot2DCanvas::getOffsetX() const { return offset_x_; }

    // getOffsetY
    /**
     * @brief Get the offset_y of the canvas.
     *
     * @return The offset_y of the canvas.
     */
    float Plot2DCanvas::getOffsetY() const { return offset_y_; }

    // getScaleX
    /**
     * @brief Get the scale_x of the canvas.
     *
     * @return The scale_x of the canvas.
     */
    float Plot2DCanvas::getScaleX() const { return scale_x_; }

    // getScaleY
    /**
     * @brief Get the scale_y of the canvas.
     *
     * @return The scale_y of the canvas.
     */
    float Plot2DCanvas::getScaleY() const { return scale_y_; }
}  // namespace osm