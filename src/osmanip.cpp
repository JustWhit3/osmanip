#include <string>
#include <cstdlib>
#include "../include/osmanip.h"
using namespace std;

//Reset variables declaration (please note that the reset variable resets ALL, both colors and styles):
string reset_var = "\033[0m";

//Error variables definition:
string error = "Inserted option is not valid!";

//Color variables definition:
string black = "\033[30m",
       red = "\033[31m",
       green = "\033[32m",
       orange = "\033[33m",
       blue = "\033[34m",
       magenta = "\033[35m",
       cyan = "\033[36m",
       white = "\033[37m";

//Highlight color variables definition:
string hl_green_1 = "\033[40m",
       hl_green_2 = "\033[42m",
       hl_green_3 = "\033[46m",
       hl_red = "\033[41m",
       hl_yellow = "\033[43m",
       hl_cyan = "\033[44m",
       hl_grey = "\033[45m",
       hl_white = "\033[47m";

//Style variables definition:
string bold = "\033[1m",
       transparent = "\033[2m",
       italics = "\033[3m",
       underlined = "\033[4m",
       highlighted = "\033[7m",
       invisible = "\033[8m",
       striped = "\033[9m";

//Reset function definition:
string reset ()
 {
  return reset_var;
 }

//Color function definition:
string color (string color_string)
 {
  if (color_string == "black") {return black;}
  else if (color_string == "red") {return red;}
  else if (color_string == "green") {return green;}
  else if (color_string == "orange") {return orange;}
  else if (color_string == "blue") {return blue;}
  else if (color_string == "magenta") {return magenta;}
  else if (color_string == "cyan") {return cyan;}
  else if (color_string == "white") {return white;}
  else {return error; exit(0);}
 }
 
//Highlight color function definition:
string hl_color (string hl_color_string)
 {
  if (hl_color_string == "hl green 1") {return hl_green_1;}
  else if (hl_color_string == "hl green 2") {return hl_green_2;}
  else if (hl_color_string == "hl green 3") {return hl_green_3;}
  else if (hl_color_string == "hl red") {return hl_red;}
  else if (hl_color_string == "hl yellow") {return hl_yellow;}
  else if (hl_color_string == "hl cyan") {return hl_cyan;}
  else if (hl_color_string == "hl grey") {return hl_grey;}
  else if (hl_color_string == "hl white") {return hl_white;}
  else {return error; exit(0);}
 }

//Style function definition:
string style (string style_string)
 {
  if (style_string == "bold") {return bold;}
  else if (style_string == "transparent") {return transparent;}
  else if (style_string == "italics") {return italics;}
  else if (style_string == "underlined") {return underlined;}
  else if (style_string == "highlighted") {return highlighted;}
  else if (style_string == "invisible") {return invisible;}
  else if (style_string == "striped") {return striped;}
  else {return error; exit(0);}
 }



