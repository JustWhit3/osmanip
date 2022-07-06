<p align="center"><img src="https://github.com/JustWhit3/osmanip/blob/main/img/logo.svg" height=220></p>

<h3 align="center">A library used to manipulate the output stream of a program using ANSI escape sequences. </h3>
<p align="center">
  <img title="v4.0" alt="v4.0" src="https://img.shields.io/badge/version-v4.0-informational?style=flat-square">
  <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square"><br/>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/osmanip?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/osmanip?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/osmanip?color=red"></br>
  <img title="codeq" alt="codeq" src="https://github.com/JustWhit3/arsenalgear-cpp/actions/workflows/codeql-analysis.yml/badge.svg">
  <img title="doc" alt="doc" src="https://github.com/JustWhit3/arsenalgear-cpp/actions/workflows/DocGenerator.yml/badge.svg">
</p>

***

## Table of contents

- [Introduction](#introduction)
- [News from the latest releases](#news-from-the-latest-release)
- [List of features](#list-of-features)
  - [ANSI escape sequences manipulators](#ANSI-escape-sequences-manipulators)
  - [Progress bars](#progress-bars)
  - [Terminal graphics](#terminal-graphics)
  - [Extra support for UNICODE and ANSI on Windows](#extra-support-for-unicode-and-ansi-on-windows)
- [Install and use](#install-and-use)
  - [Install](#install)
  - [Use in your device](#use-in-your-device)
  - [Compile examples and test codes](#compile-examples-and-test-codes)
- [Useful scripts](#other-scripts)
- [Repository structure](#repository-structure)
- [Todo](#todo)
- [Credits](#credits)
  - [Project leaders](#project-leaders)
  - [Other contributors](#other-contributors)
  - [Other contributors with no GitHub account](#other-contributors-with-no-github-account)

## Introduction

*osmanip* is a C++ library containing useful tools to manipulate [ANSI escape sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) and customize the output stream of your programs. Within this tools you can add [colors and styles](ANSI escape sequences manipulators) to the printed strings, [change cursor location]((ANSI escape sequences manipulators)) on the terminal and manage other tools like [progress bars](#progress-bars) and [terminal graphics](#terminal-graphics). Using this features may be very useful to adorn your general output stream log or to perform cursor operations.

If you want to mention this software in one of your project / articles, please [cite it](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff).

If you want to contribute to the repository, please read [this](https://github.com/JustWhit3/osmanip/blob/main/CONTRIBUTING.md) file before.

Code documentation is generated using [*Doxygen*](https://www.doxygen.nl/manual/starting.html) and can be accessed [here](https://justwhit3.github.io/osmanip/). An extra [wiki](https://github.com/JustWhit3/osmanip/wiki) is also provided and contains how-to guides and many examples.

Colors and styles manipulators examples:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/csmanip_intro.gif"  width = "450">

Progress bars examples:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/progressbars_intro.gif" width = "450"> 

2D terminal-graphics examples:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/2Dgraphics_intro.gif" width = "450">

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

Supported operating systems

- **Linux**
  - *Ubuntu* (tested)
- **Windows** (release 10 or higher)
  - *Cygwin64* (tested)
  - *MSYS2* (tested)
  - *MinGW* (tested)
  - *WSL* (tested)
- **MacOS**

## News from the latest releases

- Added a [OS_Decorator](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/printer.hpp#:~:text=*/-,class%20OS_Decorator,-%7B) class to efficiently manage the output stream style of a program.
- Added the [Wiki](https://github.com/JustWhit3/osmanip/wiki) of the library.
- Added full support to **Windows** operating system.
- Added full support to **MacOS** operating system.

## List of features

### ANSI escape sequences manipulators

- [Color and style manipulation](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#colors-and-styles-manipulators) (list of all available colors and styles [here](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#colors-and-styles-manipulators))

```c++
#include <iostream>
#include <osmanip/manipulators/colsty.hpp>

// Print a red string
std::cout << osm::feat( osm::col, "red" ) << "This string is red!" << osm::reset( "color" );

// Print a bold string
std::cout << osm::feat( osm::sty, "red" ) << "This string is bold!" << osm::reset( "bd/ft" );
```

- [Cursor manipulators](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#cursor-manipulators)

```c++
#include <iostream>
#include <osmanip/manipulators/cursor.hpp>

// Move the cursor right by 2 spaces
std::cout << osm::feat( osm::crs, "right", 2 ) << "Cursor moved!";
```

- [Terminal control sequences](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#terminal-control-sequences) (list of all the available terminal control sequences [here](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#terminal-control-sequences))

```c++
#include <iostream>
#include <osmanip/manipulators/cursor.hpp>

// Output a bell sound
std::cout << osm::feat( osm::tcs, "bell" );
```

- [Additional functions](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#the-osmprint-function)

```c++
#include <iostream>
#include <osmanip/manipulators/printer.hpp>

// Similar to the Python "print" function
osm::print( std::cout, "This is the ", "\"print\" ", "function for the normal output stream! ", 100, "% working!" );
```

- [Class to manage output stream style of a program](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators#the-osmprint-function:~:text=osm%3A%3AOS_Decorator%20class-,Can%20be%20accessed%20with%3A,-%23include%20%3C)

```c++
#include <iostream>
#include <osmanip/manipulators/printer.hpp>

osm::OS_Decorator my_shell;

// Change std::cout predefined style and color
my_shell.setColor( "green", std::cout );
my_shell.setStyle( "underlined", std::cout );

my_shell( std::cout ) << "The stdout stream has been changed using the OS_Decorator class!" << "\n";

// Change std::cerr predefined style
my_shell.setColor( "red", std::cerr );
my_shell.setStyle( "bold", std::cerr );

my_shell( std::cerr ) << "The stderr stream has been changed using the OS_Decorator class!" << "\n";
```

More examples and how-to guides can be found [here](https://github.com/JustWhit3/osmanip/wiki/ANSI-escape-sequences-manipulators).

Why choosing this library for ANSI escape sequences manipulation:

- All the functions used to manipulate these sequences are very easy to use and don't require complex code signatures.
- All the most common ANSI sequences can be manipulated.
- Using the [OS_Decorator](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/printer.hpp#:~:text=*/-,class%20OS_Decorator,-%7B) class you can set the style of an output stream at the beginning of your program and keep it unchanged until the end.

### Progress bars

- [Percentage indicator](https://github.com/JustWhit3/osmanip/wiki/Progress-bars#percentage-indicator)

```c++
#include <iostream>
#include <osmanip/progressbar/progressbar.hpp>
#include <osmanip/utility/options.hpp>

osm::ProgressBar<int> percentage_bar;

percentage_bar.setMin( 5 );
percentage_bar.setMax ( 46 );
percentage_bar.setStyle( "indicator", "%" );

std::cout << "This is a normal percentage bar: " << "\n";
osm::OPTION( osm::CURSOR::OFF ); // Hide cursor for better output rendering
 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   percentage_bar.update( i );
   //Do some operations...
  }
osm::OPTION( osm::CURSOR::ON );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_percentage.gif" width="400">

- [Loading bar](https://github.com/JustWhit3/osmanip/wiki/Progress-bars#loading-bar)

```c++
#include <iostream>
#include <osmanip/progressbar/progressbar.hpp>
#include <osmanip/utility/options.hpp>

osm::ProgressBar<int> loading_bar( 3, 25 );

loading_bar.setStyle( "loader", "#" );
loading_bar.setBrackets( "{", "}" );
loading_bar.setMessage( "processing..." );

std::cout << "This is a normal loading bar: " << "\n";
osm::OPTION( osm::CURSOR::OFF ); // Hide cursor for better output rendering
for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
 {
  loading_bar.update( i );
  //Do some operations...
 }
osm::OPTION( osm::CURSOR::ON );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_loading.gif" width="400">

- [Progress bar](https://github.com/JustWhit3/osmanip/wiki/Progress-bars#full-progress-bar)

```c++
#include <iostream>
#include <osmanip/progressbar/progressbar.hpp>
#include <osmanip/utility/options.hpp>

osm::ProgressBar<int> progress_bar( 3, 25 );

progress_bar.setStyle( "complete", "%", "■" );
progress_bar.setBrackets( "[", "]" );
progress_bar.setMessage( "elaborating..." );
progress_bar.setRemainingTimeFlag( "on" );
progress_bar.setColor( "red" );

std::cout << "This is a mixed progress bar with color and time remaining info: " << "\n";
osm::OPTION( osm::CURSOR::OFF ); // Hide cursor for better output rendering
for ( int i = progress_bar.getMin(); i < progress_bar.getMax(); i++ )
 {
  progress_bar.update( i );
  //Do some operations...
 }
osm::OPTION( osm::CURSOR::ON );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/time_remaining.gif" width="700">

- [Progress spinner](https://github.com/JustWhit3/osmanip/wiki/Progress-bars#progress-spinner)

```C++
#include <iostream>
#include <osmanip/progressbar/progressbar.hpp>
#include <osmanip/utility/options.hpp>

osm::ProgressBar<int> spinner;

spinner.setMin( 2 );
spinner.setMax ( 33 );
spinner.setStyle( "spinner", "/-\\|" );

std::cout << "This is a progress spinner: " << "\n";
osm::OPTION( osm::CURSOR::OFF ); // Hide cursor for better output rendering
for ( int i = spinner.getMin(); i < spinner.getMax(); i++ )
 {
  spinner.update( i );
  //Do some operations...
 }
osm::OPTION( osm::CURSOR::ON );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/spinner.gif" width="550">

More examples and how-to guides can be found [here](https://github.com/JustWhit3/osmanip/wiki/Progress-bars).

Why choosing this library for progress bars? Some properties:

- Extremely easy to use.
- Compatible with positive or negative variable of any standard type (integer, float, double and others).
- Maximum and minimum values can be set with [any value](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use.md#:~:text=NOTE%3A%20you%20can%20insert%20each%20min%20and%20max%20value%20you%20prefer%2C%20like%20also%20%2D3%20and%2052%20for%20example%2C%20and%20the%20bar%20will%20work%20perfectly%20too.) you prefer and the progress bars will be self-built with respect to them.
- Each progress bar [feature](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use.md#:~:text=Type%3A%20percentage%20indicator,progress%20bars%20simultaneously.) can be fully customized (messages, style, color, brackets type, time remaining info etc...) regarding to your requirements. You can also choose to use only a progress indicator or a loading bar instead of a complete progress bar.
- It is thread-safe, hence you can use also [multiple progress bars](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use.md#:~:text=To%20add%20more%20progress%20bar%20simultaneously%20using%20threads%3A) simultaneously.

### Terminal graphics

- [Create animations](https://github.com/JustWhit3/osmanip/wiki/Terminal-graphics#canvases)

```C++
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/graphics/canvas.hpp>

osm::Canvas canvas(10,10);

canvas.setBackground( '.', osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
std::cout << "Display an animation in a canvas\n";

for( uint i = 0; i < 10; i++ )
 {
  canvas.clear();
  canvas.put( 0, 2, 'x' );
  canvas.put( i, 3, 'A', osm::feat( osm::col, "red" ) );
  canvas.put( 5, 0, 'B', osm::feat( osm::col, "blue" ) );
  canvas.put( 7, 8, 'Z', osm::feat( osm::col, "bg cyan" ) + osm::feat( osm::col, "black" ) + osm::feat( osm::sty, "bold" ) );
  canvas.refresh();
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_animation.gif" width="370">

- [2D graphics plots](https://github.com/JustWhit3/osmanip/wiki/Terminal-graphics#2D-graphics)

```C++
#include <functional>
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/graphics/canvas.hpp>

osm::Plot2DCanvas plot_2d_canvas( 50, 20 );

std::cout << "\n" << "Plot2DCanvas with sin and cos" << "\n";
plot_2d_canvas.setBackground( ' ', osm::feat( osm::col, "bg white" ) );
plot_2d_canvas.enableFrame( true );
plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
plot_2d_canvas.enableFrame( true );
plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
plot_2d_canvas.setScale( 1/3.14, 0.2) ;

for( float i = 0; i < 40; i++ )
 {
  plot_2d_canvas.setOffset( i/3.14, -2 );
  plot_2d_canvas.clear();
  plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                       float{ return std::cos( x ); } ), 'X', osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "bd red" ) );
  plot_2d_canvas.draw( std::function <float( float )>( []( float x ) -> 
                       float{ return std::sin( x ); } ), 'X', osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "bd blue" ) );
  plot_2d_canvas.refresh();
  sleep_for( milliseconds( 100 ) );
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/canvas_sincos.gif" width="370">

More examples and how-to guides can be found [here](https://github.com/JustWhit3/osmanip/wiki/Terminal-graphics).

Why choosing this library for terminal graphics:

- There are very few C++ libraries doing this job, and this is one of them.
- High level of customizability.
- A faster and most comfortable alternative to [plot simple functions](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use.md#:~:text=To%20plot%202D%20canvas%20with%20sin%20and%20cos%20functions%3A) without the needing of GUI.

### Extra support for UNICODE and ANSI on Windows

```c++
// Enable ANSI escape sequences
osm::OPTION( osm::ANSI::ON );
// doing some stuff...
osm::OPTION( osm::ANSI::ON );
```

```c++
// Enable unicode characters
osm::OPTION( osm::UNICODECH::ON );
// doing some stuff...
osm::OPTION( osm::UNICODECH::ON );
```

More examples and how-to guides can be found [here](https://github.com/JustWhit3/osmanip/wiki/Options).

## Install and use

### Install

Steps to be reproduced:

**1)** Download one of the [releases](https://github.com/JustWhit3/osmanip/releases) of the repository

**2)** Unzip and enter the downloaded repository directory

**3)** Install and compile the library and its dependencies with the installer script

```bash
./script/install.sh
```

This script supports the installation on Ubuntu, MacOS and Windows operating systems.

> **NOTE**: if you are on *Cygwin64* you may get an error related to the `\r` character. To solve it run the `dos2unix` command on the script (ex: `dos2unix install.sh`) before running it.

A new library *libosmanip.a* will be created into the `/usr/lib` folder of your computer and the [*header*](https://github.com/JustWhit3/osmanip/blob/main/include) files will be installed into `/usr/include` path.
> **NOTE**: if you are on MacOS or Windows the paths are slightly different (looks at [install.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh)).

Mandatory prerequisites (automatically installed with the script):

- C++17 standard.
- g++ compiler (g++ 9.3.0 has been tested so far) for compilation.
- [GNU make](https://www.opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners/#:~:text=Installing%20GNU%20Make,install%20build%2Dessential.) for compilation.
- [Boost](https://www.boost.org/) library.
- [arsenalgear](https://github.com/JustWhit3/arsenalgear-cpp) library.

**Optional** prerequisites for developers:

- [Valgrind](https://valgrind.org/) to run the [debug.sh](#debugsh) script.
- [Cppcheck](https://github.com/danmar/cppcheck) to run the [debug.sh](#debugsh) script.
- [Clang formatter](https://stackoverflow.com/questions/20756924/how-can-i-install-clang-format-in-ubuntu#:~:text=16.04%2C%20simply%20do%3A-,sudo%20apt%20install%20clang%2Dformat,-Share) to format the code for pull requests.
- [wget](https://www.techwalla.com/articles/how-to-install-wget-in-ubuntu) to download extra dependencies repositories.
- [unzip](https://www.mysoftkey.com/linux/how-to-do-zip-and-unzip-file-in-ubuntu-linux/) to unzip zipped directories during download and installation.
- [Doxygen](https://www.doxygen.nl/manual/starting.html) for documentation generation while developing.
- [doctest](https://github.com/onqtam/doctest) for testing.
- [hurry.filesize](https://pypi.org/project/hurry.filesize/) for `size_of_dir.py` script.
- [termcolor](https://pypi.org/project/termcolor/) for `size_of_dir.py` script.

4) **EXTRA**: to update the repository after some time

```shell
./scripts/update.sh
./scripts/install.sh
```

5) **EXTRA**: to uninstall the repository from the system

```shell
./scripts/uninstall.sh
```

### Use in your device

Tu use on or more headers of the library:

```c++
#include <osmanip/module_folder/module_name.hpp>
```

If you are using the library in a program, add the `-losmanip` flag to link [source](https://github.com/JustWhit3/osmanip/tree/main/src) code.

> **NOTE**: remember also to add `-pthread` flag if you want to use some thread-dependent libraries like [**progressbar/multi_progress_bar.hpp**](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar/multi_progress_bar.hpp).

### Compile examples and test codes

To compile example codes:

```shell
make main
```

To run all examples:

```shell
./bin/manipulators
./bin/progressbar
./bin/graphics
```

> **NOTE**: executables end with `.exe` if you are on Windows of course.

To compile tests:

```shell
make tests
```

To run tests:

```shell
./bin/tests
```

> **NOTE**: executables end with `.exe` if you are on Windows of course.

There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:

```shell
make clean
```

## Useful scripts

Other scripts have been provided into the [**scripts**](https://github.com/JustWhit3/osmanip/blob/main/scripts) folder. After compiling the source code, they can be run from the repository home directory.

The `debug.sh` script is used to run [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) debugging tools on the whole code.

You can run Valgrind debugging tools with a specific executable:

```shell
./scripts/debug_cpp.sh [valgrind-tool-name] [executable-name]
```

## Repository structure

```txt
osmanip/
├── .github/
│   ├── workflows/
│   │   ├── DocGenerator.yml
│   │   ├── codeql-analysis.yml
├── img/
├── include/
│   ├── graphics/
│   │   ├── canvas.hpp
│   │   ├── plot_2D.hpp
│   ├── manipulators/
│   │   ├── colsty.hpp
│   │   ├── cursor.hpp
│   │   ├── common.hpp
│   │   ├── printer.hpp
│   ├── progressbar/
│   │   ├── progress_bar.hpp
│   │   ├── multi_progress_bar.hpp
│   ├── utility/
│   │   ├── windows.hpp
│   │   ├── options.hpp
├── src/
│   ├── graphics/
│   │   ├── canvas.cpp
│   │   ├── plot_2D.cpp
│   ├── manipulators/
│   │   ├── colsty.cpp
│   │   ├── cursor.cpp
│   │   ├── common.cpp
│   │   ├── printer.hpp
│   ├── progressbar/
│   │   ├── progress_bar.cpp
│   │   ├── multi_progress_bar.cpp
│   ├── utility/
│   │   ├── windows.cpp
├── examples/
│   ├── manipulators.cpp
│   ├── progressbar.cpp
│   ├── graphics.cpp
├── scripts/
│   ├── debug.sh
│   ├── install.sh
│   ├── uninstall.sh
│   ├── update.sh
│   ├── size_of_dir.py
├── test/
│   ├── graphics/
│   │   ├── tests_canvas.cpp
│   │   ├── tests_plot_2D.cpp
│   ├── manipulators/
│   │   ├── tests_common.cpp
│   │   ├── tests_colsty.cpp
│   │   ├── tests_cursor.cpp
│   │   ├── tests_printer.cpp
│   ├── progressbar/
│   │   ├── tests_progress_bar.cpp
│   │   ├── tests_multi_progress_bar.cpp
│── README.md
│── CONTRIBUTING.md
│── LICENSE
│── CITATION.cff
│── Makefile
│── Doxyfile
│── .gitignore
│── .clang-format
│── .valgrindrc
│── .gitignore
│── .all-contributorsrc
```

## Todo

**ANSI escape sequences manipulators**

- Add UNICODE characters manipulators.
- Add new methods to the [`OS_decorator`](https://github.com/JustWhit3/osmanip/blob/main/include/manipulators/printer.hpp#:~:text=*/-,class%20OS_Decorator,-%7B) class.
- Implement file redirection when manipulating the output.

**Progress bars**

- Add an `elapsedTime()` method to show elapsed progress bar time and substitute it to the already existing  `getTime()` method.

**Terminal graphics**

- Add a method to set the Legend of a plot.
- Add automatic plot resize.
- Add option to display axes.
- Extend the 2D terminal-graphics to 3D.

**System features**

- Improve the compilation using CMake.
- Benchmarking and other studies with respect to similar libraries.

## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

### Other contributors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://miguelmj.github.io/"><img src="https://avatars.githubusercontent.com/u/37369782?v=4" width="100px;" alt=""/><br /><sub><b>MiguelMJ</b></sub></a></td>
    <td align="center"><a href="https://github.com/TedLyngmo"><img src="https://avatars.githubusercontent.com/u/2361158?v=4" width="100px;" alt=""/><br /><sub><b>Ted Lyngmo</b></sub></a></td>
    <td align="center"><a href="https://github.com/myermo"><img src="https://avatars.githubusercontent.com/u/93035284?v=4" width="100px;" alt=""/><br /><sub><b>myermo</b></sub></a></td>
    <td align="center"><a href="http://nickb.website"><img src="https://avatars.githubusercontent.com/u/25168557?v=4" width="100px;" alt=""/><br /><sub><b>nick-botticelli</b></sub></a></td>
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

### Other contributors with no GitHub account

- [StoryTeller](https://stackoverflow.com/users/817643/storyteller-unslander-monica)
