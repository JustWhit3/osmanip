# osmanip

## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
  * [Compile and run](#compile-and-run)
- [How does osmanip work](#how-does-osmanip-work)
  * [Include the library](#include-the-library)
  * [Functions and variables](#functions-and-variables)
- [List of features](#list-of-features)
- [List of future implementations](#list-of-future-implementations)

## Introduction

Here I want to present you my personal C++ output-stream manipulator, called *osmanip*. Probably there are already some similar libraries/manipulators/classes in the web that do the same work, but since I personally don't like them at all I preferred writing my own manipulator, in order to deal with different colors, styles and much more in the output stream of any program that I usually write. Using different features for the output stream may be very useful to better read error messages or special information you want to be sure other users see when they run a certain code, or to do many other useful procedures to adorn your general output stream.

## Description of the repository

Excluding this README.md file, the [*License*](https://github.com/JustWhit3/osmanip/blob/main/License) file, the [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore) file and the [**img**](https://github.com/JustWhit3/osmanip/tree/main/img) folder (which contains images for the README.md), the repository contains two directories:
- [**include**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/include): which contains the manipulator declaration file [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/include/osmanip.h).
- [**src**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/src): which contains two .cpp files:
  * [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/src/osmanip.cpp): which is the manipulator definition file.
  * [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp): which shows you an example of the manipulator utility.

There is also a [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) for code compilation.

> **Note**
> 
>The structure of the repository may seems more complex than what is needed, since there are many 
>subdirectories and a makefile for compilation, that can be avoided in this case, due to the 
> simplicity of the code structure, however I usually prefer keeping this structure in all 
> my projects. Therefore is is just a matter of conventions.

## Run the code

### Download

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/osmanip) of the repository and click on the upper right green button called `Code`. Than click on `Download ZIP` and wait the download to be completed.

Then open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/osmanip-main.zip $HOME
```
Where ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip osmanip-main.zip
mv osmanip-main osmanip
```
And that's all. You can enter the folder by simply typing:
```shell
cd osmanip
```

### Compile and run

Now, let's suppose to continue from the previous step. For the compilation part I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile), in order to simplify this procedure. So you have to enter the [**main**](https://github.com/JustWhit3/osmanip/tree/main/main) folder and run the [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) by typing:
```shell
cd main
make
```
An extra **src** folder with object files and an executable called *main* are now created: you have simply to run this latter in order to run the entire example code:
```shell
./main
```
There is also an option to go back to the pre-compilation state of the code, to do this simply type this command where you are in the **main** folder:
```shell
make clean
```

## How does osmanip work

### Include the library

Once you have added the manipulator declaration and definition to one of your project, you may want to be able to use it freely in your code. In order to let it works you have to include it at the beginning of a code in this way:
```c++
#include "path/to/osmanip/osmanip.h"
```
Where `path/to/osmanip/` is the path to the directory in which you put the osmanip manipulator. If you put the manipulator in the same folder of the project you are working with you have simply to do:
```c++
#include "osmanip.h"
```
In this latter case you can omit the full path. 
> Remember to do this also in [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/src/osmanip.cpp) 
> and in your makefile or maybe set this latter in order to avoid this path dependence.

Now you are able to access al the functions of the manipulator. 

### Functions and variables

Each function has to be placed after the `<<` operator, in order to change the output stream until the `reset()` function is met. This is the list of the currently defined functions:
- `string color (string color_string)`: which returns a string and is used to set the color of the output stream by giving the color name to its argument.
- `hl_color (string hl_color_string)`: which returns a string and is used to set the highlight color of the output stream by giving the highlight color name to its argument.
- `style (string style_string)`: which returns a string and is used to set the style of the output stream by giving the style name to its argument.
- `reset ();`: which doesn't return anything and is used to reset the style of the output stream.

THis is the list of the currently defined color / style variables you can pass to the previously defined functions:
- For the `color` function: `black`, `red`, `green`, `orange`, `blue`, `magenta`, `cyan` and `white`.
- For the `hl_color` function: `hl_green_1`, `hl_green_2`, `hl_green_3`, `hl_red`, `hl_yellow`, `hl_cyan`, `hl_grey` and `hl_white`.
- For the `style` function: `bold`, `transparent`, `italics`, `underlined`, `highlighted`, `invisible` and `striped`.

THerefore, if you want to change, for example, the output stream color into red you can do this:
```c++
cout << color ("red") << "This stream is red!" << reset ();
```
It will color the output stream in red until you put the `reset ()` function which resets the output stream style to the original one.

## List of features

Here you can find a screenshot of the output stream of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp) program which shows you all the features supported in the current version of the manipulator:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

## List of future implementations

Here a list of implementations I planned for future developments:

- Bold, bright and background output colors.
- Cursor navigation.
- Progress indicator (percentage that loads).
- ASCII progress bar (and maybe also multiple loading bars).


