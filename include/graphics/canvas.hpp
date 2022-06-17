//====================================================
//     Preprocessor settings
//====================================================
#ifndef OSM_CANVAS_HPP
#define OSM_CANVAS_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <vector>
#include <string>

namespace osm
 {
  //====================================================
  //     FrameStyle
  //====================================================
  /** 
   * @brief Enum class used to define the frame style.
   */
  typedef enum 
   {
    EMPTY = 0,
    ASCII = 1,
    BOX = 2
   } FrameStyle;

  //====================================================
  //     Canvas
  //====================================================
  /**
   * @brief Instances of this class are used to draw in a limited 2D space. All the functions that modify the canvas do it internally; to make the changes effective in the console, you must use the refresh method.
   * 
   */
  class Canvas
   {
    public:

     //====================================================
     //     Constructors
     //====================================================
     Canvas( unsigned int width, unsigned int height );

     //====================================================
     //     Setters
     //====================================================
     void enableFrame( bool frame_enabled );
     void setFrame( FrameStyle, const std::string& feat = "" );
     void setBackground( char c, const std::string& feat = "" );
     void setWidth( unsigned int width );
     void setHeight( unsigned int height );

     //====================================================
     //     Getters
     //====================================================
     char getBackground() const;
     std::string getBackgroundFeat() const;
     bool isFrameEnabled() const;
     std::string getFrameFeat() const;
     FrameStyle getFrameStyle() const;
     unsigned int getWidth() const;
     unsigned int getHeight() const;

     //====================================================
     //     Other methods
     //====================================================
     void clear();
     void put( unsigned int x, unsigned int y, char c, const std::string& feat = "" );
     void refresh();

    private:

     //====================================================
     //     Private attributes
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
     //     Private methods
     //====================================================
     void resizeCanvas();

    protected:

     //====================================================
     //     Protected attributes
     //====================================================
     unsigned int width_, height_;
    };
 }

#endif
