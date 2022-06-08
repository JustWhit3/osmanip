<p align="center"><img src="https://github.com/JustWhit3/osmanip/blob/main/img/logo.svg" height=220></p>

<h3 align="center">Library with useful output stream tools like: color and style manipulators, progress bars and terminal graphics</h3>
<p align="center">
  <img title="v3.0" alt="v3.0" src="https://img.shields.io/badge/version-v3.0-informational?style=flat-square">
  <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square"><br/>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/osmanip?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/osmanip?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/osmanip?color=red">
</p>

***

## Table of contents

- [Introduction](#introduction)
- [Documentation](#documentation)
- [Repository structure](#repository-structure)
- [News from the last version](#news-from-the-last-version)
- [List of features](#list-of-features)
- [Credits](#credits)
  - [Project leaders](#project-leaders)
  - [Other contributors](#other-contributors)
  - [Other contributors with no GitHub account](#other-contributors-with-no-github-account)


## Introduction

*osmanip* is a C++ library containing useful tools to customize the output stream of your programs. Within this tools you can manipulate an output stream with colors, styles (ex: bold, italics, etc...) and manage other tools like progress bars and terminal graphics. You can also manipulate ANSI escape sequences / codes, with proper functions provided by the library. Using this features may be very useful to better read error messages or special information you want to be sure other users see when they run your code, or to adorn your general output stream log.

If you want to use this software in one of your project, please cite it. You can find the citation template [here](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff).
> **NOTE**: all the manipulators of this library are compatible with [iomanip](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/iomanip).

> **NOTE 2**: this library doesn't make use of any GUI.

Example output of the [*examples*](https://github.com/JustWhit3/osmanip/blob/main/examples) folder programs:

Colors and styles manipulators

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/csmanip_intro.gif"  width = "450">

Progress bars

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/progressbars_intro.gif" width = "450"> 

2D terminal-graphics

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/2Dgraphics_intro.gif" width = "450">

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

Supported and tested operating systems:

- Ubuntu (and the other Linux OSs).
- Windows Subsystem for Linux (WSL).

## Documentation

In the [**doc**](https://github.com/JustWhit3/osmanip/blob/main/doc) folder useful documentation files are stored, in order to help the user learning how to properly use the library:
- [*Download and install*](https://github.com/JustWhit3/osmanip/blob/main/doc/Download%20and%20install.md): a guide to download, install and run the library into your system.
- [*Contributing*](https://github.com/JustWhit3/osmanip/blob/main/doc/Contributing.md): if you want to contribute to the development of this library or you want to raise an issue, please carefully read this document before.
- [*Todo*](https://github.com/JustWhit3/osmanip/blob/main/doc/Todo.md): contains a list of future implementations of the library.
- [*How-to-use guides*](https://github.com/JustWhit3/Ostream-manipulator/blob/main/doc/How-to-use%20guides.md): contains a set of guides about how to use the library tools.

**Code documentation** is generated using [*Doxygen*](https://www.doxygen.nl/manual/starting.html) and can be accessed [here](https://justwhit3.github.io/osmanip/).

## Repository structure

```
osmanip/
├── .github/
│   ├── workflows/
│   │   ├── DocGenerator.yml
├── img/
├── doc/
│   ├── Contributing.md
│   ├── Download and install.md
│   ├── Todo.md
│   ├── How-to-use guides.md
├── include/
│   ├── graphics/
│   │   ├── canvas.hpp
│   │   ├── plot_2D.hpp
│   ├── manipulators/
│   │   ├── csmanip.hpp
│   ├── progressbar/
│   │   ├── progress_bar.hpp
│   │   ├── multi_progress_bar.hpp
├── src/
│   ├── graphics/
│   │   ├── canvas.cpp
│   │   ├── plot_2D.cpp
│   ├── manipulators/
│   │   ├── csmanip.cpp
│   ├── progressbar/
│   │   ├── progress_bar.cpp
│   │   ├── multi_progress_bar.cpp
├── examples/
│   ├── manipulators.cpp
│   ├── progressbar.cpp
│   ├── graphics.cpp
├── scripts/
│   ├── debug.sh
│   ├── install.sh
│   ├── uninstall.sh
│   ├── update.sh
│   ├── size_of_dir.sh
├── test/
│   ├── graphics/
│   │   ├── tests_canvas.cpp
│   │   ├── tests_plot_2D.cpp
│   ├── manipulators/
│   │   ├── tests_csmanip.cpp
│   ├── progressbar/
│   │   ├── tests_progress_bar.cpp
│   │   ├── tests_multi_progress_bar.cpp
│── README.md
│── License
│── CITATION.cff
│── Makefile
│── Doxyfile
│── .gitignore
│── .clang-format
│── .valgrindrc
│── .gitignore
│── .all-contributorsrc
```

## News from the last version

Most recent relevant news from the last version:

- A new feature to plot 2D graphics and functions in the terminal has been added.
- Progress spinner has been added to the `ProgressBar` class.
- New features have been added to the progress bar: time-reamining info.
- Added a new map for the `feat` function to deal with clear screen / line commands.
- Added a new `print` function inspired by the Python one.

## List of features

Here you can find the list of features implemented in the current version of the library:

- **Output stream manipulators** for:
  - [Color and style manipulation](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=of%20a%20program.-,Colors%20and%20styles%20manipulation,-List%20of%20the)
  - [Cursor navigation](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=reset%20commands%20here.-,Cursor%20navigation,-You%20can%20modify)
  - [Terminal control sequences](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=for%20more%20information.-,Terminal%20control%20sequences,-You%20can%20add)
  - [Additional functions](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=understand%20their%20usage.-,Extra%20functions%20(print%20and%20others),-Some%20extra%20functions) (like an own version of the Python print one).
- **Progress indicators**:
  - [Percentage indicator](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=to%20restore%20it.-,Percentage%20indicator,-Initialize%20and%20use)
  - [Loading bar](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=Do%20some%20operations...%0A%7D-,Loading%20bar,-You%20can%20also)
  - [Progress bar](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=the%20previous%20percentage.-,Full%20progress%20bar,-You%20can%20create)
  - [Progress spinner](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=endl%20%3C%3C%20endl%20%3C%3C%20endl%3B-,Progress%20spinner,-To%20initialize%20a)
- **Terminal graphics**:
  - [2D graphics](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=to%20restore%20it.-,2D%20graphics,-To%20include%20canvas)

Why choosing this library for color / styles / escape sequences manipulation:

- All the functions used to manipulate these sequences are [very easy to use](https://github.com/JustWhit3/osmanip/blob/main/examples/manipulators.cpp) and don't require complex code signatures.
- All the most common ANSI sequences can be manipulated.
  
Why choosing this library for progress bars? Some properties:

- Extremely [easy to use](https://github.com/JustWhit3/osmanip/blob/main/examples/manipulators.cpp).
- Compatible with positive or negative variable of any standard type (integer, float, double and others).
- Maximum and minimum values can be set with [any value](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=NOTE%3A%20you%20can%20insert%20each%20min%20and%20max%20value%20you%20prefer%2C%20like%20also%20%2D3%20and%2052%20for%20example%2C%20and%20the%20bar%20will%20work%20perfectly%20too.) you prefer and the progress bars will be self-built with respect to them.
- Each progress bar [feature](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=Type%3A%20percentage%20indicator,progress%20bars%20simultaneously.) can be fully customized (messages, style, color, brackets type, time remaining info etc...) regarding to your requirements. You can also choose to use only a progress indicator or a loading bar instead of a complete progress bar.
- It is thread-safe, hence you can use also [multiple progress bars](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=To%20add%20more%20progress%20bar%20simultaneously%20using%20threads%3A) simultaneously.

Why choosing this library for terminal graphics:

- There are very few C++ libraries doing this job, and this is one of them.
- High level of customizability.
- A faster and most comfortable alternative to [plot simple functions](https://github.com/JustWhit3/osmanip/blob/main/doc/How-to-use%20guides.md#:~:text=To%20plot%202D%20canvas%20with%20sin%20and%20cos%20functions%3A) without the needing of GUI.

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
