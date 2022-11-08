s21_cat : s21_cat
	gcc -Wall -Werror -Wextra cat.c -o s21_cat

clean : s21_cat
	rm s21_cat

rebuild :
	make clean
	make s21_cat

leaks :	test_leak_cat.sh
	sh test_leak_cat.sh

test :	test_func_cat.sh
	sh test_func_cat.sh
