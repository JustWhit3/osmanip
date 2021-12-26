#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void col_sty()
 {
  //====================================================
  //     CSMANIP FEATURES
  //====================================================
  cout << endl << "---------------------   COLORS   ---------------------" << endl << endl
  
       << feat( col, "black" ) << "This is a black string." << reset( "color" ) << endl
       << feat( col, "red" ) << "This is a red string." << reset( "color" ) << endl
       << feat( col, "green" ) << "This is a green string." << reset( "color" ) << endl
       << feat( col, "orange" ) << "This is an orange string." << reset( "color" ) << endl
       << feat( col, "blue" ) << "This is a blue string." << reset( "color" ) << endl
       << feat( col, "purple" ) << "This is a purple string." << reset( "color" ) << endl
       << feat( col, "cyan" ) << "This is a cyan string." << reset( "color" ) << endl
       << feat( col, "gray" ) << "This is a gray string." << reset( "color" ) << endl
       << feat( col, "dk gray" ) << "This is a dark gray string." << reset( "color" ) << endl
       << feat( col, "lt red" ) << "This is a light red string." << reset( "color" ) << endl
       << feat( col, "lt green" ) << "This is a light green string." << reset( "color" ) << endl
       << feat( col, "yellow" ) << "This is a yellow string." << reset( "color" ) << endl
       << feat( col, "lt blue" ) << "This is a light blue string." << reset( "color" ) << endl
       << feat( col, "lt purple" ) << "This is a light purple string." << reset( "color" ) << endl
       << feat( col, "lt cyan" ) << "This is a light cyan string." << reset( "color" ) << endl
       << feat( col, "white" ) << "This is a white string." << reset( "color" ) << endl
       
       << endl << "---------------------   BOLD COLORS   ---------------------" << endl << endl
       
       << feat( col, "bd black" ) << "This is a bold black string." << reset( "bd color" ) << endl
       << feat( col, "bd red" ) << "This is a bold red string." << reset( "bd color" ) << endl
       << feat( col, "bd green" ) << "This is a bold green string." << reset( "bd color" ) << endl
       << feat( col, "bd orange" ) << "This is a bold orange string." << reset( "bd color" ) << endl
       << feat( col, "bd blue" ) << "This is a bold blue string." << reset( "bd color" ) << endl
       << feat( col, "bd purple" ) << "This is a bold purple string." << reset( "bd color" ) << endl
       << feat( col, "bd cyan" ) << "This is a bold cyan string." << reset( "bd color" ) << endl
       << feat( col, "bd gray" ) << "This is a bold gray string." << reset( "bd color" ) << endl
       
       << endl << "---------------------   BACKGROUND COLORS   ---------------------" << endl << endl
       
       << feat( col, "bg black" ) << "This is a background black string." << reset( "bg color" ) << endl
       << feat( col, "bg red" ) << "This is a background red string." << reset( "bg color" ) << endl
       << feat( col, "bg green" ) << "This is a background green string." << reset( "bg color" ) << endl
       << feat( col, "bg orange" ) << "This is a background orange string." << reset( "bg color" ) << endl
       << feat( col, "bg blue" ) << "This is a background blue string." << reset( "bg color" ) << endl
       << feat( col, "bg purple" ) << "This is a background purple string." << reset( "bg color" ) << endl
       << feat( col, "bg cyan" ) << "This is a background cyan string." << reset( "bg color" ) << endl
       << feat( col, "bg gray" ) << "This is a background gray string." << reset( "bg color" ) << endl
       << feat( col, "bg dk gray" ) << "This is a background dark gray string." << reset( "bg color" ) << endl
       << feat( col, "bg lt red" ) << "This is a background light red string." << reset( "bg color" ) << endl
       << feat( col, "bg lt green" ) << "This is a background light green string." << reset( "bg color" ) << endl
       << feat( col, "bg yellow" ) << "This is a background yellow string." << reset( "bg color" ) << endl
       << feat( col, "bg lt blue" ) << "This is a background light blue string." << reset( "bg color" ) << endl
       << feat( col, "bg lt purple" ) << "This is a background light purple string." << reset( "bg color" ) << endl
       << feat( col, "bg lt cyan" ) << "This is a background light cyan string." << reset( "bg color" ) << endl
       << feat( col, "bg white" ) << "This is a background white string." << reset( "bg color" ) << " <-(white)" << endl
       
       << endl << "---------------------   STYLES   ---------------------" << endl << endl
       
       << feat( sty, "bold" ) << "This is a bold string." << reset( "bd/ft" ) << endl
       << feat( sty, "faint" ) << "This is a faint string." << reset( "bd/ft" ) << endl
       << feat( sty, "italics" ) << "This is an italics string." << reset( "italics" ) << endl
       << feat( sty, "underlined" ) << "This is an underlined string." << reset( "underlined" ) << endl
       << feat( sty, "d-underlined" ) << "This is a doubly underlined string." << reset( "underlined" ) << endl
       << feat( sty, "inverse" ) << "This is an inverse string." << reset( "inverse" ) << endl
       << feat( sty, "invisible" ) << "This is an invisible string." << reset( "invisible" ) << "It was an invisible string." << endl
       << feat( sty, "crossed" ) << "This is a crossed-out string." << reset( "crossed" ) << endl
       << feat( sty, "blink" ) << "This is a blink string." << reset( "blink" ) << endl
       
       << endl << "---------------------   MIXED   ---------------------" << endl << endl
       
       << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" ) << endl
       << feat( sty, "italics" ) << feat( col, "blue" ) << "This is an italics blue string." << reset( "all" ) << endl
       << feat( sty, "faint" ) << feat( col, "orange" ) << "This is a faint orange string." << reset( "all" ) << endl;
 }

