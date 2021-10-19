#include <string>
#include "../include/osmanip.h"
using namespace std;

//Reset variables definition:
string reset = "\033[0m";

//Error variables definition:
string error = "Inserted option is not valid!";

//Color variables definition:
string black = "\033[30m",
       red = "\033[31m",
       green = "\033[32m",
       orange = "\033[33m",
       blue = "\033[34m",
       violet = "\033[35m",
       light_blue = "\033[36m",
       white = "\033[37m";

//Style variables definition:
string bold = "\033[1m",
       transparent = "\033[2m",
       italics = "\033[3m",
       underlined = "\033[4m",
       highlighted = "\033[7m",
       invisible = "\033[8m",
       striped = "\033[9m";

//Functions definition:
string color (string color_string)
 {
  if (color_string == "reset") {return reset;}
  else if (color_string == "black") {return black;}
  else if (color_string == "red") {return red;}
  else if (color_string == "green") {return green;}
  else if (color_string == "orange") {return orange;}
  else if (color_string == "blue") {return blue;}
  else if (color_string == "violet") {return violet;}
  else if (color_string == "light blue") {return light_blue;}
  else if (color_string == "white") {return white;}
  else {return error;}
 }

string style (string style_string)
 {
  if (style_string == "reset") {return reset;}
  else if (style_string == "bold") {return bold;}
  else if (style_string == "transparent") {return transparent;}
  else if (style_string == "italics") {return italics;}
  else if (style_string == "underlined") {return underlined;}
  else if (style_string == "highlighted") {return highlighted;}
  else if (style_string == "invisible") {return invisible;}
  else if (style_string == "striped") {return striped;}
  else {return error;}
 }

