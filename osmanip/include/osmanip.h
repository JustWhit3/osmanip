#ifndef OSMANIP_H
#define OSMANIP_H

#include <string>
using namespace std;

//Functions definition:
string color (string color_string),
       style (string style_string);
       
//Reset variables declaration (please note that the reset variable resets ALL, both colors and styles):
extern string reset;

//Error variables declaration:
extern string error;

//Color variables declaration:
extern string black,
              red,
              green,
              orange,
              blue,
              violet,
              light_blue,
              white;
              
//Light color variables declaration:
                                    
//Style variables declaration:
extern string bold, 
              transparent,
              italics,
              underlined,
              highlighted,
              invisible,
              striped;
            
#endif
