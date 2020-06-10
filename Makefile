prog: pers.o main.o
	gcc pers.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
pers.o: pers.c 
	gcc -c pers.c
main.o: main.c
	gcc -c main.c
