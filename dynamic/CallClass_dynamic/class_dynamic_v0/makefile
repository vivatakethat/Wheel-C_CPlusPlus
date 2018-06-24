.SUFFIXES: .c .cpp .o
CC=g++ -g -shared -fPIC

GCC=g++ -g


all:clear test_1.so a.out test_2.so clean


OBJ1=test_1.o
OBJ2=main.o

OBJ3=test_2.o 
clear:
	rm -rf *.so a.out b.out

test_1.so:$(OBJ1)
	$(CC)	-o $@ $?
	cp $@ /usr/lib

a.out:$(OBJ2)
	$(GCC) -o $@ $? -ldl

test_2.so:$(OBJ3)
	$(CC) -o $@ $?
	cp  $@ /usr/lib


.cpp.o:
	$(CC) -c $*.cpp
.c.o:
	$(CC) -c $*.c

clean:
	rm -f *.o   







	

