#!/bin/bash

#====================================================
#     CHECK IF OS IS WINDOWS OR NOT
#====================================================
UNAME=$(uname)
main="main"
if [[ "$UNAME" == CYGWIN* || "$UNAME" == MINGW* ]] ; then
	main="${main}.exe"
fi

#====================================================
#     INSTALLING PREREQUISITES
#====================================================
sudo apt install build-essential g++ libboost-all-dev wget unzip
echo ""
echo "Installing arsenalgear library..."
wget https://github.com/JustWhit3/arsenalgear/archive/main.zip
mv main.zip arsenalgear-main.zip
unzip arsenalgear-main.zip
cd arsenalgear-main || exit
./scripts/install_cpp.sh
cd ..
rm -rf arsenalgear-*
echo ""
read -p "Do you want to install optional prerequisites for osmanip (y/n)? " word_o
if [ $word_o == "y" ] || [ $word_o == "Y" ] ; then
    sudo apt install doctest-dev valgrind cppcheck clang-format
fi
echo ""

#====================================================
#     COMPILATION OF THE SOURCE CODE
#     (check if doctest is installed)
#====================================================
if [ -f "/usr/include/doctest.h" ] ; then
    echo "Compiling the whole osmanip code..."
    if ! make ; then
        echo "Compilation failed!"
        exit
    fi
elif [ -f "/usr/include/doctest/doctest.h" ] ; then
    echo "Doctest is installed in /usr/include/doctest folder, move it in /usr/include in order to correctly use it for the library tests!"
    echo "Compiling only the main code of osmanip (this is not a problem for the installation)..."
    if ! make $main ; then
        echo "Compilation failed!"
        exit
    fi
else
    echo "Doctest is not installed, cannot compile the test codes!"
    echo "Compiling only the main code of osmanip (this is not a problem for the installation)..."
    if ! make $main ; then
        echo "Compilation failed!"
        exit
    fi
fi
echo ""

#====================================================
#     SAVING FILES INTO THE SYSTEM
#====================================================
echo "Installation will take up this number of bytes:"
du -sbh lib include
echo ""
read -p "Would you like to continue (y/n)? " word
if [ $word == "y" ] || [ $word == "Y" ] ; then
    sudo echo "Installing osmanip header files into /usr/local/include folder..."
    sudo mkdir -p /usr/local/include/osmanip
    if ! ( sudo cp -r include/* /usr/local/include/osmanip ) ; then
        echo "Cannot install the header file into /usr/local/include position of the system!"
    fi
    sudo rm -rf /usr/local/include/osmanip/utils
    echo "Installing osmanip lib into /usr/local/lib folder..."
    if ! ( sudo cp lib/* /usr/local/lib ) ; then
        echo "Cannot install the library into /usr/local/lib position of the system!"
    fi
else
    echo "Installation has been canceled!"
    exit
fi
echo ""

#====================================================
#     INSTALLATION COMPLETED
#====================================================
echo "Osmanip has been succesfully installed!"
echo ""
echo "To compile any C++ program with this library, use:"
echo ""
echo "           g++ program.cpp -losmanip"
echo ""
echo "If you use a library component which uses threads:"
echo ""
echo "           g++ program.cpp -losmanip -pthread"
echo ""
echo "Enjoy! :)"
echo ""