//====================================================
//     File data
//====================================================
/**
 * @file plot_2D.hpp
 * @author Miguel MJ (miguelmjvg@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_PLOT2DCANVAS
#define OSMANIP_PLOT2DCANVAS

//====================================================
//     Headers
//====================================================

//My headers
#include "../graphics/canvas.hpp"

//STD headers
#include <functional>
#include <cmath>
#include <string>
#include <stdint.h>

namespace osm
 {
  //====================================================
  //     Classes
  //====================================================

  // Plot2DCanvas
  /**
   * @brief This class is used to plot mathematical functions R -> R. In addition to all the properties of a basic Canvas, this one also has an offset and a scale for the plot. The offset is the first value in x and y to be represented in the canvas and the scale is the difference in x or y that each character represents relative to the previous one. For example: a canvas of size = (15, 10) with offset = (3,2) and scale = (7, 5) will represent the functions you draw from x=3 to x=3+15*7=108 and from y=2 to y=2+10*5=52.
   * 
   */
  class Plot2DCanvas: public Canvas
   {
    public:

     //====================================================
     //     Constructors
     //====================================================
     Plot2DCanvas( uint32_t w, uint32_t h ); 
      
     //====================================================
     //     Setters
     //====================================================
     void setOffset( float xOff, float yOff );
     void setScale( float xScale, float yScale );
     
     //====================================================
     //     Getters
     //====================================================
     float getOffsetX() const;
     float getOffsetY() const;
     float getScaleX() const;
     float getScaleY() const; 

     //====================================================
     //     Methods
     //====================================================

     // Draw
     /**
      * @brief Plot a function that receives an argument of a numeric type X and returns a numeric value of type Y. Represent it with a given char c and an optional feat.
      * 
      * @tparam Y Type-argument of the given function.
      * @tparam X Type-return of the given function.
      * @param function The input function.
      * @param c The char to represent a function.
      * @param feat The optional feature.
      */
     template <typename Y, typename X>
     inline void draw( std::function<Y( X )> function, char c, const std::string& feat = "" )
      {
       for( uint32_t x = 0; x < width_; x++ )
        {
         float real_x = offset_x_ + x * scale_x_;
         Y real_y = function( real_x );
         uint32_t y = std::round( ( real_y - offset_y_ ) / scale_y_ );
         if( y > 0 && y < height_ ) put( x, y, c, feat );
        }
      }

    private:

     //====================================================
     //     Private attributes
     //====================================================
     float offset_x_, offset_y_, scale_x_, scale_y_;
   };
 }

#endif