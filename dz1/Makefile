a.out: main.o allocator.o
	gcc -std=gnu++11 main.o allocator.o -o a.out
allocator.o: allocator.cpp allocator.h
	gcc  -c -std=gnu++11 allocator.cpp -o allocator.o
main.o: main.cpp allocator.h
	gcc  -c -std=gnu++11 main.cpp  -o main.o
clean:
	rm -f main.o allocator.o a.out

