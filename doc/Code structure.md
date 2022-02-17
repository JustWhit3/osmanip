# Library objects

## Table of contents
- [Namespaces](#namespaces)
- [Classes](#classes)
  * [ProgressBar](#progressbar)
  * [MultiProgressBar](#multiprogressbar)
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
  * [tcsc](#tcsc)

## Namespaces

A global namespace `osm` is used to contain all the library classes, functions and variables. It is present in all the header files.

## Classes

### ProgressBar

This template class is used to create progress bars. Templated type is called `bar_type`.

Header file: [*progressbar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/progress_bar.hpp)

Source code: [*progressbar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp)

Constructors / destructor:
- `ProgressBar()`: default constructor which set to null values the main attributes.
- `~ProgressBar()`: standard destructor. It doesn't do anything.

Setter methods: 

- `void setMax( bar_type max )`: to set max value of the bar.
- `void setMin( bar_type min )`: to set min value of the bar.
- `void setStyle( std::string type, std::string style )`: to set the bar style.
- `void setStyle( std::string type, std::string style_p, std::string style_l )`: to set the bar style in case of a complete bar.

> Standard available types are `indicator` and `loader`, `complete` (with both `indicator` and `loader`) and `spinner`.

> Standard available styles are: `%` and `/100` for indicator, `■` and `#` for loader and `/-\\|` for spinner.

- `void setMessage( std::string message )`: to set optional message of the bar.
- `void setBegin()`: to set begin time for the CPU time counting.
- `void setEnd()`: to set end time for the CPU time counting.
- `void setBrackets( std::string brackets_open, std::string brackets_close )`: to set brackets style.
- `void setColor( std::string color )`: to set progress bar color.
- `void setRemainingTimeFlag( std::string time_flag )`: to switch on/off the showing of the remaining-time info.

> Color name has to be set with corresponding name of a `crs` map element.

- `void resetAll()`: to reset all the main attributes.
- `void resetMax()`: to reset max value of the bar.
- `void resetMin()`: to reset min value of the bar.
- `void resetStyle()`: to reset the bar style.
- `void resetMessage()`: to reset optional message of the bar.
- `void resetTime()`: to reset CPU time count.
- `void resetBrackets()`: to reset brackets style.
- `void resetColor()`: to reset progress bar color.
- `void resetRemainingTime()`: to reset the time start, before showing the time-remaining info of the bar (this helps getting a more precise value of the time-remaining info at each iteration).

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
- `std::string getRemainingTimeFlag()`: to get the value of the remaining-time info flag (on or off).

Other methods: 

- `void update( bar_type iterating_var )`: to update the bar after each loop cycle.
- `void print()`: to print on the screen all the progress bar variable values.
- `void addStyle( std::string type, std::string style )`: to create customized progress bar styles.
- `void remaining_time()`: to compute the remaining time for the completion of the progress bar.
- `bar_type one( bar_type iterating_var )`: to get the unit used to calculate the real iterating variable of the `update` method.

All the attributes are private and used in the above methods, therefore they don't need to be explained here.

### MultiProgressBar

This template class is used to create multi progress bars (real name is `make_MultiProgressBar`). Templated type is a parameter pack and called `... Indicators`.

Header file and source code: [*multi_progressbar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/multi_progress_bar.hpp)

Constructors / destructor:

- `template <class... Inds> make_MultiProgressBar( Inds&&... bars )`: main constructor.

Public methods:

- `template <class Func, class... Args> void for_one( size_t idx, Func&& func, Args&&... args )`: to update a single bar in a thread.
- `template <class Func, class... Args> void for_each( Func&& func, Args&&... args )`: to update each bar in a thread.

Private methods:

- `template <size_t... Ids, class Func, class... Args> void call_one( size_t idx, indices <Ids...>, Func func, Args&&... args )`: used in the `for_one` method.
- `template <size_t... Ids, class Func, class... Args> void call_one( indices <Ids...>, Func func, Args&&... args )`: used in the `for_each` method.

Other helper functions defined outside of the class, but in the same header:

- `template <class... Indicators> make_MultiProgressBar <typename std::remove_reference <Indicators>::type...> MultiProgressBar( Indicators&&... inds )`: helper function used for deduction guides.
- `template <template <class> class PB, class bar_type> auto operator()( PB <bar_type>& pb, typename type_identity <bar_type>::type v ) const`: functor used to call the `ProgressBar` class `update` method.

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
  * `hcrs` / `\x1b[?25l` : hide cursor.
  * `scrs` / `\x1b[?25h` : show cursor.

### tcs

Header file: [*csmanippp*](https://github.com/JustWhit3/osmanip/blob/main/include/csmanip.hpp)

Source code: [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)

Complete definition: `std::map <std::string, std::pair<std::string, std::string>> tcsc`

It is used for the terminal control sequences manipulation for clear line / screen. It is used within the [`feat` function overload](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=Overload%3A%20std%3A%3Astring%20feat(%20std%3A%3Amap%20%3Cstd%3A%3Astring%2C%20std%3A%3Apair%3Cstd%3A%3Astring%2C%20std%3A%3Astring%3E%3E%20%26%20generic_map%2C%20std%3A%3Astring%20feat_string%2C%20int%20feat_int%20).) with 3 arguments and `n` as the third one. It currently supports the following list of sequences (first `std::string`) with the corresponding ASCII code (second `std::pair<std::string, std::string>`) or string value in the case of the `error` feature:
  * `error` / `Inserted cursor command`
  * `csc` / `\u001b[` / `J` : clear the screen:
    * `n=0`: clears from cursor until end of screen.
    * `n=1`: clears from cursor to beginning of screen.
    * `n=2`: clears entire screen.
  * `cln` / `\u001b[` / `K` : clear the line:
    * `n=0`: clears from cursor to end of line.
    * `n=1`: clears from cursor to start of line.
    * `n=2`: clears entire line.
    
