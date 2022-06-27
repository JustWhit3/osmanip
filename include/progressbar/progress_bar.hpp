//====================================================
//     Preprocessor settings
//====================================================
#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <iostream>
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
  //     Aliases
  //====================================================
  using string_set_map = std::map <std::string, std::set <std::string> >;
  using steady_clock = std::chrono::steady_clock;
  using duration = std::chrono::duration <float, steady_clock::period>;

  //====================================================
  //     ProgressBar class
  //====================================================
  /**
   * @brief Template class used to create customized progress bars.
   * 
   * @tparam bar_type It is the type of the progress bar.
   */
  template <typename bar_type>
  class ProgressBar
   {
    public:

    //====================================================
    //     Constructors and destructors
    //====================================================
     ProgressBar();
     ProgressBar( const bar_type& min, const bar_type& max );
     ~ProgressBar();

    //====================================================
    //     Setters
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
    //     Resetters
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
    //     Getters
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
     std::string getColorName() const;
     std::string getType() const;
     std::string getRemainingTimeFlag() const;

    //====================================================
    //     Other methods
    //====================================================
     void update( const bar_type& iterating_var );
     void print() const;
     void addStyle( const std::string& type, const std::string& style );
  
    private:

    //====================================================
    //     Private methods
    //====================================================
     void update_output( const std::string& output );
     void remaining_time();

    //====================================================
    //     Static attributes
    //====================================================
     static string_set_map styles_map_;
     static std::vector <bar_type> counter_;
     static std::mutex mutex_;
     
    //====================================================
    //     Non-static attributes
    //====================================================
     long long time_count_;
     std::uint64_t ticks_occurred;
     bar_type max_, max_spin_, min_, iterating_var_, iterating_var_spin_, width_;
     std::string style_, style_p_, style_l_, type_, conct_, message_, brackets_open_, brackets_close_, 
                 output_, color_, time_flag_, color_name_;
     steady_clock::time_point begin, end, begin_timer;
   };

  //====================================================
  //     Operator << redefinition
  //====================================================
  /**
   * @brief Operator << used to print the progress bar properties.
   * 
   * @tparam bar_type It is the type of the progress bar.
   * @param os It is the output stream used to print the progress bar.
   * @param pb It is the progress bar object.
   * @return std::ostream& It is the output stream with the given progress bar properties printed out.
   */
  template <typename bar_type>
  std::ostream& operator << ( std::ostream& os, const ProgressBar<bar_type> &pb )
   {
    os << "Max: " << pb.getMax() << "\n"
       << "Min: " << pb.getMin() << "\n"
       << "Time counter: " << pb.getTime() << "\n" 
       << "Style: " << pb.getStyle() << "\n"
       << "Type: " << pb.getType() << "\n"
       << "Message: " << pb.getMessage() << "\n"
       << "Brackets style: " << pb.getBrackets_open() << pb.getBrackets_close()<< "\n"
       << "Color: " << pb.getColorName() << "\n"
       << "Show remaining time: " << pb.getRemainingTimeFlag() << "\n";

    return os;
   }
 }
      
#endif