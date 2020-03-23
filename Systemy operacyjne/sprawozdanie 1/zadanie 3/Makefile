run: main.o libMyMath.dll
	gcc -o run main.o -L. -l:libMyMath.dll -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

libMyMath.dll: MyMath.o
	gcc -L. -I. -shared MyMath.c -o libMyMath.dll
	#ar cr libMyMath.dll MyMath.o  -l:libMyMath.dll

MyMath.o: MyMath.c
	gcc -c -fPIC MyMath.c

clean:
	rm -f *.o *.dll run
