all: rebuild data_stat.a build_with_static data_process.so build_with_dynamic clean


rebuild: data_io.o data_process.o data_stat.o decision.o
	gcc -Wall -Werror -Wextra data_io.o data_process.o data_stat.o decision.o main_executable_module.c -o ../../build/Quest_3

data_io.o: ../data_libs/data_io.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	gcc -Wall -Werror -Wextra -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	gcc -Wall -Werror -Wextra -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	gcc -Wall -Werror -Wextra -c ../yet_another_decision_module/decision.c

clean:
	rm -rf *.o

data_stat.a: create_lib_stat
	ranlib libdata_stat.a

create_lib_stat:
	ar rc libdata_stat.a data_stat.o

build_with_static:
	gcc -Wall -Werror -Wextra data_io.o data_process.o decision.o -L. -ldata_stat main_executable_module.c -o ../../build/Quest_5

data_process.so: data_process_PIC.o
	gcc -shared -L. -ldata_stat -o libdata_process.so data_process.o

data_process_PIC.o:
	gcc -Wall -Werror -Wextra -fPIC -c ../data_module/data_process.c

build_with_dynamic:
	gcc -Wall -Werror -Wextra data_io.o decision.o -L. -ldata_process main_executable_module.c -o ../../build/Quest_6