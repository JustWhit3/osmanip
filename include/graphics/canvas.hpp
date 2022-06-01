#ifndef OSM_CANVAS_HPP
#define OSM_CANVAS_HPP

//STD headers
#include <vector>
#include <string>

namespace osm
 {
  //====================================================
  //     FRAMESTYLE ENUM CLASS
  //====================================================
  typedef enum 
   {
    EMPTY = 0,
    ASCII = 1,
    BOX = 2
   } FrameStyle;

  //====================================================
  //     CANVAS CLASS
  //====================================================
  /**
   * @brief Instances of this class are used to draw in a limited 2D space. All the functions that modify the canvas do it internally; to make the changes effective in the console, you must use the refresh method.
   * 
   */
  class Canvas
   {
    public:

     //====================================================
     //     CONSTRUCTORS AND DESTRUCTORS DECLARATION
     //====================================================
     Canvas( uint width, uint height );

     //====================================================
     //     SETTERS DECLARATION
     //====================================================
     void enableFrame( bool frame_enabled );
     void setFrame( FrameStyle, const std::string& feat = "" );
     void setBackground( char c, const std::string& feat = "" );
     void setWidth( uint width );
     void setHeight( uint height );

     //====================================================
     //     GETTERS DECLARATION
     //====================================================
     char getBackground() const;
     std::string getBackgroundFeat() const;
     bool isFrameEnabled() const;
     std::string getFrameFeat() const;
     FrameStyle getFrameStyle() const;
     uint getWidth() const;
     uint getHeight() const;

     //====================================================
     //     OTHER METHODS DECLARATION
     //====================================================
     void clear();
     void put( uint x, uint y, char c, const std::string& feat = "" );
     void refresh();

    private:

     //====================================================
     //     PRIVATE ATTRIBUTES DECLARATION
     //====================================================
     bool frame_enabled_;
     FrameStyle frame_style_;
     std::string frame_feat_;
     char bg_char_;
     std::string bg_feat_;
     std::vector<char> char_buffer_;
     std::vector<std::string> feat_buffer_;
     bool already_drawn_;

     //====================================================
     //     PRIVATE METHODS DECLARATION
     //====================================================
     void resizeCanvas();

    protected:

     //====================================================
     //     PROTECTED ATTRIBUTES DECLARATION
     //====================================================
     uint width_, height_;
    };
 }

#endif
