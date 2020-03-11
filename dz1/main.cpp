#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"


int main(){
	printf("Hello!\n");
	makeAllocator(1024);
	char* p1=alloc(125);
	char* p2=alloc(500);
	

	//test1 
	printf("Test1(p1!=p2):\n");
	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
	if(p1==p2){printf("Error: p1=p2\n"); end_work(); return 1;}
	else printf("Test1: ok\n\n");

	//test2
	printf("Test2(p2-p1==125):\n");
	printf("p2-p1=%ld\n",p2-p1);
	if(p2-p1!=125*sizeof(char)){printf("Error: p2-p1 != 125\n"); end_work(); return 2;}
	else printf("Test2: ok\n\n");

	//test3
	printf("Test3:\n");
	char* p3=alloc(1000);
	printf("p3=%p , int(nullptr)=%ld\n",p3, long(nullptr));
	if (p3 != nullptr) {printf("Error: not nullptr!\n"); end_work(); return 3;}
	else printf("Test3: ok\n\n");

	//test4
	printf("Test4(after bad alloc we ask for less memory):\n");
	char* p4=alloc(10);
	printf("p4-p2=%ld\n",p4-p2);
	if(p4-p2!=500*sizeof(char)){printf("Error: p4-p2 != 500\n"); end_work(); return 4;}
	else printf("Test4: ok\n\n");

	//test5
	printf("Test5(reset and  p5==p1):\n");
	reset();
	char* p5=alloc(125);
	printf("p5=%p, p1=%p\n",p5,p1);
	if(p5!=p1){printf("Error: p5 !=p1\n"); end_work(); return 5;}
	else printf("Test5: ok\n\n");

	end_work();
	return 0;

}