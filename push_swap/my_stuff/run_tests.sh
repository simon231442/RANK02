#!/bin/bash

args_list=("1 2 12 1"
"1"
"1 8 7 9 7"
"1 abc 3"
"8 7 -2147483649"
"15 35 18 2147483648"
"-2147483648 2147483647")

for args in "${args_list[@]}"; do
    echo "\"$args\""
    ./push_swap "$args"
    echo "-----------------------------------"
    echo "$args"
    ./push_swap $args
    echo "-----------------------------------"
done
