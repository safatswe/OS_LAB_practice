#!/bin/bash
echo "enter two number"
read a b
while((b!=0))
do 
temp=$b
b=$((a%b))
a=$temp
done
echo "$a"

