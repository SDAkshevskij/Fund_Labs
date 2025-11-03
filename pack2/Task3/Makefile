
all: main.o string_manager.o status_manager.o file_manager.o solve.o test.o flag_manager.o
	gcc -std=c11 main.o string_manager.o status_manager.o file_manager.o solve.o flag_manager.o test.o -o main.out -lm

main.o: ./src/main.c
	gcc -std=c11 -c -g ./src/main.c -o main.o

string_manager.o: ./src/string_manager.c 
	gcc -std=c11 -c -g ./src/string_manager.c -o string_manager.o

status_manager.o: ./src/status_manager.c
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o

file_manager.o: ./src/file_manager.c
	gcc -std=c11 -c -g ./src/file_manager.c -o file_manager.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

flag_manager.o: ./src/flag_manager.c
	gcc -std=c11 -c -g ./src/flag_manager.c -o flag_manager.o

test.o: ./src/test.c
	gcc -std=c11 -c -g ./src/test.c -o test.o