all: main.o string_helper.o number_process.o error_manager.o
	gcc -std=c11 main.o string_helper.o number_process.o error_manager.o -o main.out

main.o: ./src/main.c include/string_helper.h include/number_process.h
	gcc -std=c11 -c -g ./src/main.c -o main.o

string_helper.o: ./src/string_helper.c include/string_helper.h
	gcc -std=c11 -c -g ./src/string_helper.c -o string_helper.o

number_process.o: ./src/number_process.c include/number_process.h
	gcc -std=c11 -c -g ./src/number_process.c -o number_process.o

error_manager.o: ./src/error_manager.c
	gcc -std=c11 -c -g ./src/error_manager.c -o error_manager.o 