.SUFFIXES: .c .cpp .o

CC=g++  -shared -fPIC

GCC=g++

 

all:test_so1.so test_so2.so test_dl clean

 

OBJ1=test_so1.o

OBJ2=test_so2.o

OBJ3=test_dl.o

 

test_so1.so:$(OBJ1)

	$(CC) -o $@ $?

	cp $@ /usr/lib

 

test_so2.so:$(OBJ2)

	$(CC) -o $@ $?

	cp $@ /usr/lib

 

test_dl:$(OBJ3)

	$(GCC)  -o $@ $? -ldl

 

.cpp.o:

	$(CC) -c $*.cpp

.c.o:

	$(CC) -c $*.c

clean:

	rm -f *.o 