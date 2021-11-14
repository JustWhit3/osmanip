# Download and install

## Table of contents
- [Download](#download)
  * [Download the whole repository](#download-the-whole-repository)
  * [Download the latest release](#download-the-latest-release)
- [Install](#install)
- [Compile and run](#compile-and-run)
- [Compile the source code example and testing](#compile-the-source-code-example-and-testing)

## Download 

To download the library you can proceed in two independent ways.

### Download the whole repository

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

### Download the latest release

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

## Install

From release [2.1.0](https://github.com/JustWhit3/osmanip/releases/tag/v2.1.0) an installer script, called [install.sh](https://github.com/JustWhit3/osmanip/blob/main/install.sh), has been introduced. This script can be used to properly install the library into your computer, in order to easily use it in your programs.

Installation prerequisites: g++ compiler (g++ 9.3.0 has been tested so far).

Operating systems compatibility: Ubuntu and WSL.

Once the source code has been downloaded you can simply run this script. Enter the osmanip folder and type this command on the shell:
```shell
./install.sh
```
A new library *libosmanip* will be created into the `/usr/local/lib` folder of your computer and the [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.h) header will be installed into `/usr/local/include`.

## Compile and run

Once you have installed the library you can freely use it in one of your C++ projects by adding this line of code at the beginning of a program:
```c++
#include <osmanip.h>
```
or equivalently:
```c++
#include "osmanip.h"
```
Now you are able to access al the functions and classes of the manipulator.

You can additionally add also a namespace directive if you want:
```c++
using namespace osm;
```

Supposing you are using the library in a program called *program.cpp*, to compile it you have simply to enter this command in the shell:
```shell
g++ program.cpp -losmanip
```
and then you can run the code with:
```shell
./a.out
```
> **NOTE**: at least c++17 standard is required to successfully access al the library features.

## Compile the source code example and testing

The source code contains also an example code [*src/main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) to show the user a simple usage of all the features supported by the library and a test code [*test/tests.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests.cpp) to test the correct functionality of the library functions and methods.

To compile them I prepared a [makefile](https://github.com/JustWhit3/osmanip/blob/main/makefile). The source code is already compiled when you install the library, but in case you don't want to install the package and explore only the library features through this examples, you can run this command on the shell:
```shell
make
```
This will compile both main and test codes. An extra **obj** folder with object files and two executables, *main* and *tests*, are now created.
> **NOTE**: to correctly compile and run the tests.cpp file you need the [doctest](https://github.com/onqtam/doctest) tool installed into your computer.

You have simply to run the former in order to run the entire example code:
```shell
./main
```
or the latter in order to test the correct functionalities of the library classes methods and functions:
```shell
./tests
```
If you want to compile only the main code you can simply enter:
```shell
make main
```
if instead you want to compile only the tests code you can use the following command:
```shell
make tests
```
There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:
```shell
make clean
```
