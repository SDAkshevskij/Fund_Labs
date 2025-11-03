
all: main.o string_manager.o status_manager.o file_manager.o student.o
	gcc -std=c11 main.o string_manager.o status_manager.o file_manager.o student.o -o main.out -lm

main.o: ./src/main.c
	gcc -std=c11 -c -g ./src/main.c -o main.o

string_manager.o: ./src/string_manager.c 
	gcc -std=c11 -c -g ./src/string_manager.c -o string_manager.o

status_manager.o: ./src/status_manager.c
	gcc -std=c11 -c -g ./src/status_manager.c -o status_manager.o

student.o: ./src/student.c 
	gcc -std=c11 -c -g ./src/student.c -o student.o

file_manager.o: ./src/file_manager.c
	gcc -std=c11 -c -g ./src/file_manager.c -o file_manager.o
