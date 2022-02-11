<p align="center"><img src="https://github.com/JustWhit3/osmanip/blob/main/img/logo.svg" height=220></p>

<h3 align="center">Library with output stream tools like: colors and styles manipulators and progress bars</h3>
<p align="center">
    <img title="v2.5" alt="v2.5" src="https://img.shields.io/badge/version-v2.5-informational?style=flat-square"
    <a href="LICENSE">
        <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
    </a>
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square"><br>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/osmanip?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/osmanip?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/osmanip?color=red">

***

## Table of contents

- [Introduction](#introduction)
- [Documentation](#documentation)
- [List of features](#list-of-features)
- [Credits](#credits)
  - [Project leaders](#project-leaders)
  - [Other contributors](#other-contributors)

## Introduction

Here I want to present you *osmanip*: my personal C++ library containing useful output-stream tools to customize your output stream. Probably there are already some similar libraries in the web that do the same job, but since I personally don't like them at all I preferred writing my own code for that. Thanks to this you can manipulate the output stream of your program with colors, styles (ex: bold, italics, etc...) and helper tools like progress bars and CPU-usage monitor objects. You can also manipulate ANSI escape sequences / codes, with proper functions provided by the library. Using this feaures may be very useful to better read error messages or special information you want to be sure other users see when they run your code, or to adorn your general output stream log.

This software has been built for Linux systems (it has been tested with Ubuntu and WSL). Its compatibility has not been tested with Windows or MacOS operating systems.

If you want to use this software in one of your project, please cite it. You can find the citation template [here](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff).
> **NOTE**: all the manipulators of this library are compatible with [iomanip](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/iomanip).

> **NOTE 2**: this library doesn't make use of any GUI.

Example output of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) program demo:

<p float="left">
  <img src="https://github.com/JustWhit3/osmanip/blob/main/img/csmanip_intro.gif"  width = "360">
  <img src="https://github.com/JustWhit3/osmanip/blob/main/img/progressbars_intro.gif" width = "450"> 
</p>

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

## Documentation

In the [**doc**](https://github.com/JustWhit3/osmanip/blob/main/doc) folder useful documentation files are stored, in order to help the user learning how to properly use the library:
- [*Repository structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Repository%20structure.md): contains general information about the files and folders of the repository.
- [*Code structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md): contains general information about the code structure of the library, therefore details on classes, functions and variables used in it.
- [*Download and install*](https://github.com/JustWhit3/osmanip/blob/main/doc/Download%20and%20install.md): a guide to download, install and run the library into your system.
- [*Contributing*](https://github.com/JustWhit3/osmanip/blob/main/doc/CONTRIBUTING.md): if you want to contribute to the development of this library or you want to raise an issue, please carefully read this document before.
- [*Todo*](https://github.com/JustWhit3/osmanip/blob/main/doc/Todo.md): contains a list of future implementations of the library.
- [*How-to-use guides*](https://github.com/JustWhit3/Ostream-manipulator/blob/main/doc/How-to-use%20guides.md): contains a set of guides about how to use the library tools.

## List of features

Here you can find the list of features implemented in the current version of the library:

- **Output stream manipulators** for:
  - Color and style manipulation
  - Cursor navigation
  - Terminal control sequences
- **Progress indicators**:
  - Percentage indicator
  - Loading bar
  - Progress bar
  - Progress spinner

Why choosing this library for progress bars? Some properties:

- Extremely easy to use.
- Compatible with positive or negative variable of any standard type (integer, float, double and others).
- Maximum and minimum values can be set with any value you prefer and the progress bars will be self-built with respect to them.
- Each progress bar feature can be fully customized (messages, style, color, brackets type, time remaining info etc...) regarding to your requirements. You can also choose to use only a progress indicator or a loading bar instead of a complete progress bar.
- It is thread-safe, hence you can use also multiple progress bars simultaneously.


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
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->