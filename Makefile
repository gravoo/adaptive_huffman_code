CC= g++
CFLAGS= -c
VERSION= -std=c++11

all: huffmanCode clean

huffmanCode: main.o tree.o node.o transmiter.o
	$(CC) $(VERSION) main.o tree.o node.o transmiter.o -o out

main.o: main.cpp ./include/Node.h ./include/Transmiter.h ./include/Tree.h
	$(CC) $(CFLAGS) $(VERSION) main.cpp -o main.o

tree.o: ./src/Tree.cpp ./include/Node.h  ./include/Tree.h
	$(CC) $(CFLAGS) $(VERSION) ./src/Tree.cpp -o tree.o

node.o: ./src/Node.cpp ./include/Node.h
	$(CC) $(CFLAGS) $(VERSION) ./src/Node.cpp -o node.o

transmiter.o: ./src/Transmiter.cpp ./include/Node.h ./include/Transmiter.h ./include/Tree.h
	$(CC) $(CFLAGS) $(VERSION) ./src/Transmiter.cpp -o transmiter.o

clean:
	rm *.o
