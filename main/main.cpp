#include <iostream>
#include "../osmanip/include/osmanip.h"
using namespace std;

int main ()
 {
       //Colored strings:
  cout << endl << "---------------------   LIST OF THE AVAILABLE COLORS   ---------------------" << endl << endl
  
       << color ("black") << "This is a black string." << reset () << endl
       << color ("red") << "This is a red string." << reset () << endl
       << color ("green") << "This is a green string." << reset () << endl
       << color ("orange") << "This is an orange string." << reset () << endl
       << color ("blue") << "This is a blue string." << reset () << endl
       << color ("magenta") << "This is a magenta string." << reset () << endl
       << color ("cyan") << "This is a cyan string." << reset () << endl
       << color ("white") << "This is a white string." << reset () << endl
       
       //Styled strings:
       << endl << "---------------------   LIST OF THE AVAILABLE STYLES   ---------------------" << endl << endl
       
       << style ("bold") << "This is a bold string." << reset () << endl
       << style ("transparent") << "This is a transparent string." << reset () << endl
       << style ("italics") << "This is an italics string." << reset () << endl
       << style ("underlined") << "This is an underlined string." << reset () << endl
       << style ("highlighted") << "This is an highlighted string." << reset () << endl
       << style ("invisible") << "This is an invisible string." << reset () << "It was an invisible string." << endl
       << style ("striped") << "This is a striped string." << reset () << endl
       
       //Colored highlight strings:
       << endl << "---------------------   LIST OF THE AVAILABLE COLORED HIGHLIGHTS   ---------------------" << endl << endl
       
       << hl_color ("hl green 1") << "This is a green 1 highlight string." << reset () << endl
       << hl_color ("hl green 2") << "This is a green 2 highlight string." << reset () << endl
       << hl_color ("hl green 3") << "This is a green 3 highlight string." << reset () << endl
       << hl_color ("hl red") << "This is a red highlight string." << reset () << endl
       << hl_color ("hl yellow") << "This is a yellow highlight string." << reset () << endl
       << hl_color ("hl cyan") << "This is a cyan highlight string." << reset () << endl
       << hl_color ("hl grey") << "This is a grey highlight string." << reset () << endl
       << hl_color ("hl white") << "This is a white highlight string." << reset () << endl;

 }
 

