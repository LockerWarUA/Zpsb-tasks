#!/bin/bash

file=$1
symbol=$2
echo "count $(cat $file | tr -cd "$symbol" | wc -m)  in file $file"