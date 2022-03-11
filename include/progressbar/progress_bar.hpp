#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

//STD headers
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <vector>
#include <mutex>
#include <cstdint>

namespace osm
 {
  //====================================================
  //     PROGRESSBAR CLASS
  //====================================================
  template <typename bar_type>
  class ProgressBar
   {
    public:

    //====================================================
    //     USING ALIASES
    //====================================================
    using steady_clock = std::chrono::steady_clock;
    using duration = std::chrono::duration <float, steady_clock::period>;
    using string_set_map = std::map <std::string, std::set <std::string> >;

    //====================================================
    //     CONSTRUCTORS AND DESTRUCTOR DECLARATION
    //====================================================
     ProgressBar();
     ~ProgressBar();

    //====================================================
    //     SETTERS DECLARATION
    //====================================================
     void setMax( const bar_type& max );
     void setMin( const bar_type& min );
     void setStyle( const std::string& type, const std::string& style );
     void setStyle( const std::string& type, const std::string& style_p, const std::string& style_l );
     void setMessage( const std::string& message );
     void setBrackets( const std::string& brackets_open, const std::string& brackets_close );
     void setBegin();
     void setEnd();
     void setColor( const std::string& color );
     void setRemainingTimeFlag( const std::string& time_flag );

    //====================================================
    //     RESETTERS DECLARATION
    //====================================================
     void resetAll();
     void resetMax();
     void resetMin();
     void resetStyle();
     void resetMessage();
     void resetTime();
     void resetRemainingTime();
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
     std::string getStyleComplete() const;
     std::string getMessage() const;
     std::string getBrackets_open() const;
     std::string getBrackets_close() const;
     std::string getColor() const;
     std::string getType() const;
     std::string getRemainingTimeFlag() const;

    //====================================================
    //     OTHER METHODS DECLARATION
    //====================================================
     void update( const bar_type& iterating_var );
     void update_output( const std::string& output );
     void print() const;
     void addStyle( const std::string& type, const std::string& style );
     void remaining_time();
  
    private:

    //====================================================
    //     STATIC ATTRIBUTES DECLARATION
    //====================================================
     static string_set_map styles_map_;
     static std::vector <bar_type> counter_;
     static std::mutex mutex_;
     
    //====================================================
    //     NON-STATIC ATTRIBUTES DECLARATION
    //====================================================
     long long time_count_;
     std::uint64_t ticks_occurred;
     bar_type max_, max_spin_, min_, iterating_var_, iterating_var_spin_, width_;
     std::string style_, style_p_, style_l_, type_, conct_, message_, brackets_open_, brackets_close_, 
                 output_, color_, time_flag_;
     steady_clock::time_point begin, end, begin_timer;
   };
 }
      
#endif