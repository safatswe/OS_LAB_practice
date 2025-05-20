#!/bin/bash
echo "How many numbers"
read n
echo "Enter $n numbers"
read largest
i=1
while [ $i -lt $n ]
do
read num
if [ $num -gt $largest ]; then
largest=$num
fi
i=$((i+1))
done
echo "largest number is $largest"
