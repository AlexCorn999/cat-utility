s21_grep :
	gcc -Wall -Werror -Wextra grep.c -o s21_grep

clean :
	rm s21_grep

rebuild :
	make clean
	make s21_grep

leaks :
	sh test_leak_grep.sh

test :
	sh test_func_grep.sh
