#!/bin/bash
#Program Statement: To reverse a entered string
echo "Enter a string"
read str
len=`echo $str | wc -c`
while [ $len -gt 0 ]
do
     rev=$rev`echo $str | cut -c $len`
     len=`expr $len - 1`
done
echo "Reversal of entered string is $rev"

