#!/bin/bash

if [[ $1 == "-p" ]]
then
    echo "To using this script you need type $0 after write name of directory and number of files"
else
read file
read count

mkdir $file
for (( i=1; i <= $count; i++ ))
do
    touch $file/$i
done
fi