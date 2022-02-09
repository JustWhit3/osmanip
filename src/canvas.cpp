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
        char_buffer_.resize(width*height);
        feat_buffer_.resize(width*height);
        clear();    
    }
    void Canvas::clear(){
        char_buffer_.assign(width_*height_, ' ');
        feat_buffer_.assign(width_*height_, "");
    }
    void Canvas::put(uint x, uint y, char c, const std::string& feat){
        char_buffer_.at(y*width_+x) = c;
        feat_buffer_.at(y*width_+x) = feat;
    }
    void Canvas::refresh(){
        if(already_drawn_){
            for(uint i = 0; i < height_; i++){
                std::cout << feat(crs, "up", 1);
            }
        }
        std::stringstream ss;
        for(uint y = 0; y < height_; y++){
            for(uint x = 0; x < width_; x++){
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
}
