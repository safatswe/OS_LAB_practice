#!/bin/bash
echo "enter the number"
read num
if [ $((num%2 )) -eq 0 ]; then
echo "the  $num is even "
else
echo "the $num is odd"
fi
