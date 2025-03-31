#!/bin/bash
sleep 5

LOCK_FILE="./file.lock"
echo "File in use. Waiting for unlock"
while true; do
    flock -x $LOCK_FILE -c "
        echo $(($(tail -n 1 numbers_lock.txt) +1)) >> numbers_lock.txt
    "
done
