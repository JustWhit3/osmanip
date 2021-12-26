# Repository structure

## Table of contents
- [Folders](#folders)
  * [Settings folders](#settings-folders-)
  * [Documentation folders](#documentation-folders-)
  * [Code folders](#code-folders-)
  * [Other](#other)
- [Files](#files)
  * [Setting files](#setting-files)
  * [Compilation files](#compilation-files-)
  * [Other](#other-)

## Folders

### Settings folders
- [**.vscode**](https://github.com/JustWhit3/osmanip/blob/main/.vscode): it contains vs code files:
  * [*settings.json*](https://github.com/JustWhit3/osmanip/blob/main/.vscode/settings.json): which contains vs code settings (in case you are using vs code as editor).

### Documentation folders
- [**img**](https://github.com/JustWhit3/osmanip/tree/main/img): it contains media used for documentation.
- [**doc**](https://github.com/JustWhit3/osmanip/tree/main/doc): it contains the library documentation. More info are explained in the [*main*](https://github.com/JustWhit3/osmanip/tree/main) page of the repository.

### Code folders
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
- [**test**](https://github.com/JustWhit3/osmanip/blob/main/test): it contains testing codes:
  * [*tests_csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_csmanip.cpp): which tests the [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp) objects.
  * [*tests_progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_progress_bar.cpp): which tests the [*progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp) objects.
  * [*tests_helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_helper_tools.cpp): which tests the [*helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/helper_tools.cpp) objects.

### Other

- [**scripts**](https://github.com/JustWhit3/osmanip/tree/main/scripts): it contains the repository scripts:
  * [*install.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/install.sh): it is used to install the software in your computer.
  * [*debug.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/debug.sh): it is used to run valgrind debugging tools.


## Files

### Setting files
- [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore): it ignores some temporary files you don't have to care about.
- [*.gitattributes*](https://github.com/JustWhit3/osmanip/blob/main/.gitattributes): it contains repository settings.
- [*.valgrindrc*](https://github.com/JustWhit3/osmanip/blob/main/.valgrindrc): it contains valgrind tools options.

### Compilation files
- [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile): for main and tests codes compilation.

### Other
- [*README.md*](https://github.com/JustWhit3/osmanip/blob/main/README.md): is the main README.md file of the software.
- [*CREDITS.md*](https://github.com/JustWhit3/osmanip/blob/main/CREDITS.md): it contains names of the contributors of the software.
- [*License*](https://github.com/JustWhit3/osmanip/blob/main/License): is the License file, please read it before using this library with your own public code.
- [*CITATION.cff*](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff): it contains information about how to properly cite this software.