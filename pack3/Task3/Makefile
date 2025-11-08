
all: main.o solve.o test.o linked_list.o string_manager.o file_manager.o liver.o status_manager.o interface.o
	gcc -std=c11 main.o solve.o test.o linked_list.o string_manager.o file_manager.o liver.o status_manager.o interface.o -o main.out -lm

main.o: ./main.c
	gcc -std=c11 -c -g ./main.c -o main.o

test.o: ./src/test.c
	gcc -std=c11 -c -g ./src/test.c -o test.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

linked_list.o: ./src/linked_list.c
	gcc -std=c11 -c -g ./src/linked_list.c -o linked_list.o

string_manager.o: ./src/string_manager.c 
	gcc -std=c11 -c -g ./src/string_manager.c -o string_manager.o

file_manager.o:  ./src/file_manager.c
	gcc -std=c11 -c -g ./src/file_manager.c -o file_manager.o

status_manager.o: ./src/status_manager.c 
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o

liver.o: ./src/liver.c 
	gcc -std=c11 -c -g ./src/liver.c -o liver.o

interface.o: ./src/interface.c 
	gcc -std=c11 -c -g ./src/interface.c -o interface.o