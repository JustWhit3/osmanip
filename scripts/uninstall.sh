#!/bin/bash

#====================================================
#     GLOBAL VARIABLES
#====================================================
declare -a headers=("osmanip" )
declare -a libraries=("libosmanip.a")
if [[ "$UNAME" == Darwin* ]] ; then
    INCL=/usr/local/include
    LIB=/usr/local/lib
elif [[ "$UNAME" == Linux* ]] ; then
    INCL=/usr/include
    LIB=/usr/lib
else
    read -p "Insert the system include path in which you want to uninstall headers: " word_include
        INCL=${word_include}
    read -p "Insert the system lib path in which you want to uninstall static libraries: " word_lib
        LIB=${word_lib}
fi

#====================================================
#     UNINSTALL THE REPOSITORY
#====================================================
echo ""
echo "Uninstalling the repository..."

#Deleting header files:
echo "Removing headers into /usr/local/include folder..."
for header in "${headers[@]}"
do
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo rm -rf "${INCL}/$header"
    else
        rm -rf "${INCL}/$header"
    fi
done

#Deleting libraries:
echo "Removing libraries into /usr/local/lib folder... "
for library in "${libraries[@]}"
do
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo rm "${LIB}/$library"
    else
        rm "${INCL}/$library"
    fi
done

#Final messages:
echo ""
echo "The software has been succesfully uninstalled!"