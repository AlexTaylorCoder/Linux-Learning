#!/bin/bash

if [[ $1 != "test" ]] then
	gcc -o test hashmap-test.c
	./test
else
	gcc -o main hashmap.c
	./main
fi
