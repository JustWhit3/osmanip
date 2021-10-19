#ifndef OSTREAM_MANIPULATOR_H
#define OSTREAM_MANIPULATOR_H

#include <string>
using namespace std;

//Functions definition:
string color (string color_string),
       style (string style_string);
       
//Reset variables declaration:
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
