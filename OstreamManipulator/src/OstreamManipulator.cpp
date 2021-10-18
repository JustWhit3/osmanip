#include <string>
#include "../include/OstreamManipulator.h"
using namespace std;


//Functions definition:
string color (string){return 0;};
string style (string){return 0;};


//Reset variables definition:
string reset = "\033[0m";


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

