#ifndef OSM_CANVAS_HPP
#define OSM_CANVAS_HPP

#include <vector>
#include <string>

namespace osm
{
    typedef enum {
        EMPTY = 0,
        ASCII = 1,
        BOX = 2
    } FrameStyle;
    
    class Canvas{
    public:
        Canvas(uint width, uint height);
        
        void setBackground(char c, const std::string& feat="");
        
        void enableFrame(bool frame_enabled);
        void setFrame(FrameStyle, const std::string feat="");
        
        void clear();
        void put(uint x, uint y, char c, const std::string& feat="");
        void refresh();
    private:
        bool frame_enabled_;
        FrameStyle frame_style_;
        std::string frame_feat_;
        char bg_char_;
        std::string bg_feat_;
        uint width_, height_;
        std::vector<char> char_buffer_;
        std::vector<std::string> feat_buffer_;
        bool already_drawn_;
    };
}
      
#endif
