#!/bin/bash
echo "enter the number of term"
read num
a=0
b=1
echo "fibonacci series"
for ((i=0;i<num;i++))
do 
echo "$a"
f=$((a+b))
a=$b
b=$f
done
echo
