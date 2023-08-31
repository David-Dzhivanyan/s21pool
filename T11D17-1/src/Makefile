all: door_struct list_test stack_test

rebuild: clean all

door_struct:
	gcc -Wall -Werror -Wextra dmanager_module.c -o ../build/Quest_1

list_test: list.o
	gcc -Wall -Werror -Wextra list.o list_test.c -o ../build/Quest_2

stack_test: stack.o
	gcc -Wall -Werror -Wextra stack.o stack_test.c -o ../build/Quest_3

list.o:
	gcc -Wall -Werror -Wextra -c list.c

stack.o:
	gcc -Wall -Werror -Wextra -c stack.c

clang: clangn
	clang-format -i *.{c,h}

clangn:
	clang-format -n *.{c,h}

clean:
	rm -rf *.o