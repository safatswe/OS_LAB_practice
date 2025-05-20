#!/bin/bash
echo "enter three digit"
read a b c
sum=$((a+b+c))
av=$(echo  "scale=2; $sum/3"|bc)
echo "$av"
