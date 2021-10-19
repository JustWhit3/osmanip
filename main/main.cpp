#include <iostream>
#include "../osmanip/include/osmanip.h"
using namespace std;

int main ()
 {
  cout << "This is a normal string." << endl
  
       //Colored strings:
       << color("black") << "This is a black string." << color("reset") << endl
       << color("red") << "This is a red string." << color("reset") << endl
       << color("green") << "This is a green string." << color("reset") << endl
       << color("orange") << "This is an orange string." << color("reset") << endl
       << color("blue") << "This is a blue string." << color("reset") << endl
       << color("violet") << "This is a red string." << color("violet") << endl
       << color("light blue") << "This is a light blue string." << color("reset") << endl
       << color("white") << "This is a white string." << color("reset") << endl
       
       
       //Styled strings:
       << style("bold") << "This is a bold string." << style("reset") << endl
       << style("transparent") << "This is a transparent string." << style("reset") << endl
       << style("italics") << "This is an italics string." << style("reset") << endl
       << style("underlined") << "This is an underlined string." << style("reset") << endl
       << style("highlighted") << "This is an highlighted string." << style("reset") << endl
       << style("invisible") << "This is an invisible string." << style("reset") << "It was an invisible string." << endl
       << style("striped") << "This is a striped string." << style("reset") << endl;
       
       //Mixed strings:
 }
 
 
