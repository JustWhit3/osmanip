#!/bin/bash

#====================================================
#     GLOBAL VARIABLES
#====================================================
declare -a headers=("osmanip" )
declare -a libraries=("libosmanip.a")

#====================================================
#     UNINSTALL THE REPOSITORY
#====================================================
echo ""
echo "Uninstalling the repository..."

#Deleting header files:
echo "Removing headers into /usr/local/include folder..."
for header in "${headers[@]}"
do
    sudo rm -rf /usr/local/include/$header
done

#Deleting libraries:
echo "Removing libraries into /usr/local/lib folder... "
for library in "${libraries[@]}"
do
    sudo rm /usr/local/lib/$library
done

#Final messages:
echo ""
echo "The software has been succesfully uninstalled!"