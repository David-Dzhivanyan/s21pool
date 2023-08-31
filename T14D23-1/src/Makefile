all: clang statesort statesearch clearstate

rebuild: clean all

clearstate: clearstate.o
	gcc -Wall -Werror -Wextra clear_state.o -o ../build/Quest_3

clearstate.o:
	gcc -c -Wall -Werror -Wextra clear_state.c

statesearch: statesearch.o
	gcc -Wall -Werror -Wextra state_search.o -o ../build/Quest_2

statesearch.o:
	gcc -c -Wall -Werror -Wextra state_search.c

statesort: state_sort.o
	gcc -Wall -Werror -Wextra state_sort.o -o ../build/Quest_1

state_sort.o:
	gcc -c -Wall -Werror -Wextra state_sort.c

clang: clangn
	clang-format -i *.c

clangn:
	clang-format -n *.c

clean:
	rm -rf *.o