#!/bin/bash

if [ ! -d "dist" ]; then
    mkdir dist
else
    rm -rf dist
    mkdir dist
fi

gcc -c ./src/modules/helpers.c -o ./src/modules/helpers.o
gcc -c ./src/modules/sort.c -o ./src/modules/sort.o
gcc -g -Wall -Werror ./src/main.c ./src/modules/helpers.c ./src/modules/sort.c -o ./dist/main.out

./dist/main.out
