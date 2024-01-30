#!/bin/bash
for file in *.c; do
    if [ -f "$file" ]; then
	output_file="${file%.c}.o"
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -c "$file" -o "$output_file"
    fi
done
