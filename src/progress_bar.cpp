#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include "../include/helper_tools.h"
#include "../include/csmanip.h"
#include "../include/progress_bar.h"

namespace osm
 {
  //Definition of the "progress bar" class constructors and destructors:
  ProgressBar::ProgressBar(): 
   max_( 0 ), 
   min_( 0 ), 
   style_( "" ), 
   type_( "" ),
   message_( "" ), 
   time_count_( 0 ),
   brackets_open_( "" ), 
   brackets_close_( "" ), 
   color_( reset( "color" ) ) 
   {}

  ProgressBar::~ProgressBar() {}

  //ProgressBar static attributes definition:
  string_set_map ProgressBar::styles_map_
   {
    { "indicator", { "%", "/100" } },
    { "loader", { "#" } },
   };

  //ProgressBar setters definition:
  void ProgressBar::setMax( long long max )
   { 
    max_ = max; 
   }

  void ProgressBar::setMin( long long min )
   {
    min_ = min; 
   }

  //First overload, to set style of single loader or indicator:
  void ProgressBar::setStyle( std::string type, std::string style )
   {
    if( styles_map_.at( type ).find( style ) != styles_map_.at( type ).end() )
     {
      style_ = style;
      type_ = type;
     }
    else if( styles_map_.at( type ).find( style ) == styles_map_.at( type ).end() )
     {
      throw runtime_error_func( "Inserted ProgressBar style", style, "is not supported for this type!" );
     }
    else
     {
      throw runtime_error_func( "Inserted ProgressBar type", type, "is not supported!" );
     }
   }

  //Second overload, to set style of complete bar:
  void ProgressBar::setStyle( std::string type, std::string style_p, std::string style_l )
   {
    if( styles_map_.at( "indicator" ).find( style_p ) != styles_map_.at( "indicator" ).end() &&
        styles_map_.at( "loader" ).find( style_l ) != styles_map_.at( "loader" ).end() &&
        type == "complete" )
     {
      style_ = style_p + style_l;
      style_p_ = style_p;
      style_l_ = style_l;
      type_ = type;
     }
    else if( styles_map_.at( "indicator" ).find( style_p ) == styles_map_.at( "indicator" ).end() )
     {
      throw runtime_error_func( "Inserted indicator style", style_p, "is not supported for this type!" );
     }
    else if( styles_map_.at( "loader" ).find( style_l ) == styles_map_.at( "loader" ).end() )
     {
      throw runtime_error_func( "Inserted loader style", style_l, "is not supported for this type!" );
     }
    else
     {
      throw runtime_error_func( "Inserted ProgressBar type", type, "is not supported!" );
     }
   }

  void ProgressBar::setMessage( std::string message ) 
   { 
    message_ = message; 
   }

  void ProgressBar::setBegin() 
   { 
    begin = std::chrono::steady_clock::now();
   }

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

  void ProgressBar::setColor( std::string color )
   { 
    color_ = feat( col, color );
   }

  //ProgressBar resetters definition:
  void ProgressBar::resetAll() 
   { 
    max_ = 0, 
    min_ = 0, 
    style_ = "", 
    type_ = "",
    message_ = "", 
    time_count_ = 0,
    brackets_open_ = "", 
    brackets_close_= "", 
    color_ = reset( "color" ); 
   }

  void ProgressBar::resetMax()
   { 
    max_ = 0;
   }

  void ProgressBar::resetMin()
   {
    min_ = 0;
   }

  void ProgressBar::resetStyle()
   {
    style_.clear();
    type_.clear();
   } 

  void ProgressBar::resetMessage()
   {
    message_.clear();
   } 

  void ProgressBar::resetTime()
   {
    time_count_ = 0;
   }

  void ProgressBar::resetBrackets() 
   {
    brackets_open_.clear(),
    brackets_close_.clear(); 
   }

  void ProgressBar::resetColor() 
   { 
    color_ = reset( "color" ); 
   }

  //ProgressBar getters definition:
  long long ProgressBar::getMax() const 
   { 
    return max_; 
   }

  long long ProgressBar::getMin() const 
   { 
    return min_;
   } 

  long long ProgressBar::getTime() const 
   {
    return time_count_;
   }

  long long ProgressBar::getIteratingVar() const 
   { 
    return iterating_var_; 
   }

  std::string ProgressBar::getStyle() const 
   { 
    return style_; 
   }

  std::string ProgressBar::getType() const 
   { 
    return type_; 
   }

  std::string ProgressBar::getMessage() const 
   { 
    return message_; 
   }

  std::string ProgressBar::getBrackets_open() const 
   {
    return brackets_open_; 
   }

  std::string ProgressBar::getBrackets_close() const 
   { 
    return brackets_close_; 
   }

  std::string ProgressBar::getColor() const 
   { 
    return color_; 
   }
 
  //ProgressBar update method definition:
  void ProgressBar::update( long long iterating_var )
   {
    iterating_var_ = 100 * ( iterating_var - min_ ) / ( max_ - min_ - 1 );
    width_ = ( iterating_var_ + 1 ) / 4;

    if( styles_map_.at( "indicator" ).find( style_ ) != styles_map_.at( "indicator" ).end() )
     {
      output_ = feat( crs, "left", 100 ) + 
                getColor() + 
                std::to_string( iterating_var_ ++ ) +
                reset( "color" ) + 
                getStyle();

      std::cout << output_ 
                << getColor() 
                << " " + message_ 
                << reset( "color" ) 
                << std::flush;
     }
    else if( styles_map_.at( "loader" ).find( style_ ) != styles_map_.at( "loader" ).end() )
     {
      output_ = feat( crs, "left", 100 ) + 
                getBrackets_open() + 
                getColor() + 
                getStyle() * width_ + 
                static_cast <std::string>( " " ) * ( 25 - width_ ) + 
                reset( "color" ) + 
                getBrackets_close();  
                     
      std::cout << output_ 
                << getColor() 
                << " " + message_
                << reset( "color" ) 
                << std::flush;
     }
    else if ( style_.find( style_p_ ) != std::string::npos && style_.find( style_l_ ) != std::string::npos &&
              type_ == "complete"  )
     {
      output_= feat( crs, "left", 100 ) + 
               getBrackets_open() + 
               getColor() + 
               style_l_ * width_ + 
               static_cast <std::string>( " " ) * ( 25 - width_ ) + 
               reset( "color" ) +
               getBrackets_close() + 
               getColor() + 
               " " + 
               std::to_string( iterating_var_ ++ ) + 
               reset( "color" ) + 
               style_p_; 

      std::cout << output_ 
                << getColor() 
                << " " + message_ 
                << reset( "color" ) 
                << std::flush;
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
               << "Brackets style: " << brackets_open_ << brackets_close_<< std::endl
               << "Color: " << color_ << std::endl;
    }

   //ProgressBar addStyle method to add new styles to the already existing ones:
   void ProgressBar::addStyle( std::string type, std::string style )
    {
     if( styles_map_.at( type ).find( style ) == styles_map_.at( type ).end() )
      {
       styles_map_.at(type).insert(style);
      }
     else if( styles_map_.at( type ).find( style ) != styles_map_.at( type ).end() )
      {
       throw runtime_error_func( "Inserted ProgressBar style", style, "is already available!" ); 
      }
     else
      {
       throw runtime_error_func( "Inserted ProgressBar type", type, "is already available!" );
      }
    }
 }