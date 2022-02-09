#ifndef OSM_CANVAS_HPP
#define OSM_CANVAS_HPP

#include <functional>
#include <vector>
#include <cmath>
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
        std::vector<char> char_buffer_;
        std::vector<std::string> feat_buffer_;
        bool already_drawn_;
    protected:
        uint width_, height_;
    };
    class Plot2DCanvas: public Canvas{
    public:
        Plot2DCanvas(uint w, uint h);
        template <typename Y, typename X>
        void draw(std::function<Y(X)> function, char c, const std::string& feat=""){
            for(int x=0; x < width_; x++){
                float real_x = offset_x_ + x * scale_x_;
                Y real_y = function(real_x);
                uint y = std::round((real_y - offset_y_)/scale_y_);
                if(y >= 0 && y < height_){
                    put(x, y, c, feat);
                }
            }
        }
        void setOffset(float xOff, float yOff);
        void setScale(float xScale, float yScale);
    private:
        float offset_x_, offset_y_, scale_x_, scale_y_;
    };
}
      
#endif
