#!/bin/bash

#====================================================
#     TOOL FUNCTION
#====================================================
tool() {
    if [ "$1" == "cppcheck" ] ; then
        cppcheck $2
    else
        valgrind --tool=$1 -s --log-fd=9 $2 9>&1 1>/dev/null 2>/dev/null
    fi
}

#====================================================
#     VALGRIND EXECUTION COMMAND
#====================================================
if [ "$2" == "all" ] ; then
    for exec in bin/*
    do
        echo ""
        echo "Running $1 tool on $exec..."
        echo ""
        tool $1 $exec
    done
else
    echo ""
    echo "Running $1 tool on $2..."
    echo ""
    tool $1 $2
fi