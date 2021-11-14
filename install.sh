#!/bin/bash

#Compilation of the code:
echo "Compiling the whole code..."
if ! make ; then
    echo "Compilation failed!"
    exit
fi
echo ""

#Static library creation:
echo "Creating the static library into the lib folder..."
mkdir -p lib 
if ! ( ar rvs lib/libosmanip.a obj/src/osmanip.cpp.o ) ; then
    echo "Cannot create the static library!"
    exit
fi
echo ""

#Saving files into the system:
echo "Enter your password for the last installation step:"
echo "Installing osmanip header into /usr/local/include folder..."
if ! ( sudo cp include/osmanip.h /usr/local/include ) ; then
    echo "Cannot install the header file into /usr/local/include position of the system!"
fi
echo "Installing osmanip lib into /usr/local/lib folder..."
if ! ( sudo cp lib/* /usr/local/lib ) ; then
    echo "Cannot install the header file into /usr/local/lib position of the system!"
fi
echo ""

#Installation completed:
echo "Osmanip has been succesfully installed!"
echo ""
echo "To compile a C++ program use:"
echo "g++ program.cpp -losmanip"
echo ""
echo "Enjoy! :)"