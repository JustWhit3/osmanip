//My headers
#include "../include/graphics/plot_2D.hpp"

namespace osm
 {
  //====================================================
  //     CONSTRUCTORS AND DESTRUCTORS DEFINITION
  //====================================================
  /**
   * @brief Construct a new Plot2D:: Plot2D object. The same as its parent, the constructor requires the dimensions of the canvas.
   * 
   * @param width Width of the canvas.
   * @param height Height of the canvas.
   */
  Plot2DCanvas::Plot2DCanvas( uint w, uint h ):
   Canvas( w, h )
    {
     offset_x_ = 0;
     offset_y_ = 0;
     scale_x_ = 1;
     scale_y_ = 1;
    }

  //====================================================
  //     SETTERS DEFINITION
  //====================================================
  /**
   * @brief Set the offset_x and offset_y of the canvas.
   * 
   * @param offset_x The offset_x of the canvas.
   * @param offset_y The offset_y of the canvas.
   */
  void Plot2DCanvas::setOffset( float xOff, float yOff )
   {
    offset_x_ = xOff;
    offset_y_ = yOff;
   }

  /** 
   * @brief Set the scale_x and scale_y of the canvas.
   * 
   * @param scale_x The scale_x of the canvas.
   * @param scale_y The scale_y of the canvas.
   */
  void Plot2DCanvas::setScale( float xScale, float yScale )
   {
    scale_x_ = xScale;
    scale_y_ = yScale;
   }

  //====================================================
  //     GETTERS DEFINITION
  //====================================================
  /**
   * @brief Get the offset_x of the canvas.
   * 
   * @return The offset_x of the canvas.
   */
  float Plot2DCanvas::getOffsetX() const
   {
    return offset_x_;
   }

  /** 
   * @brief Get the offset_y of the canvas.
   * 
   * @return The offset_y of the canvas.
   */
  float Plot2DCanvas::getOffsetY() const
   {
    return offset_y_;
   }

  /** 
   * @brief Get the scale_x of the canvas.
   * 
   * @return The scale_x of the canvas.
   */
  float Plot2DCanvas::getScaleX() const
   {
    return scale_x_;
   }

  /** 
   * @brief Get the scale_y of the canvas.
   * 
   * @return The scale_y of the canvas.
   */
  float Plot2DCanvas::getScaleY() const
   {
    return scale_y_;
   }
 }