#!/bin/bash

if [ ! -d "dist" ]; then
    mkdir dist
else
    rm -rf dist
    mkdir dist
fi

gcc -c ./modules/linkedlist.c -o ./modules/linkedlist.o
gcc -c ./modules/stack.c -o ./modules/stack.o
gcc -c ./modules/graph.c -o ./modules/graph.o
gcc -c ./modules/depth-search.c -o ./modules/depth-search.o
gcc -c main.c -o main.o
gcc -g -Wall -Werror main.c ./modules/linkedlist.c ./modules/stack.c ./modules/graph.c ./modules/depth-search.c -o ./dist/a.out

arg1=$1

./dist/a.out $arg1
