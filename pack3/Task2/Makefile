
all: main.o vector.o test.o test2.o
	gcc -std=c11 main.o vector.o test.o test2.o -o main.out -lm

main.o: ./main.c
	gcc -std=c11 -c -g ./main.c -o main.o

vector.o: ./src/vector.c
	gcc -std=c11 -c -g ./src/vector.c -o vector.o

test.o: ./src/test.c
	gcc -std=c11 -c -g ./src/test.c -o test.o

test2.o: ./src/test2.c
	gcc -std=c11 -c -g ./src/test2.c -o test2.o