#include "../include/canvas.hpp"
#include "../include/csmanip.hpp"

#include <sstream>
#include <iostream>

namespace osm
{
    Canvas::Canvas(uint width, uint height){
        already_drawn_ = false;
        width_ = width;
        height_ = height;
        bg_char_ = ' ';
        bg_feat_ = "";
        frame_enabled_ = false;
        char_buffer_.resize(width*height);
        feat_buffer_.resize(width*height);
        clear();    
    }
    void Canvas::setBackground(char c, const std::string& feat){
        bg_char_ = c;
        bg_feat_ = feat;
    }
    void Canvas::enableFrame(bool frame_enabled){
        frame_enabled_ = frame_enabled;
    }
    void Canvas::setFrame(FrameStyle fs, const std::string feat){
        frame_style_ = fs;
        frame_feat_ = feat;
    }
    void Canvas::clear(){
        char_buffer_.assign(width_*height_, bg_char_);
        feat_buffer_.assign(width_*height_, bg_feat_);
    }
    void Canvas::put(uint x, uint y, char c, const std::string& feat){
        char_buffer_.at(y*width_+x) = c;
        feat_buffer_.at(y*width_+x) = feat;
    }
    void Canvas::refresh(){
        static const std::vector<std::vector<std::string>> frames = {
        //   TL,  T,   TR,  L,   R,   BL,  B,   BR
            {" ", " ", " ", " ", " ", " ", " ", " "},
            {"+", "-", "+", "|", "|", "+", "-", "+"},
            {"\u250c", "\u2500", "\u2510", "\u2502", "\u2502", "\u2514", "\u2500", "\u2518"}
        };
        
        if(already_drawn_){
            for(uint i = 0; i < height_; i++){
                std::cout << feat(crs, "up", 1);
            }
        }
        uint y = 0;
        uint x = 0;
        const auto& frame = [&](uint fi) -> std::string {
            return frame_feat_ 
                + frames[frame_style_][fi] 
                + feat(rst,"all");
            };
        std::stringstream ss;
        if(frame_enabled_){
            ss << frame(0);
            for(uint i = 2; i < width_; i++){
                ss << frame(1);
            }
            ss << frame(2) << std::endl;
            y++;
        }
        for(; y < height_; y++){
            if(y == height_-1 && frame_enabled_){
                ss << frame(5);
                for(uint i = 2; i < width_; i++){
                    ss << frame(6);
                }
                ss << frame(7) << std::endl;
                continue;
            }
            for(uint x = 0; x < width_; x++){
                if(x == 0 && frame_enabled_){
                    ss << frame(3);
                    continue;
                }
                if(x == width_-1 && frame_enabled_){
                    ss << frame(4);
                    continue;
                }
                uint p = y*width_+x;
                ss << feat_buffer_[p]
                   << char_buffer_[p]
                   << feat(rst, "all");
            }
            ss << std::endl;
        }
        std::cout << ss.str();
        already_drawn_ = true;
    }
    Plot2DCanvas::Plot2DCanvas(uint w, uint h): Canvas(w, h){
        offset_x_ = 0;
        offset_y_ = 0;
        scale_x_ = 1;
        scale_y_ = 1;
    }
    void Plot2DCanvas::setOffset(float xOff, float yOff){
        offset_x_ = xOff;
        offset_y_ = yOff;
    }
    void Plot2DCanvas::setScale(float xScale, float yScale){
        scale_x_ = xScale;
        scale_y_ = yScale;
    }
}

