all: libex29 ex29

libex29:
	cc -c -fPIC libex29.c -o libex29.o
	cc -shared -o libex29.so libex29.o

ex29:
	cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29

clean:
	rm *.so *.o ex29
