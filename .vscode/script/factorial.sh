#!/bin/bash
echo "Enter the number"
read num
fact=1
for ((i=1;i<=num;i++))
do
fact=$((fact*i))
done
echo "the factorial of $num is $fact"
