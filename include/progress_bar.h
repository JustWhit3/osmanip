#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <string>
#include <chrono>
#include <set>
#include <map>

namespace osm
 {
  //Type aliases declaration:
  using string_set_map = std::map <std::string, std::set<std::string>>;

  //ProgressBar class declaration:
  class ProgressBar
   {
    public:

     //Constructors and destructors declaration:
     ProgressBar();
     ~ProgressBar();

     //Setters declaration:
     void setMax( long long max );
     void setMin( long long min );
     void setStyle( std::string type, std::string style );
     void setStyle( std::string type, std::string style_p, std::string style_l );
     void setMessage( std::string message );
     void setBrackets( std::string brackets_open, std::string brackets_close );
     void setBegin();
     void setEnd();
     void setColor( std::string color );

     //Resetters declaration:
     void resetAll();
     void resetMax();
     void resetMin();
     void resetStyle();
     void resetMessage();
     void resetTime();
     void resetBrackets();
     void resetColor();

     //Getters declaration:
     long long getMax() const;
     long long getMin() const;
     long long getTime() const;
     long long getIteratingVar() const;
     std::string getStyle() const;
     std::string getMessage() const;
     std::string getBrackets_open() const;
     std::string getBrackets_close() const;
     std::string getColor() const;
     std::string getType() const;

     //Other methods declaration:
     void update( long long iterating_var );
     void print() const;
     void addStyle( std::string type, std::string style );
  
    private:

     //Static attributes declaration:
     static string_set_map styles_map_;
     
     //Dynamic attributes declaration:
     long long max_, 
               min_, 
               iterating_var_, 
               time_count_, 
               width_;
     std::string style_, 
                 style_p_,
                 style_l_,
                 type_,
                 conct_, 
                 message_, 
                 brackets_open_, 
                 brackets_close_, 
                 output_, 
                 color_;
     std::chrono::steady_clock::time_point begin, 
                                           end;
   };
 }
      
#endif