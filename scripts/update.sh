#!/bin/bash

#====================================================
#     UPDATING THE REPOSITORY
#====================================================
echo ""
echo "Updating the repository..."
echo ""

#Deleting old files:
rm -rf *

#Downloading new ones:
svn export https://github.com/JustWhit3/osmanip/trunk
mv trunk/* .
rm -rf trunk
echo ""
echo "Repository is up-to-date!"
echo ""