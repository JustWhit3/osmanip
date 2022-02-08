#ifndef OSM_CANVAS_HPP
#define OSM_CANVAS_HPP

#include <vector>
#include <string>

namespace osm
{
    class Canvas{
    public:
        Canvas(uint width, uint height);
        
        void clear();
        void put(uint x, uint y, char c, const std::string& feat="");
        void refresh();
    private:
        uint width_, height_;
        std::vector<char> char_buffer_;
        std::vector<std::string> feat_buffer_;
        bool already_drawn_;
    };
}
      
#endif
