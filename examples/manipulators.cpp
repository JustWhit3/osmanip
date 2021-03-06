//My headers
#include "../include/manipulators/colsty.hpp"
#include "../include/manipulators/printer.hpp"
#ifdef _WIN32
#include "../include/utility/windows.hpp"
#endif
#include "../include/utility/options.hpp"

//STD headers
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

void colsty()
 {
  //====================================================
  //     csmanip
  //====================================================
  std::cout << "\n" << "======================================================" << "\n"
            << "     COLORS                                           " << "\n"
            << "======================================================" << "\n"
  
            << osm::feat( osm::col, "black" ) << "This is a black string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "red" ) << "This is a red string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "green" ) << "This is a green string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "orange" ) << "This is an orange string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "blue" ) << "This is a blue string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "purple" ) << "This is a purple string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "cyan" ) << "This is a cyan string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "gray" ) << "This is a gray string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "dk gray" ) << "This is a dark gray string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "lt red" ) << "This is a light red string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "lt green" ) << "This is a light green string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "yellow" ) << "This is a yellow string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "lt blue" ) << "This is a light blue string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "lt purple" ) << "This is a light purple string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "lt cyan" ) << "This is a light cyan string." 
            << osm::feat( osm::rst, "color" ) << "\n"
            << osm::feat( osm::col, "white" ) << "This is a white string." 
            << osm::feat( osm::rst, "color" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     BOLD COLORS                                      " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::col, "bd black" ) << "This is a bold black string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd red" ) << "This is a bold red string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd green" ) << "This is a bold green string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd orange" ) << "This is a bold orange string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd blue" ) << "This is a bold blue string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd purple" ) << "This is a bold purple string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd cyan" ) << "This is a bold cyan string." 
            << osm::feat( osm::rst, "bd color" ) << "\n"
            << osm::feat( osm::col, "bd gray" ) << "This is a bold gray string." 
            << osm::feat( osm::rst, "bd color" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     BACKGROUND COLORS                                " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::col, "bg black" ) << "This is a background black string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg red" ) << "This is a background red string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg green" ) << "This is a background green string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg orange" ) << "This is a background orange string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg blue" ) << "This is a background blue string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg purple" ) << "This is a background purple string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg cyan" ) << "This is a background cyan string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg gray" ) << "This is a background gray string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg dk gray" ) << "This is a background dark gray string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt red" ) << "This is a background light red string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt green" ) << "This is a background light green string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg yellow" ) << "This is a background yellow string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt blue" ) << "This is a background light blue string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt purple" ) << "This is a background light purple string."
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt cyan" ) << "This is a background light cyan string." 
            << osm::feat( osm::rst, "bg color" ) << "\n"
            << osm::feat( osm::col, "bg white" ) << "This is a background white string." 
            << osm::feat( osm::rst, "bg color" ) << " <-(white)" << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     STYLES                                           " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::sty, "bold" ) << "This is a bold string." 
            << osm::feat( osm::rst, "bd/ft" ) << "\n"
            << osm::feat( osm::sty, "faint" ) << "This is a faint string." 
            << osm::feat( osm::rst, "bd/ft" ) << "\n"
            << osm::feat( osm::sty, "italics" ) << "This is an italics string." 
            << osm::feat( osm::rst, "italics" ) << "\n"
            << osm::feat( osm::sty, "underlined" ) << "This is an underlined string." 
            << osm::feat( osm::rst, "underlined" ) << "\n"
            << osm::feat( osm::sty, "d-underlined" ) << "This is a doubly underlined string." 
            << osm::feat( osm::rst, "underlined" ) << "\n"
            << osm::feat( osm::sty, "inverse" ) << "This is an inverse string." 
            << osm::feat( osm::rst, "inverse" ) << "\n"
            << osm::feat( osm::sty, "invisible" ) << "This is an invisible string." 
            << osm::feat( osm::rst, "invisible" ) << "It was an invisible string." << "\n"
            << osm::feat( osm::sty, "crossed" ) << "This is a crossed-out string." 
            << osm::feat( osm::rst, "crossed" ) << "\n"
            << osm::feat( osm::sty, "blink" ) << "This is a blink string." 
            << osm::feat( osm::rst, "blink" ) << "\n";
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     MIXED                                           " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::sty, "underlined" ) << osm::feat( osm::col, "red" ) << "This is an underlined red string." 
            << osm::feat( osm::rst, "all" ) << "\n"
            << osm::feat( osm::sty, "italics" ) << osm::feat( osm::col, "blue" ) << "This is an italics blue string." 
            << osm::feat( osm::rst, "all" ) << "\n"
            << osm::feat( osm::sty, "faint" ) << osm::feat( osm::col, "orange" ) << "This is a faint orange string." 
            << osm::feat( osm::rst, "all" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
 }

void printer()
 {
  //====================================================
  //     Printing function features
  //====================================================
  std::cout << "\n" << "======================================================" << "\n"
            << "     PRINTING FUNCTIONS                                           " << "\n"
            << "======================================================" << "\n\n";

  //Normal examples:
  osm::print( std::cout, "This is the ", "\"printf\" ", "function for the normal output stream! ", 100, "% working!" );
  osm::print( std::cerr, "This is the printf function for the stderr stream! ", "Managing errors is always important!" );
  osm::print( std::clog, "Also writing in stdlog is important! ", osm::feat( osm::sty, "underlined" ), "Very important", osm::feat( osm::rst, "underlined" ), "!" );
  osm::print( "" );

  //Writing on a file:
  std::ofstream file_stream;
  file_stream.open( "file.txt", std::ios::trunc );
  osm::print( file_stream, "You can also write in a file! ", 1, 2, 3, 4.5, 7 );
  file_stream.close();
  osm::print( "Text has been wrote to ", "file.txt ", "file!" );

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
  
  std::cout << "\n" << "======================================================" << "\n"
            << "     OS_DECORATOR                                        " << "\n"
            << "======================================================" << "\n\n";

  osm::OS_Decorator my_shell;

  // std::cout 
  my_shell.setColor( "green", std::cout );
  my_shell.setStyle( "underlined", std::cout );
  my_shell( std::cout ) << "The stdout stream has been changed using the OS_Decorator class!" << "\n";

  // std::cerr 
  my_shell.setColor( "red", std::cerr );
  my_shell.setStyle( "bold", std::cerr );
  my_shell( std::cerr ) << "The stderr stream has been changed using the OS_Decorator class!" << "\n";

  // std::clog 
  my_shell.setColor( "lt blue", std::clog );
  my_shell.setStyle( "italics underlined", std::clog );
  my_shell( std::clog ) << "The stdlog stream has been changed using the OS_Decorator class!" << "\n";
 }

//====================================================
//     Main
//====================================================
int main()
 {
  #ifdef _WIN32
  osm::enableANSI();
  #endif

  osm::OPTION( osm::CURSOR::OFF );
 
  colsty(); //Color/style.
  printer(); //For printing functions.

  osm::OPTION( osm::CURSOR::ON );
  
  #ifdef _WIN32
  osm::disableANSI();
  #endif
 }