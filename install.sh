#!/bin/bash

#Compilation of the source code (check if doctest is installed):
if [ -f "/usr/include/doctest.h" ] ; then
    echo "Compiling the whole code..."
    if ! make ; then
        echo "Compilation failed!"
        exit
    fi
elif [ -f "/usr/include/doctest/doctest.h" ] ; then
    echo "Doctest is installed in /usr/include/doctest folder, move it in /usr/include in order to correctly use it for the library tests!"
    echo "Compiling only the main code (this is not a problem for the installation)..."
    if ! make bin/main ; then
        echo "Compilation failed!"
        exit
    fi
else
    echo "Doctest is not installed, cannot compile the test codes!"
    eco "Compiling only the main code (this is not a problem for the installation)..."
    if ! make bin/main ; then
        echo "Compilation failed!"
        exit
    fi
fi
echo ""

#Saving files into the system:
include_var=$(stat -c%s "include")
lib_var=$(stat -c%s "lib")
var=$(expr $include_var + $lib_var)
echo "Installation will take up $var bytes of disk space. Would you like to continue? (y/n)"
read word
if [ $word == "y" ] || [ $word == "Y" ] ; then
    echo "Enter your password for the last installation step:"
    sudo echo "Installing osmanip header files into /usr/local/include folder..."
    if ! ( sudo cp include/* /usr/local/include ) ; then
        echo "Cannot install the header file into /usr/local/include position of the system!"
    fi
    echo "Installing osmanip lib into /usr/local/lib folder..."
    if ! ( sudo cp lib/* /usr/local/lib ) ; then
        echo "Cannot install the header file into /usr/local/lib position of the system!"
    fi
else
    echo "Installation has been canceled!"
    exit
fi
echo ""

#Installation completed:
echo "Osmanip has been succesfully installed!"
echo ""
echo "To compile any C++ program with this library use:"
echo ""
echo "           g++ program.cpp -losmanip"
echo ""
echo "Enjoy! :)"