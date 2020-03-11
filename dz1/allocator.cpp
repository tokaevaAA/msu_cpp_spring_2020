#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

char* head;
int full_part=0;
int my_maxSize=0;
int initial_success=0;


void makeAllocator(size_t maxSize){
	my_maxSize=maxSize;
	head=(char*)malloc(maxSize*sizeof(char));
	if(head==0){head=nullptr; }
	full_part=0;
	initial_success=1;
}
char* alloc(size_t size){
	if(full_part+size > my_maxSize){return nullptr; }
	char* res=head+full_part;
	full_part=full_part+size;
	return res;
}
void reset(){
	if (initial_success==1){full_part=0;}
}

void end_work(){
	if (initial_success==1){free(head);}

}