
all: main.o solve.o linked_list.o test.o
	gcc -std=c11 main.o solve.o test.o linked_list.o -o main.out -lm

main.o: ./main.c
	gcc -std=c11 -c -g ./main.c -o main.o

solve.o: ./src/solve.c
	gcc -std=c11 -c -g ./src/solve.c -o solve.o

test.o: ./src/test.c
	gcc -std=c11 -c -g ./src/test.c -o test.o

linked_list.o: ./src/linked_list.c
	gcc -std=c11 -c -g ./src/linked_list.c linked_list.o