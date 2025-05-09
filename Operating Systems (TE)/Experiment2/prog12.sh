#!/bin/bash
#Program Statement: To check if the entered string is palindrome or not.
read -p "Enter a string: " string
if [[ "$(echo "$string" | rev)" == "$string" ]]
then
      echo " $string is a Palindrome"
else
      echo "$string is Not a palindrome"    
fi 

