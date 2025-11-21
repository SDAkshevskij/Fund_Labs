
all: main.o status_manager.o solve.o linked_list.o test.o
	gcc -std=c11 main.o status_manager.o solve.o test.o linked_list -o main.out -lm

main.o: ./main.c
	gcc -std=c11 -c -g ./main.c -o main.o

status_manager.o: ./src/status_manager.c
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

test.o: ./src/test.c
	gcc -std=c11 -c -g ./src/test.c -o test.o

linked_list.o: ./src/linked_list.o 
	gcc -std=c11 -c -g ./src/linked_list.o test.o