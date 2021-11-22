#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <set>
#include "../include/progressbar.h"
#include "../include/csmanip.h"

namespace osm
 {
  //Definition of the "progress bar" class constructors, methods and members:
  ProgressBar::ProgressBar(): max_( 0 ), min_( 0 ), style_( "" ), message_( "" ), time_count_( 0 ),
                              brackets_open_( "" ), brackets_close_( "" ), color_( reset( "color" ) ) {}

  ProgressBar::~ProgressBar() {}

  //ProgressBar variables declaration:
  const std::string ProgressBar::error_ = "Inserted ProgressBar style";

  std::set <std::string> ProgressBar::set_p_ { "%" };
  
  std::set <std::string> ProgressBar::set_l_ { "#" };

  //ProgressBar setters definition:
  void ProgressBar::setMax( long long int max ) { max_ = max; }

  void ProgressBar::setMin( long long int min ) { min_ = min; }

  void ProgressBar::setStyle( std::string style )
   {
    style_ = style;

    for(auto & element_p: set_p_)
     {
      for(auto & element_l: set_l_ )
       {
        if( ( set_p_.find( style_ ) == set_p_.end() && set_l_.find( style_ ) == set_l_.end() ) &&
            ( style_.find( element_p ) == std::string::npos && style_.find( element_l ) == std::string::npos ) )
         {
          throw std::runtime_error( error_ + " \"" + style_ + "\" is not supported!\n" );
         }
       }
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

  void ProgressBar::setColor( std::string color ) { color_ = feat( col, color ); }

  //ProgressBar resetters definition:
  void ProgressBar::resetAll() { max_ = 0, min_ = 0, style_ = "", message_ = "", time_count_ = 0,
                                 color_ = reset( "color" ); }

  void ProgressBar::resetMax() { max_ = 0; }

  void ProgressBar::resetMin() { min_ = 0; }

  void ProgressBar::resetStyle() { style_.clear(); } 

  void ProgressBar::resetMessage() { message_.clear(); } 

  void ProgressBar::resetTime() { time_count_ = 0; }

  void ProgressBar::resetBrackets() { brackets_open_.clear(), brackets_close_.clear(); }

  void ProgressBar::resetColor() { color_ = reset( "color" ); }

  //ProgressBar getters definition:
  long long int ProgressBar::getMax() const { return max_; }

  long long int ProgressBar::getMin() const { return min_; } 

  long long int ProgressBar::getTime() const { return time_count_; }

  long long int ProgressBar::getIteratingVar() const { return iterating_var_; }

  std::string ProgressBar::getStyle() const { return style_; }

  std::string ProgressBar::getMessage() const { return message_; }

  std::string ProgressBar::getBrackets_open() const { return brackets_open_; }

  std::string ProgressBar::getBrackets_close() const { return brackets_close_; }

  std::string ProgressBar::getColor() const { return color_; }

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
    width_ = ( iterating_var_ + 1 ) / 4;

    if( set_p_.find( style_ ) != set_p_.end() )
     {
      output_ = feat( crs, "left", 100 ) + getColor() + std::to_string( iterating_var_ ++ ) +
                reset( "color" ) + getStyle();
      std::cout << output_ << getColor() << message_ << reset( "color" ) << std::flush;
     }
    else if( set_l_.find( style_ ) != set_l_.end() )
     {
      output_ = feat( crs, "left", 100 ) + getBrackets_open() + getColor() + getStyle() * width_ + 
                static_cast <std::string>( " " ) * ( 25 - width_ ) + reset( "color" ) + getBrackets_close();       
      std::cout << output_ << getColor() << message_ << reset( "color" ) << std::flush;
     }
    else
     {
      for( auto & element_p: set_p_ )
       {
        for( auto & element_l: set_l_ )
         {
          if( style_.find( element_p ) != std::string::npos && style_.find( element_l ) != std::string::npos )
           {
            output_= feat( crs, "left", 100 ) + getBrackets_open() + getColor() + element_l * width_ + 
                          static_cast <std::string>( " " ) * ( 25 - width_ ) + reset( "color" ) +
                          getBrackets_close() + getColor() + " " + std::to_string( iterating_var_ ++ ) + 
                          reset( "color" ) + element_p; 
            std::cout << output_ << getColor() << message_ << reset( "color" ) << std::flush;
           }
          else
           {
            throw std::runtime_error( "ProgressBar style has not been set!" );
           }
         }
       }
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
               << "Brackets style: " << brackets_open_ << brackets_close_<< std::endl
               << "Color: " << color_ << std::endl;
    }
 }