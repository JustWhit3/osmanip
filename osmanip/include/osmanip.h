#ifndef OSMANIP_H
#define OSMANIP_H

#include <string>
using namespace std;

//Functions definition:

       //Function to deal with colors.
string color (string color_string), 

       //Function to deal with highlight colors:
       hl_color (string hl_color_string), 
       
       //Function to deal with styles:
       style (string style_string),
       
       //Function to reset the color/style output stream.
       reset ();
       
//Reset variable declaration (please note that the reset variable resets both colors and styles):
extern string reset_var;

//Error variables declaration:
extern string error;

//Color variables declaration:
extern string black,
              red,
              green,
              orange,
              blue,
              magenta,
              cyan,
              white;
              
//Highlight color variables declaration:
extern string hl_green_1,
              hl_green_2,
              hl_green_3,
              hl_red,
              hl_yellow,
              hl_cyan,
              hl_grey,
              hl_white;
              
                                    
//Style variables declaration:
extern string bold, 
              transparent,
              italics,
              underlined,
              highlighted,
              invisible,
              striped;
            
#endif
