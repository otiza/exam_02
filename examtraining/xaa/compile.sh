#!/bin/bash

if [[ $# == 1 ]]
then
	clang -Wall -Werror -Wextra -D BUFFER_SIZE=$1 -g get_next_line.c main_alt.c -o gnl
else
	clang -Wall -Werror -Wextra -g get_next_line.c main_alt.c -o gnl
fi
