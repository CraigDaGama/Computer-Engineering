#!/bin/bash
#Problem Statement: square of first 20 numbers
for((i=1; i<=20; i++))
do
echo $i\*$i = `expr $i \* $i`
done
