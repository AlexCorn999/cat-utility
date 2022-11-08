s21_grep : s21_grep
	gcc -Wall -Werror -Wextra grep.c -o s21_grep

clean : s21_grep
	rm s21_grep

rebuild :
	make clean
	make s21_grep

leaks :	test_leak_grep.sh
	sh test_leak_grep.sh

test :	test_func_grep.sh
	sh test_func_grep.sh
