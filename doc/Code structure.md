# Library objects

## Table of contents
- [Namespaces](#namespaces)
- [Classes](#classes)
  * [ProgressBar](#progressbar)
  * [MultiProgressBar](#multiprogressbar)
  * [Canvas](#canvas)
  * [Plot2DCanvas](#plot2dcanvas)
- [Functions](#functions)
  * [feat](#feat)
  * [reset](#reset)
  * [go_to](#goto)
  * [RGB](#RGB)
- [Template functions](#template-functions)
  * [OPTION](#OPTION)
  * [print](#print)
- [Global variables](#global-variables)
  * [col](#col)
  * [sty](#sty)
  * [rst](#rst)
  * [crs](#crs)
  * [tcs](#tcs)
  * [tcsc](#tcsc)
- [Enum classes](#enum-classes)
  * [CURSOR](#CURSOR)
  * [FrameStyle](#framestyle)

## Namespaces

A global namespace `osm` is used to contain all the library classes, functions and variables. It is present in all the header files.

## Classes

### ProgressBar

This template class is used to create progress bars. Templated type is called `bar_type`.

Header file: [*osmanip/progressbar/progressbar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar/progress_bar.hpp)

Source code: [*osmanip/progressbar/progressbar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progressbar/progress_bar.cpp)

Constructors / destructor:
- `ProgressBar()`: default constructor which set to null values the main attributes.
- `~ProgressBar()`: standard destructor. It doesn't do anything.

Setter methods: 

- `void setMax( const bar_type& max )`: to set max value of the bar.
- `void setMin( const bar_type& min )`: to set min value of the bar.
- `void setStyle( const std::string& type, const std::string& style )`: to set the bar style.
- `void setStyle( const std::string& type, const std::string& style_p, const std::string& style_l )`: to set the bar style in case of a complete bar.

> Standard available types are `indicator` and `loader`, `complete` (with both `indicator` and `loader`) and `spinner`.

> Standard available styles are: `%` and `/100` for indicator, `■` and `#` for loader and `/-\\|` for spinner.

- `void setMessage( const std::string& message )`: to set optional message of the bar.
- `void setBegin()`: to set begin time for the CPU time counting.
- `void setEnd()`: to set end time for the CPU time counting.
- `void setBrackets( const std::string& brackets_open, const std::string& brackets_close )`: to set brackets style.
- `void setColor( const std::string& color )`: to set progress bar color.
- `void setRemainingTimeFlag( const std::string& time_flag )`: to switch on/off the showing of the remaining-time info.

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

- `void update( const bar_type& iterating_var )`: to update the bar after each loop cycle.
- `void print()`: to print on the screen all the progress bar variable values.
- `void addStyle( const std::string type&, const std::string& style )`: to create customized progress bar styles.
- `void remaining_time()`: to compute the remaining time for the completion of the progress bar.
- `bar_type one( const bar_type& iterating_var )`: to get the unit used to calculate the real iterating variable of the `update` method.

All the attributes are private and used in the above methods, therefore they don't need to be explained here.

### MultiProgressBar

This template class is used to create multi progress bars (real name is `make_MultiProgressBar`). Templated type is a parameter pack and called `... Indicators`.

Header file and source code: [*osmanip/progressbar/multi_progressbar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar/multi_progress_bar.hpp)

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

### Canvas

Header file: [*osmanip/graphics/canvas.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/graphics/canvas.hpp)

Source code: [*osmanip/graphics/canvas.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/graphics/canvas.cpp)

Instances of this class are used to draw in a limited 2D space. All the functions that modify the canvas do it internally; to make the changes effective in the console, you must use the `refresh` method.

Constuctor:

- `Canvas( uint width, uint height )`: the size of the canvas in characters must be specified upon construction.

Setters:

- `void enableFrame( bool frame_enabled )`: flag to frame or not the canvas. The frame doesn't increase the size taken by the canvas. Instead, reduces the 2D space to draw in two columns and two rows (used to print the frame itself).
- `void setFrame( FrameStyle style, const std::string& feat = "" )`: Set the [FrameStyle](#framestyle) of the canvas and an optional [feat](#feat).
- `void setBackground( char c, const std::string& feat = "" )`: Set the char that fills the background and an optional [feat](#feat).
- `void setWidth( uint width )`: Set the width of the canvas.
- `void setHeight( uint height )`: Set the height of the canvas.

Getters:

- `bool isFrameEnabled() const`

- `FrameStyle getFrameStyle() const`
- `std::string getFrameFeat() const`
- `char getBackground() const`
- `std::string getBackgroundFeat() const`
- `uint getWidth() const`
- `uint getHeight() const`

Public methods:

- `void clear()`: Fill the canvas with the background.
- `void put( uint x, uint y, char c, const std::string& feat = "" )`: Put a character in the canvas, given its coordinates and an optional [feat](#feat). An out-of-boudns exception will be thrown if the coordinates are outside the canvas.
- `void refresh()`: Display the canvas in the console.

### Plot2DCanvas

Header file: [*osmanip/graphics/plot_2D.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/graphics/plot_2D.hpp)

Source code: [*osmanip/graphics/plot_2D.hpp*](https://github.com/JustWhit3/osmanip/blob/main/src/graphics/plot_2D.cpp)

This class is used to plot mathematical functions $\R \to \R$. In addition to all the properties of a basic [Canvas](#canvas), this one also has an offset and a scale for the plot. The offset is the first value in x and y to be represented in the canvas and the scale is the difference in x or y that each character represents relative to the previous one.

For example: a canvas of size = (15, 10) with offset = (3,2) and scale = (7, 5) will represent the functions you draw from x=3 to x=3+15\*7=108 and from y=2 to y=2+10\*5=52.

Constructor:

- `Plot2DCanvas( uint width, uint height )`: The same as its parent, the constructor requires the dimensions of the canvas.

Setters:

- `void setOffset( float xOff, float yOff )`: Set the offset of the plot.
- `void setScale( float xScale, float yScale )`: Set the scale of the plot.

Getters:

- `float getOffsetX() const`
- `float getOffsetY() const`
- `float getScaleX() const`
- `float getScaleY() const`

Public functions:

- `template <typename Y, typename X> void draw( std::function<Y( X )> function, char c, const std::string& feat = "" )`: Plot a function that receives an argument of a numeric type `X` and returns a numeric value of type `Y`. Represent it with a given char `c` and an optional [feat](#feat).

## Functions

### feat

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `std::string feat ( const std::map <std::string, std::string>& generic_map, const std::string& feat_string )`.

It takes an `std::map` object as the first argument and an `std::string` object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.

Overload: `std::string feat( const std::map <std::string, std::pair<std::string, std::string>>& generic_map, const std::string& feat_string, const int& feat_int )`.

The overload, with respect to the standard function definition, takes an `std::map` object as the first argument, but with an `std::pair` as second type and additionally takes an extra integer argument to correctly set the parameter of the [`crs`](#crs) map.

### reset

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `std::string reset ( const std::string& reset_string )`

It takes a `std::string` object (`reset` map key) as argument and returns the interested color / style reset string by returning the map value from the corresponding key.

### go_to

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `std::string go_to( const int& x, const int& y )`.

It takes two integers as arguments which are the x and y position of the cursor in the screen and returns the interested position you want to reach.

### RGB

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `std::string RGB( const int& r, const int& g, const int& b )`.

It takes three integers as arguments which are the correspoing rgb triplets of a color (see [here](http://www.aksiom.net/rgb.html) for the full list of availables colors). It can be used to output a wider variety of colors with respect to the standard availables from the `col` map.

## Template functions

### OPTION

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `template <typename T> void OPTION( const T& opt )`.

It takes an enum class as argument, which represent the cursor view state in the current program. If `opt = CURSOR::ON` the cursor is visible, else if `opt = CURSOR::OFF` the cursor is hidden.

### print

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `template <typename... Args> inline void print( std::ostream& os = null_stream, const Args&... args )`.

It takes an `ostream` object as first argument and an indeterminate number of any-type objects as second argument. It can be used to print messages and strings in the output stream, specifying also the stream you want to use. Different standard colors are set for each output-stream type. If the output stream is not specified `std::cout` will be used as default. The building of this function has been inspired by the Python `print` function.

An extra overload: `template <typename... Args> inline void print( Args&... args )` is provided to deal with the case of 0 arguments provided. In this case, the `std::cout` object has been defined as the default stream.

## Global variables

### col

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

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

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

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

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

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

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

Complete definition: `std::map <std::string, std::pair<std::string, std::string>> crs`

It is used for the output stream cursor navigation and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::pair<std::string, std::string>`) or string value in the case of the `error` feature:
  * `error` / `Inserted cursor command`
  * `up` / `\u001b[` / `A` : move cursor up.
  * `down` / `\u001b[` / `B` : move cursor down.
  * `right` / `\u001b[` / `C` : move cursor right.
  * `left` / `\u001b[` / `D` : move cursor left.

### tcs

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

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

### tcsc

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)

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

## Enum classes

### CURSOR

Header file: [*osmanip/manipulators/csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/graphics/csmanip.hpp)

Source code: [*osmanip/manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/graphics/csmanip.cpp)

It is used to store the [`OPTION`][#OPTION] function options for the cursor view. Current options are: `ON` to enable cursor view and `OFF` to disable it.

### FrameStyle

Header file: [*osmanip/graphics/canvas.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/graphics/canvas.hpp)

source: [*osmanip/graphics/canvas.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/graphics/canvas.cpp)

It is used to represent the sytle of a frame for a [`Canvas`](#canvas) object. Values:

- `ASCII`
- `BOX`
- `EMPTY`