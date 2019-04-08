all: hello

hello: main.o function1.o function2.o 
	gcc main.o function1.o function2.o -o hello

main.o: main.c
	gcc -c main.c

function1.o: function1.c
	gcc -c function1.c

function2.o: function2.c
	gcc -c function2.c

clean: 
	rm -rf *o hello
