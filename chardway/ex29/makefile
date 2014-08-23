NUMBER = 29

all: libex$(NUMBER) ex$(NUMBER)

libex$(NUMBER):
	cc -c libex$(NUMBER).c -fPIC -o libex$(NUMBER).o
	cc -shared -o libex$(NUMBER).so libex$(NUMBER).o

ex$(NUMBER):
	cc -Wall -g -DNDEBUG ex$(NUMBER).c -ldl -o ex$(NUMBER)

clean:
	rm *.o *.so ex$(NUMBER)
