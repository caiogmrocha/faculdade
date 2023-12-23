#!/bin/bash

if [ ! -d "dist" ]; then
    mkdir dist
else
    rm -rf dist
    mkdir dist
fi

gcc -c graph.c -o graph.o
gcc -c main.c -o main.o
gcc main.c graph.c -o ./dist/a.out

./dist/a.out