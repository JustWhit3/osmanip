#include <iostream>
#include <string>
#include <chrono>

#include "../include/progressbar.h"

namespace osm
 {
  //Definition of the "progress bar" class constructors, methods and members:
  ProgressBar::ProgressBar(): max_( 0 ), min_( 0 ), style_( "" ), message_( "" ), time_count_( 0 ) {}

  ProgressBar::~ProgressBar() {}

  //ProgressBar variables declaration:
  const std::string ProgressBar::error_ = "Inserted ProgressBar style:";

  //ProgressBar setters definition:
  void ProgressBar::setMax( long long int max ) { max_ = max; }

  void ProgressBar::setMin( long long int min ) { min_ = min; }

  void ProgressBar::setStyle( std::string style )
   {
    style_ = style;

    if( style_ != "%" )
     {
      conct_.append( error_ );
      conct_.append( " \"" );
      conct_.append( style_ );
      conct_.append( "\" is not supported!\n" );
      throw std::runtime_error( conct_ );
     }
   }

  void ProgressBar::setMessage( std::string message ) { message_ = message; }

  //ProgressBar resetters definition:
  void ProgressBar::reset() { max_ = 0, min_ = 0, style_ = "", message_ = "", time_count_ = 0; }

  void ProgressBar::resetMax() { max_ = 0; }

  void ProgressBar::resetMin() { min_ = 0; }

  void ProgressBar::resetStyle() { style_ = ""; } 

  void ProgressBar::resetMessage() { message_ = ""; } 

  void ProgressBar::resetTime() { time_count_ = 0; }

  //ProgressBar getters definition:
  long long int ProgressBar::getMax() const { return max_; }

  long long int ProgressBar::getMin() const { return min_; } 

  long long int ProgressBar::getTime() const { return time_count_; }

  long long int ProgressBar::getIteratingVar() const { return iterating_var_; }

  std::string ProgressBar::getStyle() const { return style_; }

  std::string ProgressBar::getMessage() const { return message_; }
 
  //ProgressBar other methods definition:
  void ProgressBar::update( long long int iterating_var )
   {
    iterating_var_ = 100 * ( iterating_var - min_ ) / ( max_ - min_ - 1 );

    if( style_ == "%" )
     {
      conct_.append( "\u001b[100D" );
      conct_.append( std::to_string( iterating_var_ ++ ) );
      conct_.append( "%" );
      std::cout << conct_ << message_ <<std::flush;
     }
    else
     {
      throw std::runtime_error( "ProgressBar style has not been set!" );
     }
   }

   void ProgressBar::setBegin() { begin = std::chrono::steady_clock::now(); }

   void ProgressBar::setEnd()
    {
     end = std::chrono::steady_clock::now();
     time_count_ += std::chrono::duration_cast <std::chrono::milliseconds>( end - begin ).count();
    }
 }