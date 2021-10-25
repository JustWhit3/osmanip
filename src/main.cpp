#include <iostream>
#include "../include/osmanip.h"
using namespace std;

int main ()
 {
  //Testing functions:
  feat_test( col );
  feat_test( sty );

  //Output all the features:
  cout << endl << "---------------------   LIST OF THE AVAILABLE COLORS   ---------------------" << endl << endl
  
       << feat( col, "black" ) << "This is a black string." << feat( col, "reset" ) << endl
       << feat( col, "red" ) << "This is a red string." << feat( col, "reset" ) << endl
       << feat( col, "green" ) << "This is a green string." << feat( col, "reset" ) << endl
       << feat( col, "orange" ) << "This is an orange string." << feat( col, "reset" ) << endl
       << feat( col, "blue" ) << "This is a blue string." << feat( col, "reset" ) << endl
       << feat( col, "magenta" ) << "This is a magenta string." << feat( col, "reset" ) << endl
       << feat( col, "cyan" ) << "This is a cyab string." << feat( col, "reset" ) << endl
       << feat( col, "white" ) << "This is a white string." << feat( col, "reset" ) << endl
       
       << endl << "---------------------   LIST OF THE AVAILABLE BACKGROUND COLORS   ---------------------" << endl << endl
       
       << feat( col, "bg green 1" ) << "This is a background green 1 string." << feat( col, "reset" ) << endl
       << feat( col, "bg green 2" ) << "This is a background green 2 string." << feat( col, "reset" ) << endl
       << feat( col, "bg green 3" ) << "This is a green background 3 string." << feat( col, "reset" ) << endl
       << feat( col, "bg red" ) << "This is a background red string." << feat( col, "reset" ) << endl
       << feat( col, "bg yellow" ) << "This is a background yellow string." << feat( col, "reset" ) << endl
       << feat( col, "bg cyan" ) << "This is a background cyan string." << feat( col, "reset" ) << endl
       << feat( col, "bg grey" ) << "This is a background grey string." << feat( col, "reset" ) << endl
       << feat( col, "bg white" ) << "This is a background white string." << feat( col, "reset" ) << endl
       
       << endl << "---------------------   LIST OF THE AVAILABLE STYLES   ---------------------" << endl << endl
       
       << feat( sty, "bold" ) << "This is a bold string." << feat( sty, "reset" ) << endl
       << feat( sty, "italics" ) << "This is an italics string." << feat( sty, "reset" ) << endl
       << feat( sty, "underlined" ) << "This is an underlined string." << feat( sty, "reset" ) << endl
       << feat( sty, "faint" ) << "This is a faint string." << feat( sty, "reset" ) << endl
       << feat( sty, "highlighted" ) << "This is an highlighted string." << feat( sty, "reset" ) << endl
       << feat( sty, "invisible" ) << "This is an invisible string." << feat( sty, "reset" ) << "It was an invisible string." << endl
       << feat( sty, "striped" ) << "This is a striped string." << feat( sty, "reset" ) << endl;
 }
 

