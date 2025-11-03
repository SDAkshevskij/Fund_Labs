
all: main.o solve.o string_manager.o status_manager.o
	gcc -std=c11 main.o string_manager.o solve.o status_manager.o -o main.out -lm

main.o: ./src/main.c
	gcc -std=c11 -c -g ./src/main.c -o main.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

string_manager.o: ./src/string_manager.c 
	gcc -std=c11 -c -g ./src/string_manager.c -o string_manager.o

status_manager.o: ./src/status_manager.c
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o
