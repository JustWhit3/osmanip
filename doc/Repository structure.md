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
│   ├── graphics/
│   │   ├── canvas.hpp
│   │   ├── plot_2D.hpp
│   ├── manipulators/
│   │   ├── csmanip.hpp
│   ├── progressbar/
│   │   ├── progress_bar.hpp
│   │   ├── multi_progress_bar.hpp
│   ├── utils/
│   │   ├── helper_tools.hpp
├── src/
│   ├── graphics/
│   │   ├── canvas.cpp
│   │   ├── plot_2D.cpp
│   ├── manipulators/
│   │   ├── csmanip.cpp
│   ├── progressbar/
│   │   ├── progress_bar.cpp
│   │   ├── multi_progress_bar.cpp
│   ├── utils/
│   │   ├── helper_tools.cpp
│   ├── main.cpp
├── scripts/
│   ├── debug.sh
│   ├── install.sh
│   ├── uninstall.sh
│   ├── update.sh
├── test/
│   ├── graphics/
│   │   ├── tests_canvas.cpp
│   │   ├── tests_plot_2D.cpp
│   ├── manipulators/
│   │   ├── tests_csmanip.cpp
│   ├── progressbar/
│   │   ├── tests_progress_bar.cpp
│   │   ├── tests_multi_progress_bar.cpp
│   ├── utils/
│   │   ├── tests_helper_tools.cpp
│── README.md
│── License
│── .gitignore
│── .clang-format
│── CITATION.cff
│── Makefile
```

## Folders

### Documentation folders

- [**img**](https://github.com/JustWhit3/osmanip/tree/main/img): it contains media used for documentation.
- [**doc**](https://github.com/JustWhit3/osmanip/tree/main/doc): it contains the library documentation. More info are explained in the [*main*](https://github.com/JustWhit3/osmanip/tree/main) page of the repository.

### Code folders

- [**include**](https://github.com/JustWhit3/osmanip/tree/main/include): it contains the library header files:
- [**src**](https://github.com/JustWhit3/osmanip/tree/main/src): it contains library implementation and main files:
- [**test**](https://github.com/JustWhit3/osmanip/tree/main/test): it contains tests for the source code.
- [**scripts**](https://github.com/JustWhit3/osmanip/tree/main/scripts): it contains the repository scripts:

## Files

### Dotfiles

- [*.gitignore*](https://github.com/JustWhit3/osmanip/blob/main/.gitignore): it ignores some temporary files you don't have to care about.
- [*.valgrindrc*](https://github.com/JustWhit3/osmanip/blob/main/.valgrindrc): it contains valgrind tools options.
- [*.clang-format*](https://github.com/JustWhit3/osmanip/blob/main/.clang-format): it contains formatting instructions.

### Compilation files

- [*makefile*](https://github.com/JustWhit3/osmanip/blob/main/makefile): for main and tests codes compilation.

### Other

- [*README.md*](https://github.com/JustWhit3/osmanip/blob/main/README.md): is the main README.md file of the software.
- [*License*](https://github.com/JustWhit3/osmanip/blob/main/License): is the License file, please read it before using this library with your own public code.
- [*CITATION.cff*](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff): it contains information about how to properly cite this software.
