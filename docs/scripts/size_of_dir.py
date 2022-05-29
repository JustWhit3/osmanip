#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 10 22:47:00 2022
Author: Gianluca Bianco
"""

#############################################################
#    Import libraries
#############################################################
import os
import argparse
from hurry.filesize import size
from termcolor import colored

#############################################################
#    Main function
#############################################################
def main():
    
    # Parser settings
    parser = argparse.ArgumentParser( description = "Parses the folder path." )
    parser.add_argument( "--paths", default = "", help = "The folder path." )
    parser.add_argument( "--message", default = "off", help = "The final output message." )
    parser.add_argument( "--exception", default = "", help = "An extra file/dir to be ignored." )
    args = parser.parse_args()
    
    # Variables
    folder_size = 0
    
    # Get size of the path
    for path_elem in args.paths.split( " " ):
        for path, dirs, files in os.walk( path_elem ):
            for file in files:
                if file != args.exception:
                    fp = os.path.join( path, file )
                    folder_size += os.path.getsize( fp )
    
    # Printing the result
    if args.message == "on":
        print( "Installation will take up this number of bytes:", size( folder_size ) )
    elif args.message == "off":
        print( size( folder_size ) )
    else:
        print( colored( "Error: inserted --message option \"{}\" is not supported!".format( args.message ), "red" ) )

if __name__ == "__main__":
    main()