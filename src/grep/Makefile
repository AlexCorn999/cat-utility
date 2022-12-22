alex_grep :
	gcc -Wall -Werror -Wextra grep.c -o alex_grep

clean :
	rm alex_grep

rebuild :
	make clean
	make alex_grep

leaks :
	sh test_leak_grep.sh

test :
	sh test_func_grep.sh
