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
- [**include**](https://github.com/JustWhit3/osmanip/tree/main/include): which contains the manipulator declaration file [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.h).
- [**src**](https://github.com/JustWhit3/osmanip/tree/main/src): which contains two .cpp files:
  * [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp): which is the manipulator definition file.
  * [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp): which shows you an example of the manipulator utility.

There is also a [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile) for code compilation.

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

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link. In this case the procedure is similar:

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

> If you prefer to download the tar.gz format of the release you have to run the `gunzip` command followed by the `tar -xvf` command on the zipped release folder and than proceed with `mv`. 

And that's all. You can enter the folder by simply typing:
```shell
cd osmanip
```

### Compile and run

Now, let's supppose to continue from the previous step. For the compilation part I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/makefile), in order to simplify this procedure. So you can run it by simply typing:
```shell
make
```
An extra **obj** folder with object files and an executable called *main* are now created: you have simply to run this latter in order to run the entire example code:
```shell
./main
```
There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:
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
> Remember to do this also in [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp) 
> and in your makefile or maybe set this latter in order to avoid this path dependence.

Now you are able to access al the functions of the manipulator. 

> **Note**
> If you want to keep the manipulator only, in order to use it in one of your projects, you can delete the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main.cpp) and the [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile) files.

### Functions and variables

List of the currently defined functions:
- `std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string )`: which takes an `std::map` object as the first argument and an `std::string` object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.
- `std::string reset ( std::string reset_string )`: which takes a `std::string` object (`reset` map key) as argument and returns the interested color / style reset string by returning the map value from the corresponding key.

List of the currently defined std::map objects:
- `std::map <std::string, std::string> col`: which is used for the color features and currently supports the following list of colors (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
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

- `std::map <std::string, std::string> sty`: which is used for the style features and currently supports the following list of styles (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
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
  
- `std::map <std::string, std::string> rst`: which is used to reset features and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
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
  
- `std::map <std::string, std::string> crs`: which is used for the cursor naviagation features and currently supports the following list of commands (first `std::string`) with the corresponding ASCII code (second `std::string`) or string value in the case of the `error` feature: 
  * `error` / `Inserted cursor command`
  * `up` / \ `u001b[A`
  * `down` / `\u001b[B`
  * `right` / `\u001b[C`
  * `left` / `\u001b[D`

Therefore, if you want to change, for example, the output stream color into red you have to call the `feat` function and give it the `col` map as a first argument and the color name as the second one. See the following example:
```c++
cout << feat( col, "red" ) << "This stream is red!" << reset( "color" );
```
This will color the output stream in red until the `reset( "color" )` function is met again, in ordert to reset the output stream color.

You can also print mixed color and styles strings:
```c++
cout << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" );
```
This will underline and color the output stream in red until the `reset( "all" )` function is met again, in ordert to reset all the output stream color / style.

Along with each function, at the end of the [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp) file, test functions have been produced in order to test the correct output of each function. The list of the currently defined test functions is the following:
- `void feat_test( std::map <std::string, std::string> & generic_map_test );`: which tests the correct functionality of the `feat` function.
- `void reset_test();`: which tests the correct functionality of the `reset` function.

## List of features

Here you can find a screenshot of the output stream of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main.cpp) program which shows you all the features supported in the current version of the manipulator:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

## List of future implementations

Here a list of implementations I planned for future developments:

- Cursor navigation.
- Progress indicator (percentage that loads).
- ASCII progress bar (and maybe also multiple loading bars).


