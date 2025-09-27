
all: main.o prime_search.o string_helper.o error_manager.o
	gcc -std=c11 main.o prime_search.o string_helper.o error_manager.o -o main.out

main.o: ./src/main.c
	gcc -std=c11 -c -g ./src/main.c -o main.o

prime_search.o: ./src/prime_search.c
	gcc -std=c11 -c -g ./src/prime_search.c -o prime_search.o

string_helper.o: ./src/string_helper.c 
	gcc -std=c11 -c -g ./src/string_helper.c -o string_helper.o

error_manager.o: ./src/error_manager.c
	gcc -std=c11 -c -g ./src/error_manager.c -o error_manager.o