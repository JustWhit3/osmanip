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
       
       << feat( col, "bg green 1" ) << "This is a background green 1 string." << reset( "bg color" ) << endl
       << feat( col, "bg green 2" ) << "This is a background green 2 string." << reset( "bg color" ) << endl
       << feat( col, "bg green 3" ) << "This is a green background 3 string." << reset( "bg color" ) << endl
       << feat( col, "bg red" ) << "This is a background red string." << reset( "bg color" ) << endl
       << feat( col, "bg yellow" ) << "This is a background yellow string." << reset( "bg color" ) << endl
       << feat( col, "bg cyan" ) << "This is a background cyan string." << reset( "bg color" ) << endl
       << feat( col, "bg grey" ) << "This is a background grey string." << reset( "bg color" ) << endl
       << feat( col, "bg white" ) << "This is a background white string." << reset( "bg color" ) << endl
       
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
 

