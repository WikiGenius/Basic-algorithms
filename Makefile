CC =clang
CFLAGS =-c -Wall -g
LDLIBS=-lm
all: algo
algo: main.o sort.o search.o read.o
	$(CC) main.o sort.o search.o read.o -o algo
main.o: ./main/main.c
	$(CC) $(CFLAGS)  ./main/main.c
sort.o: ./sort/sort.c
	$(CC) $(CFLAGS)  ./sort/sort.c
search.o: ./search/search.c
	$(CC) $(CFLAGS)  ./search/search.c
read.o: ./read_data/read_data.c
	$(CC) $(CFLAGS)  ./read_data/read_data.c -o read.o
clean:
	rm -rf *o algo