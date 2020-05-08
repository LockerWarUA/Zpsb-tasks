#!/bin/bash

path=$1
depth=$2
constant=1
directories=$(find $path -maxdepth $depth -type d -print | wc -l)
files=$(find $path -maxdepth $depth -type f -print | wc -l)
let "directories = $directories - $constant"
echo "Directories: $directories"
echo "Files: $files"
