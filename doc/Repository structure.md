# Repository structure

## Table of contents
- [Folders](#folders)
  * [Settings folders:](#settings-folders-)
  * [Documentation folders:](#documentation-folders-)
  * [Code folders:](#code-folders-)
- [Files](#files)
  * [Setting files](#setting-files)
  * [Compilation files:](#compilation-files-)
  * [Other:](#other-)
- [Scripts](#scripts)
  * [Installation scripts:](#installation-scripts-)

## Folders

### Settings folders:
- [**.vscode**](https://github.com/JustWhit3/osmanip/blob/main/.vscode): it contains vs code files:
  * [*settings.json*](https://github.com/JustWhit3/osmanip/blob/main/.vscode/settings.json): which contains vs code settings (in case you are using vs code as editor).

### Documentation folders:
- [**img**](https://github.com/JustWhit3/osmanip/tree/main/img): it contains media used for documentation.
- [**doc**](https://github.com/JustWhit3/osmanip/tree/main/doc): it contains the library documentation. More info are explained in the [*main*](https://github.com/JustWhit3/osmanip/tree/main) page of the repository.

### Code folders:
- [**include**](https://github.com/JustWhit3/osmanip/tree/main/include): it contains the library header files:
  * [*osmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.h): general header file containing all the others.
  * [*csmanip.h*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.h): colors/styles manipulation header.
  * [*progress_bar.h*](https://github.com/JustWhit3/osmanip/blob/main/include/progress_bar.h): progress bar functionalities header.
  * [*helper_tools.h*](https://github.com/JustWhit3/osmanip/blob/main/include/helper_tools.h): helper tools header. It contains tools used in the main code headers.
- [**src**](https://github.com/JustWhit3/osmanip/tree/main/src): it contains library implementation and main files:
  * [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp): *osmanip.h* implementation code.
  * [*progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp): *helper_tools.h* implementation code.
  * [*helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/helper_tools.cpp): *helper_tools* implementation code.
  * [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp): which shows you examples of the library utilities.
- [**test**](https://github.com/JustWhit3/osmanip/blob/main/test): it contains testing scripts:
  * [*tests.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests.cpp): which tests the main library functions and methods.

## Files

### Setting files
- [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore): it ignores some temporary files you don't have to care about.
- [*.gitattributes*](https://github.com/JustWhit3/osmanip/blob/main/.gitattributes): it corrects the language percentage assignment.

### Compilation files:
- [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile): for main and tests codes compilation.

### Other:
- [*License*](https://github.com/JustWhit3/osmanip/blob/main/License): is the License file, please read it before using this library with your own public code.

## Scripts

### Installation scripts:
- [*install.sh*](https://github.com/JustWhit3/osmanip/blob/main/install.sh): is the script used to install the software in your computer.