//====================================================
//     PERCENTAGE BAR
//====================================================
void perc_bars()
 {
  cout << endl << "---------------------   PROGRESS BARS   ---------------------" << endl << endl;
  
  //Normal percentage bar.
  ProgressBar <int> percentage_bar;
  percentage_bar.setMin( 5 );
  percentage_bar.setMax ( 46 );
  percentage_bar.setStyle( "indicator", "%" );

  cout << "This is a normal percentage bar: " << endl;
  for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;
            
  //Percentage bar with message and different style:
  ProgressBar <float> percentage_bar_2;
  percentage_bar_2.setMin( 1.2f );
  percentage_bar_2.setMax ( 6.4f );
  percentage_bar_2.setMessage( "processing..." );
  percentage_bar_2.setStyle( "indicator", "/100" );

  cout << "This is a percentage bar with message and the /100 style: " << endl;
  for ( float i = percentage_bar_2.getMin(); i < percentage_bar_2.getMax(); i += 0.1f )
   {
    sleep_for( milliseconds( 100 ) );
    percentage_bar_2.update( i );
    //Do some operations...
   }
  cout << endl << endl;

  //Percentage bar with time consuming info:
  percentage_bar.resetMessage();
  percentage_bar.setStyle( "indicator", "%" );

  cout << "This is a percentage bar with time consuming info: " << endl;
  for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    percentage_bar.setBegin();
    sleep_for( milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
    percentage_bar.setEnd();
   }
  cout << endl << "Time needed to complete the previous cycle: " << percentage_bar.getTime() << " ms." << endl << endl;
 }

//====================================================
//     LOADING BAR
//====================================================
void load_bars()
 {
  ProgressBar <int> loading_bar;
  loading_bar.setMin( 3 );
  loading_bar.setMax ( 25 );
  loading_bar.setStyle( "loader", "#" );
  loading_bar.setBrackets( "[", "]" );
 
  cout << "This is a normal loading bar: " << endl;
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;

  //Loading bar with message:
  loading_bar.resetBrackets();
  loading_bar.setMessage( "processing..." );
  loading_bar.setBrackets( "{", "}" );

  cout << "This is a loading bar with message: " << endl;
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;

  //Loading bar with time consuming info:
  loading_bar.resetMessage();

  cout << "This is a loading bar with time consuming info: " << endl;
  for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    loading_bar.setBegin();
    sleep_for( milliseconds( 100 ) );
    loading_bar.update( i );
    //Do some operations...
    loading_bar.setEnd();
   }
  cout << endl << "Time needed to complete the previous cycle: " << loading_bar.getTime() << " ms." << endl << endl;
 }

//====================================================
//     MIXED BAR
//====================================================
void mixed_bars()
 {
  ProgressBar <int> mixed_bar;
  mixed_bar.setMin( 3 );
  mixed_bar.setMax ( 25 );
  mixed_bar.setStyle( "complete", "%", "#" );
  mixed_bar.setBrackets( "[", "]" );
  mixed_bar.setMessage( "elaborating..." );
 
  cout << "This is a mixed progress bar: " << endl;
  for ( int i = mixed_bar.getMin(); i < mixed_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;

  mixed_bar.setColor( "red" );

  cout << "This is a mixed progress bar with color: " << endl;
  for ( int i = mixed_bar.getMin(); i < mixed_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;

  mixed_bar.resetColor();
  mixed_bar.addStyle( "indicator", "|100" );
  mixed_bar.addStyle( "loader", ">" );
  mixed_bar.setStyle( "complete", "|100", ">" );

  cout << "This is a mixed progress bar with two customized styles: " << endl;
  for ( int i = mixed_bar.getMin(); i < mixed_bar.getMax(); i++ )
   {
    sleep_for( milliseconds( 100 ) );
    mixed_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;
 }

//====================================================
//     MAIN
//====================================================
int main ()
 {
  //Manipulators:
  //col_sty(); //Color/style.

  //Progress bars:
  //perc_bars(); //Percentage bar.
  //load_bars(); //Loading bar.
  //mixed_bars(); //Mixed bar.

  /*vector<int> v = {1,2,3,1,2,3,1,1,2,3,4,3,2,1,12,3,4,1,2,4,4,2,2,3,4,5,5};
  ProgressBar <vector<int>::iterator> percentage_bar;
  percentage_bar.setMin( v.begin() );
  percentage_bar.setMax ( v.end() );
  percentage_bar.setStyle( "indicator", "%" );

  cout << "This is a normal percentage bar: " << endl;
  for ( vector<int>::iterator i = v.begin(); i < v.end(); ++i )
   {
    sleep_for( milliseconds( 100 ) );
    percentage_bar.update( i );
    //Do some operations...
   }
  cout << endl << endl;*/
  cout << "\x1b[38;2;255;20;147m" << "Testtttt" << reset( "color" ) << endl;
  cout << RGB( 255, 20, 147 ) << "Testtttt" << reset( "color" ) << endl;
 }