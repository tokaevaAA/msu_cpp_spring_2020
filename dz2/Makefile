a.out: main.o functions.o
	gcc -std=gnu++11 main.o functions.o -o a.out
functions.o: functions.cpp functions.h
	gcc  -c -std=gnu++11 functions.cpp -o functions.o
main.o: main.cpp functions.h
	gcc  -c -std=gnu++11 main.cpp  -o main.o
clean:
	rm -f main.o functions.o a.out

