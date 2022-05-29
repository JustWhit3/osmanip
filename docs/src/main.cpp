//My headers
#include "../include/manipulators/csmanip.hpp"
#include "../include/progressbar/progress_bar.hpp"
#include "../include/progressbar/multi_progress_bar.hpp"
#include "../include/graphics/canvas.hpp"
#include "../include/graphics/plot_2D.hpp"

//STD headers
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

void col_sty()
 {
  //====================================================
  //     CSMANIP FEATURES
  //====================================================
  std::cout << "\n" << "======================================================" << "\n"
            << "     COLORS                                           " << "\n"
            << "======================================================" << "\n"
  
            << osm::feat( osm::col, "black" ) << "This is a black string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "red" ) << "This is a red string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "green" ) << "This is a green string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "orange" ) << "This is an orange string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "blue" ) << "This is a blue string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "purple" ) << "This is a purple string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "cyan" ) << "This is a cyan string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "gray" ) << "This is a gray string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "dk gray" ) << "This is a dark gray string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "lt red" ) << "This is a light red string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "lt green" ) << "This is a light green string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "yellow" ) << "This is a yellow string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "lt blue" ) << "This is a light blue string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "lt purple" ) << "This is a light purple string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "lt cyan" ) << "This is a light cyan string." 
            << osm::reset( "color" ) << "\n"
            << osm::feat( osm::col, "white" ) << "This is a white string." 
            << osm::reset( "color" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     BOLD COLORS                                      " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::col, "bd black" ) << "This is a bold black string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd red" ) << "This is a bold red string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd green" ) << "This is a bold green string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd orange" ) << "This is a bold orange string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd blue" ) << "This is a bold blue string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd purple" ) << "This is a bold purple string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd cyan" ) << "This is a bold cyan string." 
            << osm::reset( "bd color" ) << "\n"
            << osm::feat( osm::col, "bd gray" ) << "This is a bold gray string." 
            << osm::reset( "bd color" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     BACKGROUND COLORS                                " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::col, "bg black" ) << "This is a background black string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg red" ) << "This is a background red string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg green" ) << "This is a background green string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg orange" ) << "This is a background orange string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg blue" ) << "This is a background blue string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg purple" ) << "This is a background purple string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg cyan" ) << "This is a background cyan string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg gray" ) << "This is a background gray string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg dk gray" ) << "This is a background dark gray string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt red" ) << "This is a background light red string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt green" ) << "This is a background light green string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg yellow" ) << "This is a background yellow string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt blue" ) << "This is a background light blue string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt purple" ) << "This is a background light purple string."
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg lt cyan" ) << "This is a background light cyan string." 
            << osm::reset( "bg color" ) << "\n"
            << osm::feat( osm::col, "bg white" ) << "This is a background white string." 
            << osm::reset( "bg color" ) << " <-(white)" << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     STYLES                                           " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::sty, "bold" ) << "This is a bold string." 
            << osm::reset( "bd/ft" ) << "\n"
            << osm::feat( osm::sty, "faint" ) << "This is a faint string." 
            << osm::reset( "bd/ft" ) << "\n"
            << osm::feat( osm::sty, "italics" ) << "This is an italics string." 
            << osm::reset( "italics" ) << "\n"
            << osm::feat( osm::sty, "underlined" ) << "This is an underlined string." 
            << osm::reset( "underlined" ) << "\n"
            << osm::feat( osm::sty, "d-underlined" ) << "This is a doubly underlined string." 
            << osm::reset( "underlined" ) << "\n"
            << osm::feat( osm::sty, "inverse" ) << "This is an inverse string." 
            << osm::reset( "inverse" ) << "\n"
            << osm::feat( osm::sty, "invisible" ) << "This is an invisible string." 
            << osm::reset( "invisible" ) << "It was an invisible string." << "\n"
            << osm::feat( osm::sty, "crossed" ) << "This is a crossed-out string." 
            << osm::reset( "crossed" ) << "\n"
            << osm::feat( osm::sty, "blink" ) << "This is a blink string." 
            << osm::reset( "blink" ) << "\n";
       
  std::cout << "\n" << "======================================================" << "\n"
            << "     MIXED                                           " << "\n"
            << "======================================================" << "\n\n"
            
            << osm::feat( osm::sty, "underlined" ) << osm::feat( osm::col, "red" ) << "This is an underlined red string." 
            << osm::reset( "all" ) << "\n"
            << osm::feat( osm::sty, "italics" ) << osm::feat( osm::col, "blue" ) << "This is an italics blue string." 
            << osm::reset( "all" ) << "\n"
            << osm::feat( osm::sty, "faint" ) << osm::feat( osm::col, "orange" ) << "This is a faint orange string." 
            << osm::reset( "all" ) << "\n";

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
 }

void printer()
 {
  //====================================================
  //     PRINTING FUNCTIONS FEATURES
  //====================================================
  std::cout << "\n" << "======================================================" << "\n"
            << "     PRINTING FUNCTIONS                                           " << "\n"
            << "======================================================" << "\n\n";

  //Normal examples:
  osm::print( std::cout, "This is the ", "\"printf\" ", "function for the normal output stream! ", 100, "% working!" );
  osm::print( std::cerr, "This is the printf function for the stderr stream! ", "Managing errors is always important!" );
  osm::print( std::clog, "Also writing in stdlog is important! ", osm::feat( osm::sty, "underlined" ), "Very important", osm::reset( "underlined" ), "!" );
  osm::print();

  //Writing on a file:
  std::ofstream file_stream;
  file_stream.open( "file.txt", std::ios::trunc );
  osm::print( file_stream, "You can also write in a file! ", 1, 2, 3, 4.5, 7 );
  file_stream.close();
  osm::print( "Text has been wrote to ", "file.txt ", "file!" );

  std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
 }

//====================================================
//     PERCENTAGE BAR
//====================================================
void perc_bars()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     PERCENTAGE BARS                                    " << "\n"
            << "======================================================" << "\n\n";
  
  //Normal percentage bar.
  osm::ProgressBar <int> percentage_bar;
  percentage_bar.setMin( 5 );
  percentage_bar.setMax ( 46 );
  percentage_bar.setStyle( "indicator", "%" );

  std::cout << "This is a normal percentage bar: " << "\n";
  for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";
            
  //Percentage bar with message and different style:
  osm::ProgressBar <float> percentage_bar_2( 1.2f, 4.4f );
  percentage_bar_2.setMessage( "processing..." );
  percentage_bar_2.setStyle( "indicator", "/100" );

  std::cout << "This is a percentage bar with message and the /100 style: " << "\n";
  for ( float i = percentage_bar_2.getMin(); i < percentage_bar_2.getMax(); i += 0.1f )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    percentage_bar_2.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  //Percentage bar with time consuming info:
  percentage_bar.resetMessage();
  percentage_bar.setStyle( "indicator", "%" );

  std::cout << "This is a percentage bar with time consuming info: " << "\n";
  for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    percentage_bar.setBegin();
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
    percentage_bar.setEnd();
   }
  std::cout << "\n" << "Time needed to complete the previous loop: " 
            << percentage_bar.getTime() << " ms." << "\n\n";

  //Percentage bar with estimated time left:
  percentage_bar.setMin( 2 );
  percentage_bar.setMax ( 121 );
  percentage_bar.setRemainingTimeFlag( "on" );
  percentage_bar.resetRemainingTime();

  std::cout << "This is a percentage bar with time-remaining info: " << "\n";
  for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";
 }

