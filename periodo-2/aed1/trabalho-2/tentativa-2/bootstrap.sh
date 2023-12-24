#!/bin/bash

if [ ! -d "dist" ]; then
    mkdir dist
else
    rm -rf dist
    mkdir dist
fi

gcc -c ./modules/linkedlist.c -o ./modules/linkedlist.o
gcc -c main.c -o main.o
gcc main.c ./modules/linkedlist.c -o ./dist/a.out

./dist/a.out