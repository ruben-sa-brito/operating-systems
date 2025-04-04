#!/bin/bash

NUMBERS_FILE="numbers_lock.txt"
LOCK_FILE="/tmp/script_lck.lock"

while true; do
    if ln -s "$$" "$LOCK_FILE" 2>/dev/null; then
        echo $(($(tail -n 1 numbers_lock.txt) +1)) >> numbers_lock.txt
        echo "I'm here"
        rm -f "$LOCK_FILE"
    else
        echo "Another process is in the critical region."
    fi
done