//====================================================
//     LOADING BAR
//====================================================
void load_bars()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     LOADING BARS                                    " << "\n"
            << "======================================================" << "\n\n";

  osm::ProgressBar <int> loading_bar;
  loading_bar.setMin( 3 );
  loading_bar.setMax ( 25 );
  loading_bar.setStyle( "loader", "#" );
  loading_bar.setBrackets( "[", "]" );
 
  std::cout << "This is a normal loading bar: " << "\n";
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  //Loading bar with message:
  loading_bar.resetBrackets();
  loading_bar.setMessage( "processing..." );
  loading_bar.setBrackets( "{", "}" );

  std::cout << "This is a loading bar with message: " << "\n";
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  //Loading bar with time remaining info:
  loading_bar.setMin( 3 );
  loading_bar.setMax ( 101 );
  loading_bar.resetMessage();
  loading_bar.setRemainingTimeFlag( "on" );
  loading_bar.resetRemainingTime();

  std::cout << "This is a loading bar with time-remaining info: " << "\n";
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";
 }

//====================================================
//     MIXED BAR
//====================================================
void mixed_bars()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     FULL PROGRESS BARS                                    " << "\n"
            << "======================================================" << "\n\n";

  osm::ProgressBar <float> mixed_bar( 0.1f, 3.8f );
  mixed_bar.setStyle( "complete", "%", "■" );
  mixed_bar.setBrackets( "[", "]" );
  mixed_bar.setMessage( "elaborating..." );
 
  std::cout << "This is a mixed progress bar: " << "\n";
  for ( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  mixed_bar.setColor( "red" );
  mixed_bar.setRemainingTimeFlag( "on" );
  mixed_bar.resetRemainingTime();

  std::cout << "This is a mixed progress bar with color and time remaining info: " << "\n";
  for ( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  mixed_bar.resetColor();
  mixed_bar.addStyle( "indicator", "|100" );
  mixed_bar.addStyle( "loader", ">" );
  mixed_bar.setStyle( "complete", "|100", ">" );
  mixed_bar.setRemainingTimeFlag( "off" );

  std::cout << "This is a mixed progress bar with two customized styles: " << "\n";
  for ( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";
 }

//====================================================
//     MULTI BARS
//====================================================
void multi_bars()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     MULTI PROGRESS BARS                                    " << "\n"
            << "======================================================" << "\n\n";

  std::cout << "These are 3 progress bars printed simultaneously: " << "\n\n\n";

  osm::ProgressBar<int> prog_int;
  prog_int.setMin( 0 );
  prog_int.setMax ( 60 );
  prog_int.setStyle( "complete", "%", "#" );
  prog_int.setBrackets( "[", "]" );
  prog_int.setMessage( "Installing..." );
  prog_int.setColor( "red" );

  osm::ProgressBar<int> prog_int_2( 5, 25 );
  prog_int_2.setStyle( "complete", "%", "■" );
  prog_int_2.setBrackets( "{", "}" );
  prog_int_2.setMessage( "Processing..." );
  prog_int_2.setColor( "purple" );

  osm::ProgressBar<float> prog_float;
  prog_float.setMin( 0.1f );
  prog_float.setMax ( 5.8f );
  prog_float.setStyle( "complete", "%", "#" );
  prog_float.setBrackets( "[", "]" );
  prog_float.setMessage( "Downloading..." );
  prog_float.setColor( "yellow" );

  auto bars = MultiProgressBar( prog_int, prog_int_2, prog_float );

  auto job1 = [ &bars, &prog_int ]() 
   {
    for( int i = prog_int.getMin(); i < prog_int.getMax(); i++ ) 
     {
      bars.for_one( 0, osm::updater{}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
     }
   };

  auto job2 = [ &bars, &prog_int_2 ]() 
   {
    for( int i = prog_int_2.getMin(); i < prog_int_2.getMax(); i++) 
     {
      bars.for_one( 1, osm::updater{}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
     }
   };

  auto job3 = [ &bars, &prog_float ]() 
   {
    for( float i = prog_float.getMin(); i < prog_float.getMax(); i += 0.1f ) 
     {
      bars.for_one( 2, osm::updater{}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 60 ) );
     }
   };

  std::thread first_job(job1);
  std::thread second_job(job2);
  std::thread third_job(job3);

  first_job.join();
  second_job.join();
  third_job.join();

  std::cout << "\n\n\n";
 }

//====================================================
//     PROGRESS SPINNER
//====================================================
void progress_spinner()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     PROGRESS SPINNER                                    " << "\n"
            << "======================================================" << "\n\n";
  
  //Integer progress spinner.
  osm::ProgressBar <int> spinner;
  spinner.setMin( 2 );
  spinner.setMax ( 33 );
  spinner.setStyle( "spinner", "/-\\|" );

  std::cout << "This is a progress spinner: " << "\n";
  for ( int i = spinner.getMin(); i < spinner.getMax(); i++ )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    spinner.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";

  //Float progress spinner.
  osm::ProgressBar <float> spinner_float;
  spinner_float.setMin( 2.3f );
  spinner_float.setMax ( 6.7f );
  spinner_float.setColor( "lt blue" );
  spinner_float.addStyle( "spinner", "|/_\\" );
  spinner_float.setStyle( "spinner", "|/_\\" );
  spinner_float.setMessage( "elaborating data..." );

  std::cout << "This is another progress spinner: " << "\n";
  for ( float i = spinner_float.getMin(); i < spinner_float.getMax(); i += 0.1f )
   {
    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    spinner_float.update( i );
    //Do some operations...
   }
  std::cout << "\n\n";
 }

//====================================================
//     2D TERMINAL GRAPHICS
//====================================================
void canvas_2d()
 {
  std::cout << "\n" << "======================================================" << "\n"
            << "     CANVAS                                    " << "\n"
            << "======================================================" << "\n\n";
  
    std::cout << "Display an animation in a canvas" << "\n";

    osm::Canvas canvas(10,10);
    canvas.setBackground( '.', osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
    for( uint i = 0; i < 10; i++ )
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
//     MAIN
//====================================================
int main()
 {
  osm::OPTION( osm::CURSOR::OFF );
 
  //Manipulators:
  col_sty(); //Color/style.
  printer(); //For printing functions.

  //Progress bars:
  perc_bars(); //Percentage bar.
  load_bars(); //Loading bar.
  mixed_bars(); //Mixed bar.
  multi_bars(); //Multi progress bars
  progress_spinner(); //Progress spinner.
  
  //Terminal graphics visualization:
  canvas_2d();

  osm::OPTION( osm::CURSOR::ON );
 }
