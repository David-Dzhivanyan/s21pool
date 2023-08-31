all: clang cipher.o logging_cipher clean

rebuild: clean all

logging_cipher: log
	gcc -Wall -Werror -Wextra logger.o cipher.c -Dlog -o ../build/logging_cipher

log:
	gcc -c -Wall -Werror -Wextra logger.c

cipher.o:
	gcc -Wall -Werror -Wextra cipher.c -o ../build/cipher

clang: clangn
	clang-format -i *.{c,h}

clangn:
	clang-format -n *.{c,h}

clean:
	rm -rf *.o