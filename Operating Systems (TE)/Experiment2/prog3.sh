#!/bin/bash
#Problem Statement: Generate the fibonacci series
echo "Enter the number of terms"
read n
a=0
b=1
echo "Fibonacci Sequence :"
for((i=1; i<=n; i++))
do
echo $a
c=`expr $a + $b`
a=`expr $b`
b=`expr $c`
done
