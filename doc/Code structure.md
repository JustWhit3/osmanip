# Library objects

## Table of contents
- [Namespaces](#namespaces)
- [Classes](#classes)
  * [ProgressBar](#progressbar)
- [Functions](#functions)
  * [feat](#feat)
  * [reset](#reset)
  * [go_to](#goto)
  * [RGB](#RGB)
  * [SET_CURSOR_VIEW](#SETCURSORVIEW)
- [Global variables](#global-variables)
  * [col](#col)
  * [sty](#sty)
  * [rst](#rst)
  * [crs](#crs)
  * [tcs](#tcs)

## Namespaces

A global namespace `osm` is used to contain all the library classes, functions and variables. It is present in all the header files.

## Classes

### ProgressBar

This template class is used to create progress bars. Templated type is called `bar_type`.

Header file: [*progressbar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar.hpp)

Source code: [*progressbar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progressbar.cpp)

Constructors / destructor:
- `ProgressBar()`: default constructor which set to null values the main attributes.
- `~ProgressBar()`: standard destructor. It doesn't do anything.

Setter methods: 
- `void setMax( bar_type max )`: to set max value of the bar.
- `void setMin( bar_type min )`: to set min value of the bar.
- `void setStyle( std::string type, std::string style )`: to set the bar style.
- `void setStyle( std::string type, std::string style_p, std::string style_l )`: to set the bar style in case of a complete bar.
> Standard available types are `indicator` and `loader` and `complete` (with both `indicator` and `loader`).

> Standard available styles are: `%` and `/100` for indicator and `#` for loader.
- `void setMessage( std::string message )`: to set optional message of the bar.
- `void setBegin()`: to set begin time for the CPU time counting.
- `void setEnd()`: to set end time for the CPU time counting.
- `void setBrackets()`: to set brackets style.
- `void setColor( std::string color )`: to set progress bar color.
> Color name has to be set with corresponding name of a `crs` map element.
- `void resetAll()`: to reset all the main attributes.
- `void resetMax()`: to reset max value of the bar.
- `void resetMin()`: to reset min value of the bar.
- `void resetStyle()`: to reset the bar style.
- `void resetMessage()`: to reset optional message of the bar.
- `void resetTime()`: to reset CPU time count.
- `void resetBrackets()`: to reset brackets style.
- `void resetColor()`: to reset progress bar color.
> **NOTE**: progress bar class fully supports all the positive, negative and null *int* variables. *double* and *floats* are supported too even if they don't optimally work for the moment, in the sense that a few precision in lost when using them into loops.

Getter methods:
- `bar_type getMax()`: to get max value of the bar.
- `bar_type getMin()`: to get min value of the bar.
- `bar_type getTime()`: to get time for the CPU counting of a process.
- `bar_type getIteratingVar()`: to get the iterating variable of the `update` method.
- `std::string getStyle()`: to get the bar style.
- `std::string getStyleComplete()`: to get the bar style in case of a mixed type.
- `std::string getType()`: to get the bar type.
- `std::string getMessage()`: to get the optional bar message.
- `std::string getBrackets_open()`: to get the opening bracket.
- `std::string getBrackets_close()`: to get the closing bracket.
- `std::string getColor()`: to get the progress bar color.

Other methods: 
- `void update( bar_type iterating_var )`: to update the bar after each loop cycle.
> **NOTE**: `std::cout` object cannot be used inside a loop within the `update` method.
- `void print()`: to print on the screen all the progress bar variable values.
- `void addStyle( std::string type, std::string style )`: to create customized progress bar styles.
- `bar_type one( bar_type iterating_var )`: to get the unit used to calculate the real iterating variable of the `update` method.

All the attributes are private and used in the above methods, therefore they don't need to be explained here.

## Functions

### feat

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string )`.

It takes an `std::map` object as the first argument and an `std::string` object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.

Overload: `std::string feat( std::map <std::string, std::pair<std::string, std::string>> & generic_map, std::string feat_string, int feat_int )`.

The overload, with respect to the standard function definition, takes an `std::map` object as the first argument, but with an `std::pair` as second type and additionally takes an extra integer argument to correctly set the parameter of the [`crs`](#crs) map.

### reset

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string reset ( std::string reset_string )`

It takes a `std::string` object (`reset` map key) as argument and returns the interested color / style reset string by returning the map value from the corresponding key.

### go_to

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string go_to( int x, int y )`.

It takes two integers as arguments which are the x and y position of the cursor in the screen and returns the interested position you want to reach.

### RGB

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::string RGB( int r, int g, int b )`.

It takes three integers as arguments which are the correspoing rgb triplets of a color (see [here](http://www.aksiom.net/rgb.html) for the full list of availables colors). It can be used to output a wider variety of colors with respect to the standard availables from the `col` map.

### SET_CURSOR_VIEW

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `void SET_CURSOR_VIEW( std::string onof )`.

It takes a string as argument, which represent the cursor view state in the current program. If `onof = ON` the cursor if visible, else if `onof = OFF` the cursor is hidde.

## Global variables

### col

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

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

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

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

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

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

Header file: [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::pair<std::string, std::string>> crs`

It is used for the output stream cursor navigation and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::pair<std::string, std::string>`) or string value in the case of the `error` feature:
  * `error` / `Inserted cursor command`
  * `up` / `\u001b[` / `A` : move cursor up.
  * `down` / `\u001b[` / `B` : move cursor down.
  * `right` / `\u001b[` / `C` : move cursor right.
  * `left` / `\u001b[` / `D` : move cursor left.

### tcs

Header file: [*csmanippp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::string> tcs`

It is used for the terminal control sequences manipulation and currently supports the following list of sequences (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted terminal control sequence`
  * `bell` / `\x07` : bell sound.
  * `bksp` / `\x08` : backspace.
  * `tab` / `\x09` : tab.
  * `lfd` / `\x0A` : line feed.
  * `ffd` / `\x0C` : form feed.
  * `crt` / `\x0D` : carriage return.
  * `csc` / `\x1b[2J\x1b[1;1H` : clear screen.
  * `cln` / `\x1b[2K` : clear line.
  * `hcrs` / `\x1b[?25l` : hide cursor.
  * `scrs` / `\x1b[?25h` : show cursor.