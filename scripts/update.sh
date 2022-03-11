#!/bin/bash

#====================================================
#     UPDATING THE REPOSITORY
#====================================================
echo ""
echo "Updating the repository..."
echo ""

#Deleting old files and downloading the new repo:
cd ..
rm -rf osmanip*

#Downloading new ones:
wget https://github.com/JustWhit3/osmanip/archive/main.zip
mv main.zip osmanip-main.zip
unzip osmanip-main.zip
rm osmanip-main.zip
mv osmanip-main osmanip
echo ""
echo "Repository is up-to-date!"
echo ""
echo "Enter the following commands:"
echo "1. cd .."
echo "2. cd osmanip"
echo ""