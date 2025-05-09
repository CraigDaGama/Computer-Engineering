#!/bin/bash
#Program Statement: Check if given year is leap year or not
echo "Enter the year : "
read year
if [ `expr $year % 4` == 0 ]
then
  echo "It is a leap year"
else
  echo "It is not a leap year"
fi
