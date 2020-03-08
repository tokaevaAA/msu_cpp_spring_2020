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
	if(head==0){printf("Not enough memory! Try once more with less memory.\n"); 			    			    head=nullptr; }
	full_part=0;
	initial_success=1;
}
char* alloc(size_t size){
	if(full_part+size > my_maxSize){
			printf("In alloc: full_part+size = %ld , my_maxSize=%d\n",full_part+size,my_maxSize);
			printf("No more space in initial mas! Ask for less memory or  Try reset!\n"); 
			return nullptr; }
	char* res=head+full_part;
	full_part=full_part+size;
	return res;
}
void reset(){
	full_part=0;
}