# Library objects

## Table of contents
- [Namespaces](#namespaces)
- [Classes](#classes)
  * [ProgressBar](#progressbar)
- [Functions](#functions)
  * [feat](#feat)
  * [reset](#reset)
- [Global variables](#global-variables)
  * [col](#col)
  * [sty](#sty)
  * [rst](#rst)
  * [crs](#crs)

## Namespaces

A global namespace `osm` is used to contain all the library classes, functions and variables. It is present in all the header files.

## Classes

### ProgressBar

This class is used to create progress bars.

Header file: [*progressbar.h*](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar.h)

Source code: [*progressbar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progressbar.cpp)

Constructors / destructor:
- `ProgressBar()`: default constructor which set to null values the main attributes.
- `~ProgressBar()`: standard destructor. It doesn't do anything.

Setter methods: 
- `void setMax( long long int max )`: to set max value of the bar.
- `void setMin( long long int min )`: to set min value of the bar.
- `void setStyle( std::string style )`: to set the bar style.
- `void setMessage( std::string message )`: to set optional message of the bar.
- `void setBegin()`: to set begin time for the CPU time counting.
- `void setEnd()`: to set end time for the CPU time counting.
- `void reset()`: to reset all the main attributes.
- `void resetMax()`: to reset max value of the bar.
- `void resetMin()`: to reset min value of the bar.
- `void resetStyle()`: to reset the bar style.
- `void resetMessage()`: to reset optional message of the bar.
- `void resetTime()`: to reset CPU time count.
> **NOTE**: progress bar class fully supports all the positive, negative and null *int* variables. *double* and *floats* are supported too even if they don't optimally work for the moment, in the sense that a few precision in lost when using them into loops.

Getter methods:
- `long long int getMax()`: to get max value of the bar.
- `long long int getMin()`: to get min value of the bar.
- `long long int getTime()`: to get time for the CPU counting of a process.
- `long long int getIteratingVar()`: to get the iterating variable of the `update` method.
- `std::string getStyle()`: to get the bar style.
- `std::string getMessage()`: to get the optional bar message.

Other methods: 
- `void update( long long int iterating_var )`: to update the bar after each loop cycle.
> **NOTE**: `std::cout` object cannot be used inside a loop within the `update` method.

All the attributes are private and used in the above methods, therefore they don't need to be explained here.

## Functions

### feat

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string )`.

It takes an `std::map` object as the first argument and an `std::string` object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.

### reset

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string reset ( std::string reset_string )`

It takes a `std::string` object (`reset` map key) as argument and returns the interested color / style reset string by returning the map value from the corresponding key.

## Global variables

### col

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::string> col`

It is used for the color output stream manipulation and currently supports the following list of colors (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted color`
  * `black` / `\033[30m`
  * `red` / `\033[31m`
  * `green` / `\033[32m`
  * `orange` / `\033[33m`
  * `blue` / `\033[34m`
  * `purple` / `\033[35m`
  * `cyan` / `\033[36m`
  * `gray` / `\033[37m`
  * `dk gray` / `\033[90m`
  * `lt red` / `\033[91m`
  * `lt green` / `\033[92m`
  * `yellow` / `\033[93m`
  * `lt blue` / `\033[94m`
  * `lt purple` / `\033[95m`
  * `lt cyan` / `\033[96m`
  * `white` / `\033[97m`
  * `bg black` / `\033[40m`
  * `bg red` / `\033[41m`
  * `bg green` / `\033[42m`
  * `bg orange` / `\033[43m`
  * `bg cyan` / `\033[44m`
  * `bg purple` / `\033[45m`
  * `bg blue` / `\033[46m`
  * `bg gray` / `\033[47m`
  * `bg dk gray` / `\033[100m`
  * `bg lt red` / `\033[101m`
  * `bg lt green` / `\033[102m`
  * `bg yellow` / `\033[103m`
  * `bg lt blue` / `\033[104m`
  * `bg lt purple` / `\033[105m`
  * `bg ly cyan` / `\033[106m`
  * `bg white` / `\033[107m`
  * `bd black` / `\033[1;30m`
  * `bd red` / `\033[1;31m`
  * `bd green` / `\033[1;32m`
  * `bd orange` / `\033[1;33m`
  * `bd blue` / `\033[1;34m`
  * `bd purple` / `\033[1;35m`
  * `bd cyan` / `\033[1;36m`
  * `bd gray` / `\033[1;37m`
> **Note**
> "bg" is the prefix of the background color features and "bd" is the one of the bold color features.

### sty

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::string> sty`

It is used for the style output stream manipulation and currently supports the following list of styles (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted color`
  * `bold` / `\033[1m`
  * `faint` / `\033[2m`
  * `italics` / `\033[3m`
  * `underlined` / `\033[4m`
  * `blink` / `\033[5m`
  * `inverse` / `\033[7m`
  * `invisible` / `\033[8m`
  * `crossed` / `\033[9m`
  * `d-underlined` / `\033[21m`
  
### rst

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::string> rst`

It is used to reset features and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted reset command`
  * `all` / `\033[0m`
  * `color` / `\033[39m`
  * `bg color` / `\033[49m`
  * `bd color` / `\033[22m + \033[39m`
  * `bd/ft` / `\033[22m`
  * `italics` / `\033[23m`
  * `underlined` / `\033[24m`
  * `blink` / `\033[25m`
  * `inverse` / `\033[27m`
  * `invisible` / `\033[28m`
  * `crossed` / `\033[29m`
  
### crs

Header file: [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.cpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::string> crs`

It is used for the output stream cursor naviagation and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature:
  * `error` / `Inserted cursor command`
  * `up` / \ `u001b[A`
  * `down` / `\u001b[B`
  * `right` / `\u001b[C`
  * `left` / `\u001b[D`
