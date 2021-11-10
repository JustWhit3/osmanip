#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <chrono>

#include "../include/osmanip.h"


//-----------------------------------------   DEFINITIONS   -----------------------------------------


//Definition of the "color" map:
std::map <std::string, std::string> col 
 {
  //Error variables:
  { "error", "Inserted color" },
  
  //Color variables:
  { "black", "\033[30m" }, { "red", "\033[31m" }, { "green", "\033[32m" }, { "orange", "\033[33m" }, 
  { "blue", "\033[34m" }, { "purple", "\033[35m" }, { "cyan", "\033[36m" }, { "gray", "\033[37m" }, 
  { "dk gray", "\033[90m" }, { "lt red", "\033[91m" },  { "lt green", "\033[92m" }, { "yellow", "\033[93m" },
  { "lt blue", "\033[94m"}, { "lt purple", "\033[95m" }, { "lt cyan", "\033[96m" }, { "white", "\033[97m" },
  
  //Background color variables:
  { "bg black", "\033[40m" }, { "bg red", "\033[41m" }, { "bg green", "\033[42m" }, { "bg orange", "\033[43m" },
  { "bg cyan", "\033[44m" }, { "bg purple", "\033[45m" }, { "bg blue", "\033[46m" }, { "bg gray", "\033[47m" },
  { "bg dk gray", "\033[100m"}, { "bg lt red", "\033[101m" },  { "bg lt green", "\033[102m" }, { "bg yellow", "\033[103m" },
  { "bg lt blue", "\033[104m"}, { "bg lt purple", "\033[105m" }, { "bg lt cyan", "\033[106m" }, { "bg white", "\033[107m" },
  
  //Bold color variables:
  { "bd black", "\033[1;30m"}, { "bd red", "\033[1;31m" }, { "bd green", "\033[1;32m" }, { "bd orange", "\033[1;33m" }, 
  { "bd blue", "\033[1;34m" }, { "bd purple", "\033[1;35m"}, { "bd cyan", "\033[1;36m" }, { "bd gray", "\033[1;37m" }
 };

//Definition of the "style" map:
std::map <std::string, std::string> sty 
 {
  //Error variables:
  { "error", "Inserted style" },
  
  //Color variables:
  { "bold", "\033[1m" }, { "faint", "\033[2m" }, { "italics", "\033[3m" }, { "underlined", "\033[4m" }, 
  { "blink", "\033[5m" }, { "inverse", "\033[7m" }, { "invisible", "\033[8m" }, { "crossed", "\033[9m" },
  {"d-underlined", "\033[21m" }
 };
 
//Definition of the "reset" map:
std::map <std::string, std::string> rst 
 {
  //Error variables:
  { "error", "Inserted reset command" },
  
  //Reset total variables:
  { "all", "\033[0m" },
  
  //Reset color variables:
  { "color", "\033[39m" }, { "bg color", "\033[49m" }, {"bd color", "\033[22m \033[39m"  },
  
  //Reset style variables:
  { "bd/ft", "\033[22m" }, { "italics", "\033[23m" }, { "underlined", "\033[24m" }, { "blink", "\033[25m" }, 
  { "inverse", "\033[27m" }, { "invisible", "\033[28m" }, { "crossed", "\033[29m" },
 };
 
//Definition of the "cursor" map:
std::map <std::string, std::string> crs
 {
  //Error variables:
  { "error", "Inserted cursor command" },
  
  //Cursor variables:
  { "up", "\u001b[A" }, { "down", "\u001b[B" }, { "right", "\u001b[C" }, { "left", "\u001b[D" }
 };
 
//Definiton of the "feat" function:
std::string feat( std::map <std::string, std::string> & generic_map, std::string feat_string )
 {
  if( generic_map.find( feat_string ) == generic_map.end() ) 
   {
    std::string conct;
    conct.append( generic_map.at( "error" ) );
    conct.append( " \"" );
    conct.append( feat_string );
    conct.append( "\" is not supported!\n" );
    throw std::runtime_error( conct );
   }
  else
   {
    return generic_map.at( feat_string );
   }
 }
 
//Definition of the "reset" function
std::string reset ( std::string reset_string )
 {
  if( rst.find( reset_string ) == rst.end() ) 
   {
    std::string conct;
    conct.append( rst.at( "error" ) );
    conct.append( " \"" );
    conct.append( reset_string );
    conct.append( "\" is not supported!\n" );
    throw std::runtime_error( conct );
   } 
  else
   {
    return rst.at( reset_string );
   }
 }
 
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