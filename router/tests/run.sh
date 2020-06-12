#!/bin/bash
for filename in *.cpp; do
	if test -f "$filename"; then
		g++ ./$filename && ./a.out
		rm a.out
	fi
done