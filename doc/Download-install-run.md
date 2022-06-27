# Download and install

## Table of contents

- [Prerequisites](#prerequisites)
  * [Mandatory](#mandatory)
  * [Optional](#optional)
- [Install](#install)
- [Update](#update)
- [Uninstall](#uninstall)
- [Compile and run](#compile-and-run)
  * [Use in your device](#use-in-your-device)
  * [Compile the source code example and testing](#compile-the-source-code-example-and-testing)
- [Other scripts](#other-scripts)
  * [debug.sh](#debugsh)

## Prerequisites

All the prerequisites can be installed during the first step of the automatic installation with [script](https://github.com/JustWhit3/osmanip/blob/main/scripts/install.sh).

### Mandatory

Tools:

- C++17 standard.
- A terminal supporting ANSI escape codes.
- g++ compiler (g++ 9.3.0 has been tested so far) for compilation.
- [GNU make](https://www.opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners/#:~:text=Installing%20GNU%20Make,install%20build%2Dessential.) for compilation.

> **NOTE**: if you are on **MacOS** you would need also [Xcode](https://www.freecodecamp.org/news/how-to-download-and-install-xcode/) and [Homebrew](https://brew.sh/index_it) installed.
> **NOTE**: if you are on **Windows** you would need also [pacman](https://www.msys2.org/docs/package-management/) or [chocolately](https://chocolatey.org/) installed.

Libraries and frameworks:

- [Boost](https://www.boost.org/) library.
- [arsenalgear](https://github.com/JustWhit3/arsenalgear-cpp) library.

### Optional

Tools:

- [Valgrind](https://valgrind.org/) to run the [debug.sh](#debugsh) script.
- [Cppcheck](https://github.com/danmar/cppcheck) to run the [debug.sh](#debugsh) script.
- [Clang formatter](https://stackoverflow.com/questions/20756924/how-can-i-install-clang-format-in-ubuntu#:~:text=16.04%2C%20simply%20do%3A-,sudo%20apt%20install%20clang%2Dformat,-Share) to format the code for pull requests.
- [wget](https://www.techwalla.com/articles/how-to-install-wget-in-ubuntu) to download extra dependencies repositories.
- [unzip](https://www.mysoftkey.com/linux/how-to-do-zip-and-unzip-file-in-ubuntu-linux/) to unzip zipped directories during download and installation.
- [Doxygen](https://www.doxygen.nl/manual/starting.html) for documentation generation while developing.

Libraries and frameworks:

- [doctest](https://github.com/onqtam/doctest) for testing.
- [hurry.filesize](https://pypi.org/project/hurry.filesize/) for `size_of_dir.py` script.
- [termcolor](https://pypi.org/project/termcolor/) for `size_of_dir.py` script.

## Install

From release [2.1.0](https://github.com/JustWhit3/osmanip/releases/tag/v2.1.0) an installer script, called [install.sh](https://github.com/JustWhit3/osmanip/blob/main/install.sh), has been introduced. This script can be used to properly install the library into your computer, in order to easily use it in your programs.

Once the source code has been downloaded you can simply run this script. Enter the osmanip folder and type this command on the shell:

```shell
./scripts/install.sh
```

> **NOTE**: this script supports the installation on Ubuntu, MacOS and Windows operating systems.

> **NOTE**: if you are on *Cygwin64* you may get an error related to the `\r` character. To solve it run the `dos2unix` command on the script (ex: `dos2unix install.sh`) before running it.

A new library *libosmanip.a* (or *libosmanip.lib* in the Windows case) will be created into the `/usr/local/lib` folder of your computer and the [*header*](https://github.com/JustWhit3/osmanip/blob/main/include) files will be installed into `/usr/local/include`.
> **NOTE**: if you are on MacOS or Windows the paths are slightly different (looks at [install.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh)).

## Update

In case you want to update the source code from the latest improvements of the repository, you can use the updater script, called [update.sh](https://github.com/JustWhit3/osmanip/blob/main/scripts/update.sh).

From the repository folder type this command on the shell:

```shell
./scripts/update.sh
```

Then, you can reinstall the repository:

```shell
./scripts/install.sh
```

## Uninstall

In case you want to uninstall the software from your computer, you can use the uninstaller script, called [uninstall.sh](https://github.com/JustWhit3/osmanip/blob/main/uninstall.sh).

From the repository folder type this command on the shell:

```shell
./scripts/uninstall.sh
```

## Compile and run

### Use in your device

Once you have installed the library you can freely use it in one of your C++ projects by including one or more of the modules:
```c++
#include <osmanip/module_folder/module_name.hpp>
```
for example:
```c++
#include <osmanip/manipulators/cursor.hpp>
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
> **NOTE**: remember to add `-pthread` flag if you want to use some thread-dependent libraries like [**progressbar/multi_progress_bar.hpp**](https://github.com/JustWhit3/osmanip/blob/main/include/progressbar/multi_progress_bar.hpp).
and then you can run the code with:

```shell
./a.out
```
> **NOTE**: executable is called `a.exe` if you are on Windows.

> **NOTE**: at least c++17 standard is required to successfully access al the library features.

### Compile the source code example and testing

The source code contains also an example code [*src/main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) to show the user a simple usage of all the features supported by the library and test codes in the [**test**](https://github.com/JustWhit3/osmanip/blob/main/test) folder to test the correct functionality of the library functions and methods.

To compile them I prepared a [Makefile](https://github.com/JustWhit3/osmanip/blob/main/Makefile). The source code is already compiled when you install the library, but in case you don't want to install the package and explore only the library features through this examples, you can run this command on the shell:
```shell
make
```
> **NOTE**: this Makefile is compatible with Ubuntu, MacOS and Windows operating systems.

This will compile both main and test codes. An extra **obj** folder with object files and a **bin** folder with some executables for examples and testing, are now created.

To run all the examples (or only one if you prefer):
```shell
./bin/manipulators
./bin/progressbar
./bin/graphics
```

> **NOTE**: executables end with `.exe` if you are on Windows of course.

To run tests:

```shell
./bin/tests
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

## Other scripts

Other scripts have been provided into the [**scripts**](https://github.com/JustWhit3/osmanip/blob/main/scripts) folder. After compiling the source code, they can be run from the repository home directory.

### debug.sh

This script is used to run [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) debugging tools on the whole code.

You can run Valgrind debugging tools with a specific executable:
```shell
./scripts/debug.sh [valgrind-tool-name] [executable-name]
```
> **NOTE**: where `[tool-name]` is the Valgrind tool name and `[executable-name]` is the executable name (you have to indicate also the path to it).

Or you can run them for all the executables of the repository:
```shell
./scripts/debug.sh [valgrind-tool-name] all
```
You can also run Cppcheck tool for a specific source code directory:
```shell
./scripts/debug.sh cppcheck [source-code-dir]
```
Or for a .cpp file only:
```shell
./scripts/debug.sh cppcheck [file.cpp]
```
