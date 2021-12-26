#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <cmath>
#include "../include/helper_tools.h"
#include "../include/csmanip.h"
#include "../include/progress_bar.h"

namespace osm
 {
  //====================================================
  //     DEFINITION OF THE CONSTRUCTORS AND DESTRUCTOR
  //====================================================
  template <typename bar_type>
  ProgressBar <bar_type>::ProgressBar(): 
   max_( 0 ), 
   min_( 0 ), 
   style_( "" ), 
   type_( "" ),
   message_( "" ), 
   time_count_( time_type::duration::zero().count() ),
   brackets_open_( "" ), 
   brackets_close_( "" ), 
   color_( reset( "color" ) ) 
   {}

  template <typename bar_type>
  ProgressBar <bar_type>::~ProgressBar() {}

  //====================================================
  //     DEFINITION OF THE STATIC ATTRIBUTES
  //====================================================
  template <typename bar_type>
  string_set_map ProgressBar <bar_type>::styles_map_
   {
    { "indicator", { "%", "/100" } },
    { "loader", { "#" } },
   };

  template <typename bar_type>
  std::vector <bar_type> ProgressBar <bar_type>::counter_ (2);

  template <typename bar_type>
  std::string ProgressBar <bar_type>::null_str = "";
  
  template <typename bar_type>
  std::string ProgressBar <bar_type>::empty_space = " ";
  
  //====================================================
  //     DEFINITION OF THE SETTERS
  //====================================================
  template <typename bar_type>
  void ProgressBar <bar_type>::setMax( bar_type max )
   { 
    max_ = max; 
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::setMin( bar_type min )
   {
    min_ = min; 
   }

  //First setStyle overload, to set style of loader or indicator:
  template <typename bar_type>
  void ProgressBar <bar_type>::setStyle( std::string type, std::string style )
   {
    try
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
    catch ( std::out_of_range const & exception )
     {
      throw runtime_error_func( "Inserted ProgressBar type", type, "is not supported!" );
     }
   }

  //Second setStyle overload, to set style of complete bar:
  template <typename bar_type>
  void ProgressBar <bar_type>::setStyle( std::string type, std::string style_p, std::string style_l )
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

  template <typename bar_type>
  void ProgressBar <bar_type>::setMessage( std::string message ) 
   { 
    message_ = message; 
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::setBegin() 
   { 
    begin = time_type::now();
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::setEnd()
   {
    end = time_type::now();
    time_count_ += std::chrono::duration_cast <std::chrono::milliseconds>( end - begin ).count();
   }
  
  template <typename bar_type>
  void ProgressBar <bar_type>::setBrackets( std::string brackets_open, std::string brackets_close )
   { 
    brackets_open_ = brackets_open,
    brackets_close_ = brackets_close;
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::setColor( std::string color )
   { 
    color_ = feat( col, color );
   }

  //====================================================
  //     DEFINITION OF THE RESETTERS
  //====================================================
  template <typename bar_type>
  void ProgressBar <bar_type>::resetAll() 
   { 
    max_ = static_cast<bar_type> ( NULL ), 
    min_ = static_cast<bar_type> ( NULL ), 
    style_ = "", 
    type_ = "",
    message_ = "", 
    time_count_ = 0,
    brackets_open_ = "", 
    brackets_close_= "", 
    color_ = reset( "color" ); 
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::resetMax()
   { 
    max_ = static_cast<bar_type> ( NULL );
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::resetMin()
   {
    min_ = static_cast<bar_type> ( NULL );
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::resetStyle()
   {
    style_.clear();
    type_.clear();
   } 

  template <typename bar_type>
  void ProgressBar <bar_type>::resetMessage()
   {
    message_.clear();
   } 

  template <typename bar_type>
  void ProgressBar <bar_type>::resetTime()
   {
    time_count_ = time_type::duration::zero().count();
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::resetBrackets() 
   {
    brackets_open_.clear(),
    brackets_close_.clear(); 
   }

  template <typename bar_type>
  void ProgressBar <bar_type>::resetColor() 
   { 
    color_ = reset( "color" ); 
   }

  //====================================================
  //     DEFINITION OF THE GETTERS
  //====================================================
  template <typename bar_type>
  bar_type ProgressBar <bar_type>::getMax() const 
   { 
    return max_; 
   }

  template <typename bar_type>
  bar_type ProgressBar <bar_type>::getMin() const 
   { 
    return min_;
   } 

  template <typename bar_type>
  long long ProgressBar <bar_type>::getTime() const 
   {
    return time_count_;
   }

  template <typename bar_type>
  bar_type ProgressBar <bar_type>::getIteratingVar() const 
   { 
    return iterating_var_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getStyle() const 
   { 
    return style_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getStyleComplete() const 
   { 
    if( type_ == "complete" )
     {
      return "Percentage: \"" + style_p_ + "\"\n" + 
             "Loader: \"" + style_l_ + "\"\n"; 
     }
    else
     {
      return style_; 
     }
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getType() const 
   { 
    return type_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getMessage() const 
   { 
    return message_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getBrackets_open() const 
   {
    return brackets_open_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getBrackets_close() const 
   { 
    return brackets_close_; 
   }

  template <typename bar_type>
  std::string ProgressBar <bar_type>::getColor() const 
   { 
    return color_; 
   }

  //====================================================
  //     DEFINITION OF THE "one" METHOD
  //====================================================
  template <typename bar_type>
  bar_type ProgressBar <bar_type>::one( bar_type iterating_var )
   {
    if( isFloatingPoint( iterating_var ) )
     {
      if( counter_.size() < 2 )
       {
        counter_.push_back( iterating_var );
       }
      if( counter_.size() == 2 )
       {
        return abs( abs( counter_.front() ) - abs( counter_.back() ) );
       }
      return static_cast<bar_type> ( NULL );
     }
    return 1;
   }
 
  //====================================================
  //     DEFINITION OF THE "update" METHOD
  //====================================================
  template <typename bar_type>
  void ProgressBar <bar_type>::update( bar_type iterating_var )
   {
    iterating_var_ = 100 * ( iterating_var - min_ ) / ( max_ - min_ - one( iterating_var ) );
    width_ = ( iterating_var_ + 1 ) / 4;

    //Update of the progress indicator only:
    if( styles_map_.at( "indicator" ).find( style_ ) != styles_map_.at( "indicator" ).end() )
     {
      output_ = feat( crs, "left", 100 ) + 
                getColor() +
                std::to_string( static_cast <int> ( round( iterating_var_ ++ ) ) ) +
                reset( "color" ) + 
                getStyle();

      std::cout << check_condition( [ = ]{ return iterating_var == min_; }, feat( tcs, "hcrs" ), null_str )
                << output_ 
                << getColor() 
                << empty_space + message_ 
                << reset( "color" ) 
                << std::flush
                << check_condition( [ = ]{ return iterating_var == max_ - 1; }, feat( tcs, "scrs" ), null_str );
     }

    //Update of the loader indicator only:
    else if( styles_map_.at( "loader" ).find( style_ ) != styles_map_.at( "loader" ).end() )
     {
      output_ = feat( crs, "left", 100 ) + 
                getBrackets_open() + 
                getColor() + 
                getStyle() * width_ + 
                empty_space * ( 25 - width_ ) + 
                reset( "color" ) + 
                getBrackets_close();  
                     
      std::cout << check_condition( [ = ]{ return iterating_var == min_; }, feat( tcs, "hcrs" ), null_str )
                << output_ 
                << getColor() 
                << empty_space + message_
                << reset( "color" ) 
                << std::flush
                << check_condition( [ = ]{ return iterating_var == max_ - 1; }, feat( tcs, "scrs" ), null_str );
     }

    //Update of the whole progress bar:
    else if ( style_.find( style_p_ ) != std::string::npos && style_.find( style_l_ ) != std::string::npos &&
              type_ == "complete"  )
     {
      output_= feat( crs, "left", 100 ) + 
               getBrackets_open() + 
               getColor() + 
               style_l_ * width_ + 
               empty_space * ( 25 - width_ ) + 
               reset( "color" ) +
               getBrackets_close() + 
               getColor() + 
               empty_space + 
               std::to_string( iterating_var_ ++ ) + 
               reset( "color" ) + 
               style_p_; 

      std::cout << check_condition( [ = ]{ return iterating_var == min_; }, feat( tcs, "hcrs" ), null_str )
                << output_ 
                << getColor() 
                << empty_space + message_ 
                << reset( "color" ) 
                << std::flush
                << check_condition( [ = ]{ return iterating_var == max_ - 1; }, feat( tcs, "scrs" ), null_str );
     }
     
    else
     {
      throw std::runtime_error( "ProgressBar style has not been set!" );
     }
   }

  //====================================================
  //     DEFINITION OF THE "print" METHOD
  //====================================================
   template <typename bar_type>
   void ProgressBar <bar_type>::print() const
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
   template <typename bar_type>
   void ProgressBar <bar_type>::addStyle( std::string type, std::string style )
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
  
  //====================================================
  //     TEMPLATE SPECIALIZATIONS
  //====================================================

  //Standard types:
  template class ProgressBar <long long>;
  template class ProgressBar <long>;
  template class ProgressBar <int>;
  template class ProgressBar <double>;
  template class ProgressBar <long double>;
  template class ProgressBar <float>;
 }