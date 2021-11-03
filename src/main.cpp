#include <iostream>
#include "../include/osmanip.h"
using namespace std;

int main ()
 {
  //Testing functions:
  feat_test( col );
  feat_test( sty );
  reset_test();

  //Output all the features:
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
 

