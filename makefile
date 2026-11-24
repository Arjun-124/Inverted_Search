output.exe: main.o create.o display.o read_validate.o save.o search.o update.o
	gcc main.o create.o display.o read_validate.o save.o search.o update.o -o output.exe
main.o: main.c
	gcc -c main.c
create.o: create.c
	gcc -c create.c
display.o: display.c
	gcc -c display.c
read_validate.o: read_validate.c
	gcc -c read_validate.c
save.o: save.c
	gcc -c save.c
search.o: search.c
	gcc -c search.c
update.o: update.c
	gcc -c update.c
