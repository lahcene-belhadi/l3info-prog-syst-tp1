
# Build with debug symbols
alldb: buildb linkdb clear

buildb: src/*.c 
	gcc -g -c src/*.c

linkdb:
	gcc -g -o bin/tp1db *.o

clear:
	rm *.o
	rm testfile.txt