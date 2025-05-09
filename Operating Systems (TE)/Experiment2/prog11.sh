#!/bin/bash
#Program Statement:To print all the prime numbers less than 20
b=2
while [ $b -lt 20 ]
     do
           i=2
          flag=0
     while [ $i -le `expr $b / 2` ]
          do
               if [ `expr $b % $i` -eq 0 ]
               then
                    flag=1
               break
               fi
          i=`expr $i + 1`
         done
         if [ $flag -eq 0 ]
         then
               echo "$b"
         fi
     b=`expr $b + 1`
done

