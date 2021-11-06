#!/bin/bash

cat -e < get_next_line.c > original.res

i=1

while [[ $i -le 2000 ]]
do
	echo "Buffer of $i"
	clang -Wall -Werror -Wextra -D BUFFER_SIZE=$i get_next_line.c main_alt.c -o gnl
	./gnl < get_next_line.c > yours_.res
	cat -e yours_.res > yours.res
	diff -y --suppress-common-line original.res yours.res
	i=$(( $i + 1 ))
done

rm -rf yours_.res gnl
