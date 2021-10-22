
alldb: src/*.c
	gcc -g -c src/*.c
	gcc -g -o bin/tp1 *.o
	rm *.o
