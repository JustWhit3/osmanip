# osmanip

## Table of contents
- [Introdutction](#introdutction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
  * [Compile and run](#compile-and-run)
- [List of features](#list-of-features)

## Introdutction

Here I want to present you my personal output-stream manipulator, called *osmanip*. Probably there are already some similar libraries/manipulators/classes in the web that do the same work, but since I personally don't like them at all I preferred writing my own manipulator, in order to deal with different color and styles in the output stream of any program that I usually write. Using different features for the output stream may be very useful to better read error messages or special informations you want to be sure an user see when he runs the code, or to do many other useful procedures to adorn your general output stream.

## Description of the repository

Excluding this README.md file and the [**License**](https://github.com/JustWhit3/osmanip/blob/main/License), the repository contains two directories:
- [**osmanip**](https://github.com/JustWhit3/osmanip/tree/main/osmanip): which contains two subdirectories:
  * [**include**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/include): which contains the manipulator declaration file [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/include/osmanip.h).
  * [**src**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/src): which contains the manipulator definition file [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/src/osmanip.cpp).
- [**main**](https://github.com/JustWhit3/osmanip/tree/main/main): which contains the main code [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp), which shows an example of the manipolator utility, and a [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) for compilation.

Detailed information about variables and functions utility can be seen in the manipulator declaration and definition files, since for each passaga a proper comment has been added before the command lines.

Note: the structure of the repository may seems more complex than what is needed since there are many subdirectories and a makefile for compilation that may be avoided in this case, due to the simplicity of the code structure, however I usually prefer using this structure in all my projects since it is for me the basic structure I use for any C++ code/project. Therefore is is just a matter of conventions.

## Run the code

### Download

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/osmanip) of the repository and click on the upper right green button *Code*. Than click on *Download ZIP* and wait the download to be completed.

Then open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/osmanip $HOME
```
Where *Downloads* have to be replaced with the right name (and maybe the right path) of your downloads folder. And then enter your home folder:
```shell
cd $HOME
```
Now you have to extract the folder from the zipped file and renaming itself with its right repository name by typing this two commands one after the other:
```shell
unzip osmanip-main.zip
mv osmanip-main osmanip
```
And that's all. You can enter the folder by typing:
```shell
cd osmanip
```

### Compile and run

For the compilation part I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile), in order to make easier this procedure. Therefore you have to simply enter the **main** folder and run the makefile by typing:
```shell
cd main
make
```
An executable file called *main* is now created and to run the code you have to simply type:
```shell
./main
```

## List of features

List all the colors and styles supported at the moment. Put screenshot.

