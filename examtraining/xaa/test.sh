#!/bin/bash

if [[ $# == 1 ]]
then
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$1" get_next_line.c main_alt.c -o gnl
else
	clang -Wall -Werror -Wextra get_next_line.c main_alt.c -o gnl
fi

./gnl < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
cat -e < get_next_line.c > original.res
diff -y --suppress-common-line original.res yours.res

rm -rf yours_.res gnl
