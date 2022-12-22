s21_cat :
	gcc -Wall -Werror -Wextra cat.c -o s21_cat

clean :
	rm s21_cat

rebuild :
	make clean
	make s21_cat

leaks :
	sh test_leak_cat.sh

test :
	sh test_func_cat.sh
