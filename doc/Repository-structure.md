# Repository structure

```
osmanip/
├── .github/
│   ├── workflows/
│   │   ├── DocGenerator.yml
│   │   ├── codeql-analysis.yml
├── img/
├── doc/
│   ├── Contributing.md
│   ├── Download-install-run.md
│   ├── Todo.md
│   ├── How-to-use.md
├── include/
│   ├── graphics/
│   │   ├── canvas.hpp
│   │   ├── plot_2D.hpp
│   ├── manipulators/
│   │   ├── colsty.hpp
│   │   ├── cursor.hpp
│   │   ├── common.hpp
│   │   ├── printer.hpp
│   ├── progressbar/
│   │   ├── progress_bar.hpp
│   │   ├── multi_progress_bar.hpp
│   ├── utility/
│   │   ├── windows.hpp
│   │   ├── options.hpp
├── src/
│   ├── graphics/
│   │   ├── canvas.cpp
│   │   ├── plot_2D.cpp
│   ├── manipulators/
│   │   ├── colsty.cpp
│   │   ├── cursor.cpp
│   │   ├── common.cpp
│   │   ├── printer.hpp
│   ├── progressbar/
│   │   ├── progress_bar.cpp
│   │   ├── multi_progress_bar.cpp
│   ├── utility/
│   │   ├── windows.cpp
├── examples/
│   ├── manipulators.cpp
│   ├── progressbar.cpp
│   ├── graphics.cpp
├── scripts/
│   ├── debug.sh
│   ├── install.sh
│   ├── uninstall.sh
│   ├── update.sh
│   ├── size_of_dir.py
├── test/
│   ├── graphics/
│   │   ├── tests_canvas.cpp
│   │   ├── tests_plot_2D.cpp
│   ├── manipulators/
│   │   ├── tests_common.cpp
│   │   ├── tests_colsty.cpp
│   │   ├── tests_cursor.cpp
│   │   ├── tests_printer.cpp
│   ├── progressbar/
│   │   ├── tests_progress_bar.cpp
│   │   ├── tests_multi_progress_bar.cpp
│── README.md
│── License
│── CITATION.cff
│── Makefile
│── Doxyfile
│── .gitignore
│── .clang-format
│── .valgrindrc
│── .gitignore
│── .all-contributorsrc
```