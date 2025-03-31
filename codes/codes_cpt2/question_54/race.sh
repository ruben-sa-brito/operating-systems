#!/bin/bash
sleep 5

while true; do
    echo $(($(tail -n 1 numbers.txt) +1)) >> numbers.txt
done