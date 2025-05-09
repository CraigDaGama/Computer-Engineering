#!/bin/bash
#Program Statement: Using switch case print the capitals given the state name.
echo "Choose the options for getting capital of the states: 1)Maharashtra 2)Goa 3)Karnataka 4)Tamil Nadu 5)Telangana "
read choice
case $choice in
1) echo "Mumbai";;
2) echo "Panjim";;
3) echo "Banglore";;
4) echo "Chennai";;
5) echo "Hyderabad";;
*) echo "Invalid option"
esac

