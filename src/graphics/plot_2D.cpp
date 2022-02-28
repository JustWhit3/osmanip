//My headers
#include "../include/graphics/plot_2D.hpp"

namespace osm
 {
  //====================================================
  //     CONSTRUCTORS AND DESTRUCTORS DEFINITION
  //====================================================
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
  void Plot2DCanvas::setOffset( float xOff, float yOff )
   {
    offset_x_ = xOff;
    offset_y_ = yOff;
   }

  void Plot2DCanvas::setScale( float xScale, float yScale )
   {
    scale_x_ = xScale;
    scale_y_ = yScale;
   }

  //====================================================
  //     GETTERS DEFINITION
  //====================================================
  float Plot2DCanvas::getOffsetX() const
   {
    return offset_x_;
   }

  float Plot2DCanvas::getOffsetY() const
   {
    return offset_y_;
   }

  float Plot2DCanvas::getScaleX() const
   {
    return scale_x_;
   }

  float Plot2DCanvas::getScaleY() const
   {
    return scale_y_;
   }
 }