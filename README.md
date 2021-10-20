# osmanip

## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
  * [Compile and run](#compile-and-run)
- [List of features](#list-of-features)

## Introduction

Here I want to present you my personal C++ output-stream manipulator, called *osmanip*. Probably there are already some similar libraries/manipulators/classes in the web that do the same work, but since I personally don't like them at all I preferred writing my own manipulator, in order to deal with different colors and styles in the output stream of any program that I usually write. Using different features for the output stream may be very useful to better read error messages or special information you want to be sure other users see when they run a certain code, or to do many other useful procedures to adorn your general output stream.

## Description of the repository

Excluding this README.md file, the [*License*](https://github.com/JustWhit3/osmanip/blob/main/License) file, the [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore) file and the [**img**](https://github.com/JustWhit3/osmanip/tree/main/img) folder (which contains images for the README.md), the repository contains two directories:
- [**osmanip**](https://github.com/JustWhit3/osmanip/tree/main/osmanip): which contains two subdirectories:
  * [**include**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/include): which contains the manipulator declaration file [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/include/osmanip.h).
  * [**src**](https://github.com/JustWhit3/osmanip/tree/main/osmanip/src): which contains the manipulator definition file [*osmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/osmanip/src/osmanip.cpp).
- [**main**](https://github.com/JustWhit3/osmanip/tree/main/main): which contains the main code [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp), which shows you an example of the manipulator utility and a [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) for code compilation.

Detailed information about variables and functions utility can be seen in the manipulator declaration and definition files, since for each passage a proper comment has been added before several command lines.

Note: the structure of the repository may seems more complex than what is needed, since there are many subdirectories and a makefile for compilation, that can be avoided in this case, due to the simplicity of the code structure, however I usually prefer keeping this structure in all my projects. Therefore is is just a matter of conventions.

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

Now, let's suppose to continue from the previous step. For the compilation part I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile), in order to simplify this procedure. So you have to enter the [**main**]((https://github.com/JustWhit3/osmanip/tree/main/main) folder and run the [makefile](https://github.com/JustWhit3/osmanip/blob/main/main/makefile) by typing:
```shell
cd main
make
```
An executable file called *main* is now created and you have simply to run it in order to run the entire code:
```shell
./main
```
There is also an option to go back to the pre-compilation state of the code, to do this simply type this command where you are in the **main** folder:
```shell
make clean
```

## List of features

Here you can find a screenshot of the output stream of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/main/main.cpp) program which shows you all the features supported in the current version of the manipulator:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

