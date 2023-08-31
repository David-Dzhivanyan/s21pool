all: clang print_module documentation_module bst_create_test bst_insert_test

rebuild: clean all

print_module: print_module.o
	gcc -Wall -Werror -Wextra print_module.o main_module_entry_point.c -DQuest1 -o ../build/Quest_1

documentation_module: documentation_module.o
	gcc -Wall -Werror -Wextra documentation_module.o main_module_entry_point.c -DQuest2 -o ../build/Quest_2

bst_insert_test: bst.o
	gcc -Wall -Werror -Wextra bst.o bst_insert_test.c -o ../build/Quest_4

bst_create_test: bst.o
		gcc -Wall -Werror -Wextra bst.o bst_create_test.c -o ../build/Quest_3

bst.o:
	gcc -Wall -Werror -Wextra -c bst.c

documentation_module.o:
	gcc -Wall -Werror -Wextra -c documentation_module.c

print_module.o:
	gcc -Wall -Werror -Wextra -c print_module.c

clang: clangn
	clang-format -i *.{c,h}

clangn:
	clang-format -n *.{c,h}

clean:
	rm -rf *.o