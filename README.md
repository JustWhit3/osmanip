# osmanip

## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
    * [Download the whole repository](#download-the-whole-repository)
    * [Download the latest release](#download-the-latest-release)
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

To download the manipulator you can proceed in two independent ways.

#### Download the whole repository

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

#### Download the latest release

Alternatively you can download the last version of the repository from the ``Releases`` button on the right of the repository main page. In this case the procedure is similar:

Open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/osmanip-x.y.z.zip $HOME
```
Where `x.y.z` is the release tag and ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip osmanip-x.y.z.zip
mv osmanip-x.y.z osmanip
```

> If you prefer to download the tar.gz format of the release you have to run the `gunzip` command followed by the `tar -xvf` command and than proceed with `mv`. 

And that's all. You can enter the folder by simply typing:
```shell
cd osmanip
```

### Compile and run

Now, let's su> ppose to continue from the previous step. For the compilation part I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile), in order to simplify this procedure. So you have to enter the [**main**](https://github.com/JustWhit3/osmanip/tree/main/main) folder and run the [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) by typing:
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

> **Note**
> If you want to keep the manipulator only, in order to use it in one of your projects, you can delete the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp) and the [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) files.

### Functions and variables

List of the currently defined functions:
- `std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat )`: which takes an `std::map` object as the first argument and an `std::string` object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.

List of the currently defined std::map objects:
- `std::map <std::string, std::string> col`: which is used for the color features and currently supports the following list of colors (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted color is not supported!\n`
  * `reset` / `\033[0m`
  * `black` / `\033[30m`
  * `red` / `\033[31m`
  * `green` / `\033[32m`
  * `orange` / `\033[33m`
  * `blue` / `\033[34m`
  * `magenta` / `\033[35m`
  * `cyan` / `\033[36m`
  * `white` / `\033[37m`
  * `bg green 1` / `\033[40m`
  * `bg red` / `\033[41m`
  * `bg green 2` / `\033[42m`
  * `bg yellow` / `\033[43m`
  * `bg cyan` / `\033[44m`
  * `bg grey` / `\033[45m`
  * `bg green 3` / `\033[46m`
  * `bg white` / `\033[47m`

> **Note**
> "bg" is the prefix of the background color features.

- `std::map <std::string, std::string> sty`: which is used for the style features and currently supports the following list of styles (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted color is not supported!\n`
  * `reset` / `\033[0m`
  * `bold` / `\033[1m`
  * `faint` / `\033[2m`
  * `italics` / `\033[3m`
  * `underlined` / `\033[4m`
  * `highlighted` / `\033[7m`
  * `invisible` / `\033[8m`
  * `striped` / `\033[9m`

THerefore, if you want to change, for example, the output stream color into red you have to call the `feat` function and give it the `col` map as a first argument and the color name as the second one. See the following example:
```c++
cout << feat( col, "red" ) << "This stream is red!" << feat( col, "reset" );
```
This will color the output stream in red until the `feat( col, "reset" )` function is met again, but with the `reset` key as the second argument, in ordert to reset the output stream style.

Along with each function, at the end of the [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/src/osmanip.cpp) file, test functions have been produced in order to test the correct output of each function. The list of the currently defined test functions is the following:
- `void feat_test( std::map <std::string, std::string> & generic_map_test );`: which tests the correct functionality of the `feat` function.

## List of features

Here you can find a screenshot of the output stream of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp) program which shows you all the features supported in the current version of the manipulator:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

## List of future implementations

Here a list of implementations I planned for future developments:

- Bold, bright and background output colors.
- Cursor navigation.
- Progress indicator (percentage that loads).
- ASCII progress bar (and maybe also multiple loading bars).


