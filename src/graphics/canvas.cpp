//====================================================
//     File data
//====================================================
/**
 * @file canvas.cpp
 * @author Miguel MJ (miguelmjvg@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

//My headers
#include "../../include/graphics/canvas.hpp"
#include "../../include/manipulators/cursor.hpp"
#include "../../include/manipulators/colsty.hpp"
#include "../../include/manipulators/common.hpp"

//STD headers
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <ext/alloc_traits.h>

namespace osm
 {
  //====================================================
  //     Constructors
  //====================================================

  // Parametric constructor
  /**
   * @brief Construct a new Canvas:: Canvas object. The size of the canvas in characters must be specified upon construction.
   * 
   * @param width Width of the canvas.
   * @param height Height of the canvas.
   */
  Canvas::Canvas( unsigned int width, unsigned int height ): already_drawn_( false ), width_( width ), height_( height ), bg_char_( ' ' ), bg_feat_( "" ), frame_enabled_( false )
   {
    resizeCanvas();
    clear();
   }

  //====================================================
  //     Setters
  //====================================================

  // setBackground
  /**
   * @brief Set the char that fills the background and an optional feat.
   * 
   * @param c The char that fills the background.
   * @param feat The optional feat.
   */
  void Canvas::setBackground( char c, const std::string & feat )
   {
    bg_char_ = c;
    bg_feat_ = feat;
   }

  //====================================================
  //     Setters
  //====================================================

  // setFrame
  /**
   * @brief Set the FrameStyle of the canvas and an optional feat.
   * 
   * @param fs The FrameStyle of the canvas.
   * @param feat The optional feature.
   */
  void Canvas::setFrame( FrameStyle fs, const std::string & feat )
   {
    frame_style_ = fs;
    frame_feat_ = feat;
   }

  // setWidth
  /**
   * @brief Set the width of the canvas.
   * 
   * @param width The canvas width to set.
   */
  void Canvas::setWidth( unsigned int width )
   {
    width_ = width;
    resizeCanvas();
   }

  // setHeight
  /**
   * @brief Set the height of the canvas.
   * 
   * @param height The canvas height to set.
   */
  void Canvas::setHeight( unsigned int height )
   {
    height_ = height;
    resizeCanvas();
   }

  //====================================================
  //     Getters
  //====================================================

  // getWidth
  /**
   * @brief Get the width of the canvas.
   * 
   * @return unsigned int The width of the canvas.
   */
  unsigned int Canvas::getWidth() const
   {
    return width_;
   }

  // getHeight
  /**
   * @brief Get the height of the canvas.
   * 
   * @return unsigned int The height of the canvas.
   */
  unsigned int Canvas::getHeight() const
   {
    return height_;
   }

  // getBackground
  /**
   * @brief Get the char that fills the background.
   * 
   * @return char The char that fills the background.
   */
  char Canvas::getBackground() const
   {
    return bg_char_;
   }

  // getBackgroundFeat
  /** 
   * @brief Get the optional feat of the background.
   * 
   * @return const std::string& The optional feat of the background.
   */
  std::string Canvas::getBackgroundFeat() const
   {
    return bg_feat_;
   }

  // getFrameFeat
  /**
   * @brief Get the frame feature (if set).
   * 
   * @return std::string The frame feature.
   */
  std::string Canvas::getFrameFeat() const
   {
    return frame_feat_;
   }

  // getFrameStyle
  /**
   * @brief Get the frame style.
   * 
   * @return FrameStyle The frame style.
   */
  FrameStyle Canvas::getFrameStyle() const
   {
    return frame_style_;
   }

  //====================================================
  //     Methods
  //====================================================

  // enableFrame
  /**
   * @brief Flag to frame or not the canvas. The frame doesn't increase the size taken by the canvas. Instead, reduces the 2D space to draw in two columns and two rows (used to print the frame itself).
   * 
   * @param frame_enabled Set to True to enable the frame. Otherwise set to False.
   */
  void Canvas::enableFrame( bool frame_enabled )
   {
    frame_enabled_ = frame_enabled;
   }
  
  // isFrameEnabled
  /**
   * @brief Return True if the frame is enabled. Otherwise return False.
   * 
   * @return bool The frame enabled flag.
   */
  bool Canvas::isFrameEnabled() const
   {
    return frame_enabled_;
   }

  // clear
  /**
   * @brief Fill the canvas with the background.
   */
  void Canvas::clear()
   {
    char_buffer_.assign( static_cast<long> ( width_ ) * height_, bg_char_ );
    feat_buffer_.assign( static_cast<long> ( width_ ) * height_, bg_feat_ );
   }

  // put
  /** 
   * @brief Put a character in the canvas, given its coordinates and an optional feat. An out-of-bounds exception will be thrown if the coordinates are outside the canvas.
   * 
   * @param c The char to put.
   * @param x The x position.
   * @param y The y position.
   * @param feat The optional feature.
   */
  void Canvas::put( unsigned int x, unsigned int y, char c, const std::string & feat )
   {
    char_buffer_.at( y * width_ + x ) = c;
    feat_buffer_.at( y * width_ + x ) = feat;
   }

  // refresh
  /** 
   * @brief Display the canvas in the console.
   */
  void Canvas::refresh()
   {
    static const std::vector<std::vector<std::string>> frames = 
     {
      //   TL,  T,   TR,  L,   R,   BL,  B,   BR
      { " ", " ", " ", " ", " ", " ", " ", " " },
      { "+", "-", "+", "|", "|", "+", "-", "+" },
      { "\u250c", "\u2500", "\u2510", "\u2502", "\u2502", "\u2514", "\u2500", "\u2518" }
     };

    if( already_drawn_ )
     {
      for( unsigned int i = 0; i < height_; i++ )
      {
        std::cout << feat( crs, "up", 1 );
      }
     }

    unsigned int y = 0;

    const auto& frame = [ & ]( unsigned int fi ) -> std::string 
     {
      return frame_feat_ + frames[ frame_style_ ][ fi ] + feat( rst, "all" );
     };

    std::stringstream ss;

    if( frame_enabled_ )
     {
      ss << frame( 0 );

      for( unsigned int i = 2; i < width_; i++ )
       {
        ss << frame( 1 );
       }

      ss << frame( 2 ) << std::endl;
      y++;
     }

    for( ; y < height_; y++ )
     {
      if( y == height_ - 1 && frame_enabled_ )
      {
        ss << frame( 5 );

        for( unsigned int i = 2; i < width_; i++ )
         {
          ss << frame( 6 );
         }

        ss << frame( 7 ) << std::endl;
        continue;
      }

      for( unsigned int x = 0; x < width_; x++ )
       {
        if( x == 0 && frame_enabled_ )
         {
          ss << frame( 3 );
          continue;
         }

        if( x == width_ - 1 && frame_enabled_ )
         {
          ss << frame( 4 );
          continue;
         }

        unsigned int p = y * width_ + x;

        ss << feat_buffer_[ p ]
           << char_buffer_[ p ]
           << feat( rst, "all" );
       }
      ss << std::endl;
     }
    std::cout << ss.str();
    already_drawn_ = true;
   }

  // resizeCanvas
  /** 
   * @brief Resize the canvas.
   */
  void Canvas::resizeCanvas()
   {
    char_buffer_.resize( static_cast<long> ( width_ ) * height_ );
    feat_buffer_.resize( static_cast<long> ( width_ ) * height_ );
   }
 }