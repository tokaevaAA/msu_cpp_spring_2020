#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int cnt_ints=0;
int cnt_strings=0;
int mas_of_ints[10];
int has_my_handler_for_end_work=0;


void my_func_for_begin(){
	printf("Hello from my_register_for_begin_work\n\n");

}

void my_func_for_end(){
	printf("Hello from my_register_for_end_work\n\n");
	has_my_handler_for_end_work=1;


}

void my_func_for_ints(int num){
	//int num=atoi(tek_word);
	printf("We have int: %d\n", num);
	mas_of_ints[cnt_ints]=num;
	cnt_ints+=1;

}

void my_func_for_strings(const char* tek_word){
	cnt_strings+=1;

}

int main(){
	printf("Hello from main!\n");


	//test1
	cnt_ints=0;
	cnt_strings=0;
	parse("12 ddd f4f");
	printf("cnt_ints=%d cnt_strings=%d \n",cnt_ints, cnt_strings);
	if ((cnt_ints != 0) || (cnt_strings !=0)){printf("Error: no my_functions registered, but cnt_ints != 0 or cnt_strings !=0!\n"); return 1; }
	else {printf("test1: ok\n");}

	//test2
	cnt_ints=0;
	cnt_strings=0;
	register_handler_for_begin_work (my_func_for_begin);
	register_handler_for_ints (my_func_for_ints);

	parse("123 abc 77 45d 6789 ss 45 pp");

	printf("cnt_ints=%d cnt_strings=%d \n",cnt_ints, cnt_strings);

	printf("mas_of_ints[1]=%d\n",mas_of_ints[1]);
	
	if ((cnt_ints != 4) || (cnt_strings !=0)){printf("Error:  cnt_ints != 4 or cnt_strings !=0 !\n"); return 2; }
	else {printf("test2: ok\n");}

	//test3
	if (mas_of_ints[1] != 77){printf("Error:  mas_of_ints[1] != 77 \n"); return 3; }
	else {printf("test3: ok\n");}


	//test4
	cnt_ints=0;
	cnt_strings=0;
	register_handler_for_end_work(my_func_for_end);
	parse("456");
	if(has_my_handler_for_end_work != 1){printf("Error: has_my_handler_for_end_work!=1\n"); return 4;}
	else {printf("test4: ok\n");}

	//test5
	cnt_ints=0;
	cnt_strings=0;
	register_handler_for_strings (my_func_for_strings);
	parse("  ffd     554d 6tg 776");
	printf("cnt_ints=%d, cnt_strings=%d\n", cnt_ints, cnt_strings);
	if ((cnt_ints != 1) || (cnt_strings !=3)){printf("Error: cnt_ints != 1 or cnt_strings !=3 !\n"); return 5; }
	else {printf("test5: ok\n");}

		
	printf("\nGoodbuy from main!\n");
	return 0;

}
