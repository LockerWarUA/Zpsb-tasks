run: main.o libMyMath.a
	gcc -o run main.o -L. -lMyMath

main.o: main.c
	gcc -c main.c

libMyMath.a: MyMath.o
	ar cr libMyMath.a MyMath.o

MyMath.o: MyMath.c
	gcc -c MyMath.c

clean:
	rm -f *.o *.a run
