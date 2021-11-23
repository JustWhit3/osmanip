# osmanip

## Table of contents
- [Introduction](#introduction)
- [Documentation](#documentation)
- [List of features](#list-of-features)
  * [Colors and styles manipulation](#colors-and-styles-manipulation)
  * [Cursor navigation](#cursor-navigation)
  * [Progress bars](#progress-bars)

## Introduction

Here I want to present you *osmanip*: my personal C++ library containing useful output-stream tools to be used in your code. Probably there are already some similar libraries in the web that do the same job, but since I personally don't like them at all I preferred writing my own code for that. Thanks to this you can manipulate the output stream of your program with colors, styles (ex: bold, italics, etc...) and helper tools like progress bars and CPU-usage monitor objects. Using this feaures may be very useful to better read error messages or special information you want to be sure other users see when they run your code, or to adorn your general output stream log.

> **NOTE**: all the manipulators of this library are compatible with [iomanip](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/iomanip).

## Documentation

In the [**doc**](https://github.com/JustWhit3/osmanip/blob/main/doc) folder useful documentation files are stored, in order to help the user learning how to properly use the library:
- [*Repository structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Repository%20structure.md): contains general information about the files and folders of the repository.
- [*Code structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md): contains general information about the code structure of the library, therefore details on classes, functions and variables used in it.
- [*Download and install*](https://github.com/JustWhit3/osmanip/blob/main/doc/Download%20and%20install.md): a guide to download, install and run the library into your system.
- [*Todo*](https://github.com/JustWhit3/osmanip/blob/main/doc/Todo.md): contains a list of future implementations of the library.

## List of features

Here you can find examples of all the features supported in the current version of the manipulator and how to use them.
> **NOTE**: all the examples are written supposing to use the following directive:
> ```c++
> using namespace osm;
> ```
### Colors and styles manipulation

List of the supported color / style features (part of the output of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) program):

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

Blink string feature:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/blink.gif" width="250" height="27">

If you want to change for example the output stream color into red you have to call the `feat` function and give it the `col` map as a first argument and the color name as the second one. See the following example:
```c++
cout << feat( col, "red" ) << "This stream is red!" << reset( "color" );
```
This will color the output stream in red until the `reset( "color" )` function is met again, in order to reset the output stream color.

You can also print mixed color and style strings:
```c++
cout << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" );
```
This will underline and color the output stream in red until the `reset( "all" )` function is met again, in order to reset all the output stream color / style.

### Cursor navigation

You can modify the cursor navigation in all the 4 directions (up, down, right, left) by using the `feat` function within the `crs` map, in this way:
```c++
cout << feat( crs, "left" ) << "Moving cursor on the left";
```
You can additionally add a third argument to the `feat` function, in order to increase the parameter of the ANSII code of the cursor navigation (see [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)).
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

It is not so easy to show a simple example of this feature. Certainly, a very intuitive application is for progress bars creation, explained in the next section. See the progress bar update method definition in [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp) for more information.

### Progress bars

From release [2.0.0](https://github.com/JustWhit3/osmanip/releases/tag/v2.0.0) of the library, also progress bars have been introduced. Here you can find some examples about how to use them into your code.
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

Initialize and use a percentage progress bar:
```c++
ProgressBar percentage_bar;
percentage_bar.setMin( 1 );
percentage_bar.setMax ( 100 );
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

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_percentage.gif" width="300" height="50">

Add a message to a percentage bar:
```c++
ProgressBar percentage_bar;
percentage_bar.setMin( 1 );
percentage_bar.setMax ( 100 );
percentage_bar.setStyle( "indicator", "%" );
percentage_bar.setMessage( " processing..." );

cout << "This is a percentage bar with message: " << endl;
 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   sleep_for( milliseconds( 100 ) );
   percentage_bar.update( i );
   //Do some operations...
  }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/message_percentage.gif" width="350" height="50">

Add CPU time consuming info when using a progress bar in loops:
```c++
ProgressBar percentage_bar;
percentage_bar.setMin( 1 );
percentage_bar.setMax ( 100 );
percentage_bar.setStyle( "indicator", "%" );

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

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/time_percentage.gif" width="475" height="85">

It is possible to add also colors and much more.

You can also create a classic loading bar:
```c++
ProgressBar loading_bar;
loading_bar.setMin( 3 );
loading_bar.setMax ( 22 );
loading_bar.setStyle( "loader", "#" );
loading_bar.setBrackets( "[", "]" );
loading_bar.setMessage( "processing..." );

cout << "This is a normal loading bar: " << endl;
for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
 {
  sleep_for( milliseconds( 100 ) );
  loading_bar.update( i );
  //Do some operations...
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_loading.gif" width="400" height="60">

And customize it with messages and time-consuming info, like the previous percentage.

If using mixed bar styles, for example:
```c++
loading_bar.setStyle( "complete", "%#" );
```
you can create loading bar with percentage counter (mixed bar):

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/mixed_bar.gif" width="400" height="60">