CC=clang
CFLAGS =-c -Wall
LDLIBS =-lm 
all: generate
generate: generate.o
	$(CC) $(LDLIBS) generate.o -o generate
generate.o: generate_random_data.c
	$(CC) $(CFLAGS)  generate_random_data.c -o generate.o

clean:
	rm -rf *o generate