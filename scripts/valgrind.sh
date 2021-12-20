#!/bin/bash

#====================================================
#     VALGRIND EXECUTION COMMAND
#====================================================
if [ "$2" == "all" ] ; then
    for exec in bin/*
    do
        echo ""
        echo "Running $1 tool on $exec..."
        echo ""
        valgrind --tool=$1 --log-fd=9 $exec 9>&1 1>/dev/null 2>/dev/null
    done
else
    echo ""
    echo "Running $1 tool on $2..."
    echo ""
    valgrind --tool=$1 --log-fd=9 $2 9>&1 1>/dev/null 2>/dev/null
fi