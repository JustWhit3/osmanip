# Repository structure

## Table of contents
- [Repository diagram structure](#repository-diagram-structure)
- [Folders](#folders)
  * [Documentation folders](#documentation-folders-)
  * [Code folders](#code-folders-)
  * [Other](#other)
- [Files](#files)
  * [Dotfiles](#setting-files)
  * [Compilation files](#compilation-files-)
  * [Other](#other-)

## Repository diagram structure

```
osmanip/
├── doc/
│   ├── Code structure.md
│   ├── Contributing.md
│   ├── Download and install.md
│   ├── Repository structure.md
│   ├── Todo.md
│   ├── How-to-use guides.md
├── img/
├── include/
│   ├── csmanip.hpp
│   ├── helper_tools.hpp
│   ├── aliases.hpp
│   ├── osmanip.hpp
│   ├── progress_bar.hpp
│   ├── multi_progress_bar.hpp
├── src/
│   ├── csmanip.cpp
│   ├── helper_tools.cpp
│   ├── main.cpp
│   ├── progress_bar.cpp
├── scripts/
│   ├── debug.sh
│   ├── install.sh
│   ├── uninstall.sh
│   ├── update.sh
├── test/
│   ├── tests_csmanip.cpp
│   ├── tests_helper_tools.cpp
│   ├── tests_progress_bar.cpp
│── README.md
│── License
│── .gitignore
│── CITATION.cff
│── Makefile
```

## Folders

### Documentation folders
- [**img**](https://github.com/JustWhit3/osmanip/tree/main/img): it contains media used for documentation.
- [**doc**](https://github.com/JustWhit3/osmanip/tree/main/doc): it contains the library documentation. More info are explained in the [*main*](https://github.com/JustWhit3/osmanip/tree/main) page of the repository.

### Code folders
- [**include**](https://github.com/JustWhit3/osmanip/tree/main/include): it contains the library header files:
  * [*osmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.hpp): general header file containing all the others.
  * [*csmanip.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/osmanip.hpp): colors/styles manipulation header.
  * [*progress_bar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/progress_bar.hpp): progress bar functionalities header.
  * [*helper_tools.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/helper_tools.hpp): helper tools header. It contains tools used in the main code headers.
  * [*aliases.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/aliases.hpp): header with all the type aliases definition.
  * [*multi_progress_bar.hpp*](https://github.com/JustWhit3/osmanip/blob/main/include/multi_progress_bar.hpp): It contains source code for the multi progress bars implementation.
- [**src**](https://github.com/JustWhit3/osmanip/tree/main/src): it contains library implementation and main files:
  * [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp): *osmanip.hpp* implementation code.
  * [*progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp): *helper_tools.hpp* implementation code.
  * [*helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/helper_tools.cpp): *helper_tools* implementation code.
  * [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp): which shows you examples of the library utilities.
- [**test**](https://github.com/JustWhit3/osmanip/blob/main/test): it contains testing codes:
  * [*tests_csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_csmanip.cpp): which tests the [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/osmanip.cpp) objects.
  * [*tests_progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_progress_bar.cpp): which tests the [*progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp) objects.
  * [*tests_helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/test/tests_helper_tools.cpp): which tests the [*helper_tools.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/helper_tools.cpp) objects.

### Other

- [**scripts**](https://github.com/JustWhit3/osmanip/tree/main/scripts): it contains the repository scripts:
  * [*install.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/install.sh): it is used to install the software in your computer.
  * [*update.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/update.sh): it is used to update the software in your computer.
  * [*uninstall.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/uninstall.sh): it is used to uninstall the software from your computer.
  * [*debug.sh*](https://github.com/JustWhit3/osmanip/blob/main/scripts/debug.sh): it is used to run valgrind debugging tools.


## Files

### Dotfiles
- [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore): it ignores some temporary files you don't have to care about.
- [*.valgrindrc*](https://github.com/JustWhit3/osmanip/blob/main/.valgrindrc): it contains valgrind tools options.

### Compilation files
- [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile): for main and tests codes compilation.

### Other
- [*README.md*](https://github.com/JustWhit3/osmanip/blob/main/README.md): is the main README.md file of the software.
- [*License*](https://github.com/JustWhit3/osmanip/blob/main/License): is the License file, please read it before using this library with your own public code.
- [*CITATION.cff*](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff): it contains information about how to properly cite this software.
