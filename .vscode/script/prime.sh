#!/bin/bash
echo "enter the number "
read num
if ((num<=1)); then
echo "not prime"
exit 0
fi
f=1
for ((i=2;i*i<=num;i++))
do 
if ((num%i==0)); then
   f=0
fi
done
if ((f==0)); then
echo "not prime"
else 
echo  " prime"
fi
   

