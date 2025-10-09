
all: main.o solve.o string_helper.o status_manager.o number_helper.o
	gcc -std=c11 main.o string_helper.o solve.o status_manager.o number_helper.o -o main.out -lm

main.o: ./src/main.c
	gcc -std=c11 -c -g ./src/main.c -o main.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

string_helper.o: ./src/string_helper.c 
	gcc -std=c11 -c -g ./src/string_helper.c -o string_helper.o

status_manager.o: ./src/status_manager.c
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o
