#!/bin/bash
echo "enter the numbers"
read num
for (( i=1;i<=num;i++))
do 
sum=$((sum+i))
done
echo "$sum"
