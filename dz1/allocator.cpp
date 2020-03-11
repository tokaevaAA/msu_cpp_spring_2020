#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

char* head;
int full_part=0;
int my_maxSize=0;


void makeAllocator(size_t maxSize){
	my_maxSize=maxSize;
	full_part=0;
	head=(char*)malloc(maxSize*sizeof(char));
}

char* alloc(size_t size){
	if (head==0) {return nullptr; }
	if (full_part+size > my_maxSize){return nullptr; }
	char* res=head+full_part;
	full_part=full_part+size;
	return res;
}
void reset(){
	if (head!=0){full_part=0;}
}

void end_work(){
	if (head!=0){free(head);}

}