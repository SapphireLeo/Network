#Makefile
all: add-nbo

add-nbo: read_4bytes.o main.o
	g++ -o add-nbo read_4bytes.o main.o

main.o: read_4bytes.h main.cpp
	g++ -c main.o main.cpp

read_4bytes.o: read_4bytes.h read_4bytes.cpp
	g++ -c read_4bytes.o read_4bytes.cpp


clean:
	rm -f add-nbo
	rm -f *.o

