# How-to-use guides

## Table of contents

- [Introduction](#introduction)
- [Output stream manipulators](#output-stream-manipulators)
  - [Colors and styles manipulation](#colors-and-styles-manipulation)
  - [Cursor navigation](#cursor-navigation)
  - [Terminal control sequences](#terminal-control-sequences)
  - [Extra functions (print and others)](#extra-functions-print-and-others)
- [Progress bars](#progress-bars)
  - [Percentage indicator](#percentage-indicator)
  - [Loading bar](#loading-bar)
  - [Full progress bar](#full-progress-bar)
  - [Progress spinner](#progress-spinner)
- [Terminal graphics](#terminal-graphics)
  - [2D graphics](#2D-graphics)

## Introduction

Here you can find examples of all the features supported in the current version of the library and how to use them.
> **NOTE**: all the examples are written supposing to use the following directive:
> ```c++
> using namespace osm;
> ```
> just to imptove readability.

## Output stream manipulators

Can be accessed by including:
```c++
#include <osmanip/manipulators/csmanip.hpp>
using namespace osm //to improve examples readability (avoid if possible).
```

This manipulators are used to modify and manipulate the output stream of a program.

### Colors and styles manipulation

List of the supported color / style features (part of the output of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) program):

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

Blink string feature:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/blink.gif" width="250">

If you want to change for example the output stream color into red you have to call the `feat` function and give it the `col` map as a first argument and the color name as the second one. See the following example:
```c++
cout << feat( col, "red" ) << "This stream is red!" << reset( "color" );
```
This will color the output stream in red until the `reset( "color" )` function is met again, in order to reset the output stream color.

It is possible to access a wider variety of colors by directly using the `RGB( int r, int g, int b )` function and the corresponding rgb color codes from [this page](http://www.aksiom.net/rgb.html). For example:
```c++
std::string DeepPink = RGB( 255, 20, 147 );

cout << DeepPink << "This stream is deep pink!" << reset( "color" );
```

You can also print mixed color and style strings:
```c++
cout << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" );
```
This will underline and color the output stream in red until the `reset( "all" )` function is met again, in order to reset all the output stream color / style.

List of available colors [here](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=error%20/%20Inserted%20color,gray%20/%20%5C033%5B1%3B37m).
List of available styles [here](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=It%20is%20used%20for%20the%20style,italics%20/%20%5C033%5B3m).
List of the reset commands [here](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=error%20/%20Inserted%20reset,crossed%20/%20%5C033%5B29m).

### Cursor navigation

You can modify the cursor navigation in all the 4 directions (up, down, right, left) by using the `feat` function within the `crs` map, in this way:

```c++
cout << feat( crs, "left" ) << "Moving cursor on the left";
```

You can additionally add a third argument to the `feat` function, in order to increase the parameter of the ANSI code of the cursor navigation (see [*manipulators/csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/manipulators/csmanip.cpp)):

```c++
cout << feat( crs, "left", "10" ) << "Moving cursor on the left";
```

> If you want to know all the available features, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=is%20used%20for%20the%20output,error%20/%20Inserted%20cursor%20command) page.

It is not so easy to show a simple example of this feature. Certainly, a very intuitive application is for progress bars creation, explained in the next section. See the progress bar update method definition in [*progressbar/progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progressbar/progress_bar.cpp#:~:text=output_%20%3D%20feat(%20crs,getStyle()%3B)) for more information.

### Terminal control sequences

You can add a terminal control sequency to your output by using the `feat`  function within the `tcs` or `tcsc` maps (depends on the task), in this way:
```c++
cout << feat( tcs, "bell" );
```
For example, the previous command will output a bell sound from your computer.
> If you want to know all the available features, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=error%20/%20Inserted%20terminal,25h%20%3A%20show%20cursor.) page.

If you plan to use the sequences for clearing screen / line, please have a look [here](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=It%20is%20used%20for%20the%20terminal%20control%20sequences%20manipulation%20for%20clear%20line%20/%20screen.%20It%20is%20used%20within%20the%20feat%20function%20overload%20with%203%20arguments%20and%20n%20as%20the%20third%20one.%20It%20currently%20supports%20the%20following%20list%20of%20sequences) to fully understand their usage.

## Extra functions (print and others)

Some extra functions are provided:
- [`go_to`](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=the%20corresponding%20key.-,go_to,the%20screen%20and%20returns%20the%20interested%20position%20you%20want%20to,-reach.): to put the cursor in a precise (x,y) point of the terminal.
- [`OPTION`](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=Template%20functions-,OPTION,-Header%20file%3A%20osmanip): to set the cursor view on or off in your program.
- [`print`](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=cursor%20is%20hidden.-,print,-Header%20file%3A%20osmanip): it is used to print one or more strings (or other type of objects) in the output stream, specifying also the stream you want to write to. It is inspired by the Python `print` function.

## Progress bars

From release [2.0.0](https://github.com/JustWhit3/osmanip/releases/tag/v2.0.0) of the library, also progress bars have been introduced.

Can be accessed by including:
```c++
#include <osmanip/progressbar/progressbar.hpp>
using namespace osm //to improve examples readability (avoid if possible).
```

A list of all the customizable [settings](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setMax(%20bar_type,std%3A%3Astring%20time_flag%20)) of these progress bars:

- [**Type**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setStyle(%20const%20std%3A%3Astring%26%20type%2C%20const%20std%3A%3Astring%26%20style%20)%3A%20to%20set%20the%20bar%20style.): percentage indicator, loading bar, full progress bar and progress spinner.
- [**Min**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setMin(%20const%20bar_type%26%20min%20)%3A%20to%20set%20min%20value%20of%20the%20bar.) and [**max**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setMax(%20const%20bar_type%26%20max%20)%3A%20to%20set%20max%20value%20of%20the%20bar.) values (for the loop iteration).
- [**Style**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setStyle(%20const%20std%3A%3Astring%26%20type%2C%20const%20std%3A%3Astring%26%20style%20)%3A%20to%20set%20the%20bar%20style.) (ex: % or /100 for a percentage indicator, etc...). You can also create and add new ones.
- [**Messages**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setMessage(%20const%20std%3A%3Astring%26%20message%20)%3A%20to%20set%20optional%20message%20of%20the%20bar.).
- [**Brackets style**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setBrackets(%20const%20std%3A%3Astring%26%20brackets_open%2C%20const%20std%3A%3Astring%26%20brackets_close%20)%3A%20to%20set%20brackets%20style.) (for the loading and full progress bar).
- [**Color**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setColor(%20const%20std%3A%3Astring%26%20color%20)%3A%20to%20set%20progress%20bar%20color.).
- [**Remaining time flag**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setRemainingTimeFlag(%20const%20std%3A%3Astring%26%20time_flag%20)%3A%20to%20switch%20on/off%20the%20showing%20of%20the%20remaining%2Dtime%20info.).
- [**CPU time-consuming info**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setBegin()%3A%20to,void%20setEnd()).
- [**Run progress bars simultaneously**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=be%20explained%20here.-,MultiProgressBar,template%20%3Cclass...%20Inds%3E%20make_MultiProgressBar(%20Inds%26%26...%20bars%20)%3A%20main%20constructor.,-Public%20methods%3A).


Here you can find some examples about how to use them into your code.
> If you want to know more precisely all the available methods of this class, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=This%20template%20class%20is%20used%20to%20create%20progress,Constructors%20/%20destructor%3A) page.

> **TIP**: when using a progress bar in a main program, you can hide the cursor by calling the [`OPTION`](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=Template%20functions-,OPTION,-Header%20file%3A%20osmanip) function at the beginning and then at the end of the program.

> It may happens that cursor disappears if stopping a program in which a progress bar is running. In this case you have to simply close the terminal and open a new one to restore it.

### Percentage indicator

Initialize and use a percentage progress bar:

```c++
ProgressBar <int> percentage_bar;
percentage_bar.setMin( 5 );
percentage_bar.setMax ( 46 );
percentage_bar.setStyle( "indicator", "%" );

cout << "This is a normal percentage bar: " << endl;
 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   sleep_for( milliseconds( 100 ) );
   percentage_bar.update( i );
   //Do some operations...
  }
```

> **NOTE**: `sleep_for( milliseconds( 100 ) )` has been inserted to delay the loop in order to better visualize the progress bar into this .gif file. You don't need to use it in your code.

> **NOTE**: you can insert each `min` and `max` value you prefer, like also -3 and 52 for example, and the bar will work perfectly too.

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_percentage.gif" width="400">

Add a message to a percentage bar and change its style:
```c++
percentage_bar.setMessage( " processing..." );
percentage_bar.setStyle( "indicator", "/100" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/message_percentage.gif" width="550">

Add CPU time consuming info when using a progress bar in loops:
```c++
cout << "This is a percentage bar with time consuming info: " << endl;

 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   percentage_bar.setBegin();
   sleep_for( milliseconds( 100 ) );
   percentage_bar.update( i );
   //Do some operations...
   percentage_bar.setEnd();
  }

cout << endl << "Time needed to complete the previous cycle: " << percentage_bar.getTime() << " ms." << endl;
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/time_percentage.gif" width="500">

It is possible to add also [colors](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setColor(%20const%20std%3A%3Astring%26%20color%20)%3A%20to%20set%20progress%20bar%20color.) and much more.

>**HINT**: To use a progress bar with a standard template data container:
>
>```c++
>vector<int> v = {/* list of integers */};
>
>ProgressBar <int> percentage_bar;
>percentage_bar.setMin( 0 );
>percentage_bar.setMax ( v.size() );
>percentage_bar.setStyle( "indicator", "%" );
>
>for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); ++i )
> {
>  sleep_for( milliseconds( 100 ) );
>  percentage_bar.update( i );
>  //Do some operations...
> }
>```

### Loading bar

You can also create a classic loading bar:

```c++
ProgressBar <int> loading_bar( 3, 25 );
loading_bar.setStyle( "loader", "#" );
loading_bar.setBrackets( "{", "}" );
loading_bar.setMessage( "processing..." );

cout << "This is a normal loading bar: " << endl;
for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
 {
  sleep_for( milliseconds( 100 ) );
  loading_bar.update( i );
  //Do some operations...
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_loading.gif" width="400">

And customize it with messages and time-consuming info, like the previous percentage.

### Full progress bar

You can create a full progress bar with this setting:

```c++
progress_bar.setStyle( "complete", "%", "#" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/mixed_bar.gif" width="400">

You can also add new customized styles, both for indicator and loader:

```c++
progress_bar.addStyle( "indicator", "|100" );
progress_bar.addStyle( "loader", ">" );
progress_bar.setStyle( "complete", "|100", ">" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/mixed_bar_add.gif" width="550">

It is possible to add also time-remaining info for each progress bar type:

```c++
progress_bar.setRemainingTimeFlag( "on" );
progress_bar.resetRemainingTime(); //To get more precise time values.
//Loop initialization...
```

>**NOTE**: to get more precise time values, and in particular if you plan to reuse the same progress bar in future loops, it would be better to add this line:
>```c++
>progress_bar.resetRemainingTime();
>```
>before each loop initialization.

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/time_remaining.gif" width="700">

To add more progress bar simultaneously using threads:

additionally include:
```c++
#include <osmanip/progressbar/multi_progress_bar.hpp>
```
and then:
```c++
cout << "These are 3 progress bars printed simultaneously: " << endl << endl << endl;

ProgressBar<int> prog_int;
prog_int.setMin( 0 );
prog_int.setMax ( 60 );
prog_int.setStyle( "complete", "%", "#" );
prog_int.setBrackets( "[", "]" );
prog_int.setMessage( "Installing..." );
prog_int.setColor( "red" );

ProgressBar<int> prog_int_2( 5, 25 );
prog_int_2.setStyle( "complete", "%", "■" );
prog_int_2.setBrackets( "{", "}" );
prog_int_2.setMessage( "Processing..." );
prog_int_2.setColor( "purple" );

ProgressBar<float> prog_float;
prog_float.setMin( 0.1f );
prog_float.setMax ( 5.8f );
prog_float.setStyle( "complete", "%", "#" );
prog_float.setBrackets( "[", "]" );
prog_float.setMessage( "Downloading..." );
prog_float.setColor( "yellow" );

auto bars = MultiProgressBar( prog_int, prog_int_2, prog_float );

auto job1 = [ &bars, &prog_int ]() 
 {
  for( int i = prog_int.getMin(); i < prog_int.getMax(); i++ ) 
   {
    bars.for_one( 0, updater{}, i );
    sleep_for( milliseconds( 100 ) );
   }
 };

auto job2 = [ &bars, &prog_int_2 ]() 
 {
  for( int i = prog_int_2.getMin(); i < prog_int_2.getMax(); i++) 
   {
    bars.for_one( 1, updater{}, i );
    sleep_for( milliseconds( 200 ) );
   }
 };

auto job3 = [ &bars, &prog_float ]() 
 {
  for( float i = prog_float.getMin(); i < prog_float.getMax(); i += 0.1f ) 
   {
    bars.for_one( 2, updater{}, i );
    sleep_for( milliseconds( 60 ) );
   }
 };

thread first_job(job1);
thread second_job(job2);
thread third_job(job3);

first_job.join();
second_job.join();
third_job.join();

cout << endl << endl << endl;
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/multi_bars.gif" width="550">

### Progress spinner

To initialize a progress spinner:

```C++
ProgressBar <int> spinner;
spinner.setMin( 2 );
spinner.setMax ( 33 );
spinner.setStyle( "spinner", "/-\\|" );
cout << "This is a progress spinner: " << endl;

for ( int i = spinner.getMin(); i < spinner.getMax(); i++ )
 {
  sleep_for( milliseconds( 100 ) );
  spinner.update( i );
  //Do some operations...
 }

cout << endl << endl;
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/spinner.gif" width="550">

If you add a new stile to the spinner:

```C++
spinner.addStyle( "spinner", "|/_\\" );
spinner.setStyle( "spinner", "|/_\\" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/spinner_2.gif" width="550">

## Terminal graphics

From release [3.0.0](https://github.com/JustWhit3/osmanip/releases/tag/v3.0.0) of the library, also terminal graphics have been introduced. For the moment, only 2D graphics is available, but probably, in the future, also 3D will be.

A list of all the customizable [settings](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=be%20explained%20here.-,Canvas,it%20internally%3B%20to%20make%20the%20changes%20effective%20in%20the%20console,-%2C%20you%20must%20use) of this feature:

- [**Size of the graphic canvas**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=Canvas(%20uint%20width%2C%20uint%20height%20)%3A%20the): to set the canvas dimensions.
- [**Enable or disable the canvas frame**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setFrame(%20FrameStyle%20style%2C%20const%20std%3A%3Astring%26%20feat%20%3D%20%22%22%20)%3A%20Set%20the%20FrameStyle): to flag to frame or not the canvas.
- [**Set the canvas background**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20setBackground(%20char%20c%2C%20const%20std%3A%3Astring%26%20feat%20%3D%20%22%22%20)%3A%20Set%20the): to set the canvas background color
- [**Put a character in the canvas**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=void%20put(%20uint%20x%2C%20uint%20y%2C%20char%20c%2C%20const%20std%3A%3Astring%26%20feat%20%3D%20%22%22%20)%3A%20Put%20a%20character%20in%20the): to put a character inside the canvas.
- [**Plot 2D objects**](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=in%20the%20console.-,Plot2DCanvas,used%20to%20plot%20mathematical%20functions%20%24%5CR%20%5Cto%20%5CR%24.%20In%20addition,-to%20all%20the): to plot 2D mathematical functions.

Here you can find some examples about how to use terminal graphics in your code.
> If you want to know more precisely all the available methods of this class, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=be%20explained%20here.-,Canvas,-Header%20file%3A%20canvas) page.

> **TIP**: when using a progress bar in a main program, you can hide the cursor by calling the [`OPTION`](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md#:~:text=Template%20functions-,OPTION,-Header%20file%3A%20osmanip) function at the beginning and then at the end of the program.

> It may happens that cursor disappears if stopping a program in which a progress bar is running. In this case you have to simply close the terminal and open a new one to restore it.

### 2D graphics

To include canvas objects:
```c++
#include <osmanip/graphics/canvas.hpp>
#include <osmanip/graphics/plot_2D.hpp>
using namespace osm //to improve examples readability (avoid if possible).
```

To display an animation in a canvas:

```C++
Canvas canvas(10,10);
canvas.setBackground( '.', feat( col, "bg white" ) + feat( col, "black" ) );
for( uint i = 0; i < 10; i++ )
 {
  canvas.clear();
  canvas.put( 0, 2, 'x' );
  canvas.put( i, 3, 'A', feat( col, "red" ) );
  canvas.put( 5, 0, 'B', feat( col, "blue" ) );
  canvas.put( 7, 8, 'Z', feat( col, "bg cyan" ) + feat( col, "black" ) + feat( sty, "bold" ) );
  canvas.refresh();
  this_thread::sleep_for( chrono::milliseconds( 100 ) );
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_animation.gif" width="400">

To display a canvas with an ASCII frame:

```C++
Canvas ascii_framed_canvas( 15, 10 );
ascii_framed_canvas.enableFrame( true );
ascii_framed_canvas.setFrame( FrameStyle::ASCII, feat( col, "bg white" ) + feat( col, "black" ) );
ascii_framed_canvas.clear();
ascii_framed_canvas.put( 3, 4, 'H' );
ascii_framed_canvas.put( 4, 4, 'e' );
ascii_framed_canvas.put( 5, 4, 'l' );
ascii_framed_canvas.put( 6, 4, 'l' );
ascii_framed_canvas.put( 7, 4, 'o' );
ascii_framed_canvas.refresh();
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_ascii_frame.png" width="400">

To draw a canvas with a box frame:

```C++
Canvas box_framed_canvas( 20, 8 );
box_framed_canvas.enableFrame( true );
box_framed_canvas.setFrame( FrameStyle::BOX );
box_framed_canvas.clear();
box_framed_canvas.put( 3, 4, 'H' );
box_framed_canvas.put( 4, 4, 'e' );
box_framed_canvas.put( 5, 4, 'l' );
box_framed_canvas.put( 6, 4, 'l' );
box_framed_canvas.put( 7, 4, 'o' );
box_framed_canvas.refresh();
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_box_frame.png" width="400">

To plot 2D canvas with sin and cos functions:

```C++
cout << endl << "Plot2DCanvas with sin and cos" << endl;
Plot2DCanvas plot_2d_canvas( 50, 20 );
plot_2d_canvas.setBackground( ' ', feat( col, "bg white" ) );
plot_2d_canvas.enableFrame( true );
plot_2d_canvas.setFrame( FrameStyle::BOX, feat( col, "bg white" ) + feat( col, "black" ) );
plot_2d_canvas.enableFrame( true );
plot_2d_canvas.setFrame( FrameStyle::BOX, feat( col, "bg white" ) + feat( col, "black" ) );
plot_2d_canvas.setScale( 1/3.14, 0.2) ;
for( float i = 0; i < 40; i++ )
 {
  plot_2d_canvas.setOffset( i/3.14, -2 );
  plot_2d_canvas.clear();
  plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                       float{ return std::cos( x ); } ), 'X', feat( col, "bg white" ) + feat( col, "bd red" ) );
  plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                       float{ return std::sin( x ); } ), 'X', feat( col, "bg white" ) + feat( col, "bd blue" ) );
  plot_2d_canvas.refresh();
  sleep_for( milliseconds( 100 ) );
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_sincos.gif" width="400">