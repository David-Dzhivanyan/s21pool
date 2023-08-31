all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

rebuild: clean all

strlen_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrlen -o ../build/Quest_1

strcmp_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrcmp -o ../build/Quest_2

strcpy_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrcpy -o ../build/Quest_3

strcat_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrcat -o ../build/Quest_4

strchr_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrchr -o ../build/Quest_5

strstr_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrstr -o ../build/Quest_6

strtok_tests: s21_string.o
	gcc -Wall -Werror -Wextra s21_string.o s21_str_test.c -Dstrtok -o ../build/Quest_7

s21_string.o:
	gcc -Wall -Werror -Wextra -c s21_string.c

clean:
	rm -rf *.o