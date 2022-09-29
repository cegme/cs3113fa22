all: mycfile bits

hash: hash.c
	gcc hash.c -Wall -pedantic -g -O3 

mycfile: mycfile.o
	gcc -o mycfile mycfile.o

mycfile.o: mycfile.c
	gcc -c mycfile.c

bits: bits.c
	gcc -o bits bits.c

pdf: mycfile.c
	enscript -r2 mycfile.c -o mycfile.c.ps
	ps2pdf mycfile.c.ps

clean:
	rm -f mycfile.o mycfile *.ps *.pdf bits
