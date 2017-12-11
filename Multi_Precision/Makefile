CC=gcc
main:main.o Multiprece.o
	$(CC) -o main.out main.o Multiprece.o
main.o: main.c
	$(CC) -c main.c
Multiprece.o: Multiprece.c
	$(CC) -c Multiprece.c
clean:
	rm main.out
run: 
	./main.out