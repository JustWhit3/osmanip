#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <string>
#include <chrono>
#include <set>
#include <map>
#include <vector>

namespace osm
 {
  //====================================================
  //     TYPE ALIASES DECLARATION
  //====================================================
  using string_set_map = std::map <std::string, std::set<std::string>>;
  using time_type = std::chrono::steady_clock;

  template <typename bar_type>
  class ProgressBar
   {
    public:

    //====================================================
    //     CONSTRUCTORS AND DESTRUCTOR DECLARATION
    //====================================================
     ProgressBar();
     ~ProgressBar();

    //====================================================
    //     SETTERS DECLARATION
    //====================================================
     void setMax( bar_type max );
     void setMin( bar_type min );
     void setStyle( std::string type, std::string style );
     void setStyle( std::string type, std::string style_p, std::string style_l );
     void setMessage( std::string message );
     void setBrackets( std::string brackets_open, std::string brackets_close );
     void setBegin();
     void setEnd();
     void setColor( std::string color );

    //====================================================
    //     RESETTERS DECLARATION
    //====================================================
     void resetAll();
     void resetMax();
     void resetMin();
     void resetStyle();
     void resetMessage();
     void resetTime();
     void resetBrackets();
     void resetColor();

    //====================================================
    //     GETTERS DECLARATION
    //====================================================
     long long getTime() const;
     bar_type getMax() const;
     bar_type getMin() const;
     bar_type getIteratingVar() const;
     std::string getStyle() const;
     std::string getMessage() const;
     std::string getBrackets_open() const;
     std::string getBrackets_close() const;
     std::string getColor() const;
     std::string getType() const;

    //====================================================
    //     OTHER METHODS DECLARATION
    //====================================================
     void update( bar_type iterating_var );
     void print() const;
     void addStyle( std::string type, std::string style );
     bar_type one( bar_type iterating_var );
  
    private:

    //====================================================
    //     STATIC ATTRIBUTES DECLARATION
    //====================================================
     static string_set_map styles_map_;
     static std::string null_str,
                        empty_space;
     static std::vector <bar_type> counter_;
     
    //====================================================
    //     NON-STATIC ATTRIBUTES DECLARATION
    //====================================================
     long long time_count_;
     bar_type max_, 
              min_, 
              iterating_var_, 
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
     time_type::time_point begin, 
                           end;
   };
 }
      
#endif