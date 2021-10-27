
# Build with debug symbols
alldb: buildb linkdb clear

buildb: src/*.c 
	gcc -g -c src/*.c

linkdb:
	gcc -g -o bin/tp1db *.o

# Build minbash
minibash: mbmain mbheader mblink clear

mbmain: minibash.c
	gcc -g -c minibash.c

mbheader: src/tp1.c src/utils.c
	gcc -g -c src/tp1.c src/utils.c 

mblink:
	gcc -g -o bin/minibash *.o

# Build execfile
execfile: efmain efheader eflink clear

efmain: execfile.c 
	gcc -g -c execfile.c

efheader: src/tp1.c src/utils.c
	gcc -g -c src/tp1.c src/utils.c

eflink:
	gcc -g -o bin/execfile *.o

clear:
	rm *.o
	rm testfile.txt
