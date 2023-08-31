all: clang graph.c clean

rebuild: clean all

graph.c: lexicon_list.o structures.o polish_notation.o value_calculation.o rendering.o
	gcc -Wall -Werror -Wextra  structures.o lexicon_list.o polish_notation.o value_calculation.o rendering.o graph.c -o ../build/graph

rendering.o:
	gcc -Wall -Werror -Wextra -c rendering.c

value_calculation.o:
	gcc -Wall -Werror -Wextra -c value_calculation.c

polish_notation.o:
	gcc -Wall -Werror -Wextra -c polish_notation.c

structures.o:
	gcc -Wall -Werror -Wextra -c structures.c

lexicon_list.o:
	gcc -Wall -Werror -Wextra -c lexicon_list.c

clang: clangn
	clang-format -i *.{c,h}

clangn:
	clang-format -n *.{c,h}

clean:
	rm -rf *.o