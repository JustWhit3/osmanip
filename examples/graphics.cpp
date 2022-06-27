//My headers
#include "../include/manipulators/colsty.hpp"
#include "../include/graphics/canvas.hpp"
#include "../include/graphics/plot_2D.hpp"
#ifdef _WIN32
#include "../include/utility/windows.hpp"
#endif
#include "../include/utility/options.hpp"

//STD headers
#include <iostream>
#include <thread>
#include <chrono>

//====================================================
//     2D terminal graphics
//====================================================
void canvas_2d()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     CANVAS                                    " << "\n"
            << "======================================================" << "\n\n";
  
    std::cout << "Display an animation in a canvas" << "\n";

    osm::Canvas canvas(10,10);
    canvas.setBackground( '.', osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
    for( unsigned int i = 0; i < 10; i++ )
     {
      canvas.clear();
      canvas.put( 0, 2, 'x' );
      canvas.put( i, 3, 'A', osm::feat( osm::col, "red" ) );
      canvas.put( 5, 0, 'B', osm::feat( osm::col, "blue" ) );
      canvas.put( 7, 8, 'Z', osm::feat( osm::col, "bg cyan" ) + osm::feat( osm::col, "black" ) + osm::feat( osm::sty, "bold" ) );
      canvas.refresh();
      std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
     }
    
    std::cout << "\n" << "Canvas with an ASCII frame" << "\n";
    
    osm::Canvas ascii_framed_canvas( 15, 10 );
    ascii_framed_canvas.enableFrame( true );
    ascii_framed_canvas.setFrame( osm::FrameStyle::ASCII, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
    ascii_framed_canvas.clear();
    ascii_framed_canvas.put( 3, 4, 'H' );
    ascii_framed_canvas.put( 4, 4, 'e' );
    ascii_framed_canvas.put( 5, 4, 'l' );
    ascii_framed_canvas.put( 6, 4, 'l' );
    ascii_framed_canvas.put( 7, 4, 'o' );
    ascii_framed_canvas.refresh();
    
    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    
    std::cout << "\n" << "Canvas with a BOX frame" << "\n";
    
    osm::Canvas box_framed_canvas( 20, 8 );
    box_framed_canvas.enableFrame( true );
    box_framed_canvas.setFrame( osm::FrameStyle::BOX );
    box_framed_canvas.clear();
    box_framed_canvas.put( 3, 4, 'H' );
    box_framed_canvas.put( 4, 4, 'e' );
    box_framed_canvas.put( 5, 4, 'l' );
    box_framed_canvas.put( 6, 4, 'l' );
    box_framed_canvas.put( 7, 4, 'o' );
    box_framed_canvas.refresh();
    
    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    
    std::cout << "\n" << "Plot2DCanvas with sin and cos" << "\n";

    osm::Plot2DCanvas plot_2d_canvas( 50, 20 );
    plot_2d_canvas.setBackground( ' ', osm::feat( osm::col, "bg white" ) );
    plot_2d_canvas.enableFrame( true );
    plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
    plot_2d_canvas.enableFrame( true );
    plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
    plot_2d_canvas.setScale( 1/3.14, 0.2) ;
    for( float i = 0; i < 40; i++ )
     {
      plot_2d_canvas.setOffset( i/3.14, -2 );
      plot_2d_canvas.clear();
      plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                           float{ return std::cos( x ); } ), 'X', osm::feat( osm::col, "bg white" ) + 
                            osm::feat( osm::col, "bd red" ) );
      plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                           float{ return std::sin( x ); } ), 'X', osm::feat( osm::col, "bg white" ) + 
                           osm::feat( osm::col, "bd blue" ) );
      plot_2d_canvas.refresh();
      std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
     }

    std::cout << "\n\n";
 }

//====================================================
//     Main
//====================================================
int main()
 {
  #ifdef _WIN32
  osm::OPTION( osm::ANSI::ON );
  osm::OPTION( osm::UNICODECH::ON );
  #endif

  osm::OPTION( osm::CURSOR::OFF );
 
  canvas_2d();

  osm::OPTION( osm::CURSOR::ON );

  #ifdef _WIN32
  osm::OPTION( osm::ANSI::OFF );
  osm::OPTION( osm::UNICODECH::OFF );
  #endif
 }