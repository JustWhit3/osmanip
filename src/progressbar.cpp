#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include "../include/progressbar.h"
#include "../include/csmanip.h"

namespace osm
 {
  //Definition of the "progress bar" class constructors, methods and members:
  ProgressBar::ProgressBar(): max_( 0 ), min_( 0 ), style_( "" ), message_( "" ), time_count_( 0 ),
                              brackets_open_( "" ), brackets_close_( "" ) {}

  ProgressBar::~ProgressBar() {}

  //ProgressBar variables declaration:
  const std::string ProgressBar::error_ = "Inserted ProgressBar style:";

  //ProgressBar setters definition:
  void ProgressBar::setMax( long long int max ) { max_ = max; }

  void ProgressBar::setMin( long long int min ) { min_ = min; }

  void ProgressBar::setStyle( std::string style )
   {
    style_ = style;

    if( style_ != "%" && style_ != "#" )
     {
      throw std::runtime_error( error_ + " \"" + style_ + "\" is not supported!\n" );
     }
   }

  void ProgressBar::setMessage( std::string message ) { message_ = message; }

  void ProgressBar::setBegin() { begin = std::chrono::steady_clock::now(); }

  void ProgressBar::setEnd()
    {
     end = std::chrono::steady_clock::now();
     time_count_ += std::chrono::duration_cast <std::chrono::milliseconds>( end - begin ).count();
    }
  
  void ProgressBar::setBrackets( std::string brackets_open, std::string brackets_close )
   { 
    brackets_open_ = brackets_open,
    brackets_close_ = brackets_close;
   }

  //ProgressBar resetters definition:
  void ProgressBar::reset() { max_ = 0, min_ = 0, style_ = "", message_ = "", time_count_ = 0; }

  void ProgressBar::resetMax() { max_ = 0; }

  void ProgressBar::resetMin() { min_ = 0; }

  void ProgressBar::resetStyle() { style_.clear(); } 

  void ProgressBar::resetMessage() { message_.clear(); } 

  void ProgressBar::resetTime() { time_count_ = 0; }

  void ProgressBar::resetBrackets() { brackets_open_.clear(), brackets_close_.clear(); }

  //ProgressBar getters definition:
  long long int ProgressBar::getMax() const { return max_; }

  long long int ProgressBar::getMin() const { return min_; } 

  long long int ProgressBar::getTime() const { return time_count_; }

  long long int ProgressBar::getIteratingVar() const { return iterating_var_; }

  std::string ProgressBar::getStyle() const { return style_; }

  std::string ProgressBar::getMessage() const { return message_; }

  std::string ProgressBar::getBrackets_open() const { return brackets_open_; }

  std::string ProgressBar::getBrackets_close() const { return brackets_close_; }

  //Operator * redefinition definition to multiply strings by an integer:
  std::string operator * ( const std::string & generic_string, unsigned long long int integer )
   {
    std::stringstream out;
    while (integer--) { out << generic_string; }
    return out.str();
   }
 
  //ProgressBar update method definition:
  void ProgressBar::update( long long int iterating_var )
   {
    iterating_var_ = 100 * ( iterating_var - min_ ) / ( max_ - min_ - 1 );

    if( style_ == "%" )
     {
      std::cout << feat( crs, "left", 100 ) + std::to_string( iterating_var_ ++ ) + getStyle()
                << message_ << std::flush;
     }
    else if( style_ == "#" )
     {
      width_ = ( iterating_var_ + 1 ) / 4;

      std::cout << feat( crs, "left", 100 ) + getBrackets_open() + getStyle() * width_ +
                   static_cast <std::string>( " " ) * ( 25 - width_ ) + getBrackets_close() 
                << message_ << std::flush;
     }
    else
     {
      throw std::runtime_error( "ProgressBar style has not been set!" );
     }
   }

   //ProgressBar print method definition:
   void ProgressBar::print() const
    {
     std::cout << "Max: " << max_ << std::endl 
               << "Min: " << min_ << std::endl 
               << "Time counter: " << time_count_ << std::endl 
               << "Style: " << style_ << std::endl
               << "Message: " << message_ << std::endl
               << "Brackets style: " << brackets_open_ << brackets_close_<< std::endl;
    }
 }