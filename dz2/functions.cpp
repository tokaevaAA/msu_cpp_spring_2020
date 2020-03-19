#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//using Handler_for_begin_work = void (*)(); //псевдонимы
//using Handler_for_end_work = void (*)();
//using Handler_for_ints = void (*)(const char* tek_token);
//using Handler_for_strings = void (*)(const char* tek_token );


Handler_for_begin_work   my_handler_for_begin_work=0; //переменные куда класть зарегистрированный хэндлер
Handler_for_end_work   my_handler_for_end_work=0;
Handler_for_ints    my_handler_for_ints=0;
Handler_for_strings   my_handler_for_strings=0;


void register_handler_for_ints(Handler_for_ints my_handler){
	my_handler_for_ints=my_handler;

}

void register_handler_for_strings(Handler_for_strings my_handler){
	my_handler_for_strings=my_handler;

}

void register_handler_for_begin_work (Handler_for_begin_work  my_handler){
	my_handler_for_begin_work =my_handler;

}

void register_handler_for_end_work(Handler_for_end_work my_handler){
	my_handler_for_end_work=my_handler;

}




void parse(const char* text){
	printf("\nparsing this: %s\n",text);

	int looks_like_number=1;

	if (my_handler_for_begin_work !=0 ) {my_handler_for_begin_work(); }

	char* str=(char*)malloc((strlen(text)+1)*sizeof(char));
	strcpy(str, text);
	
	char sep [10]= " ";
	char* tek_token;
	tek_token = strtok (str, sep);
	while (tek_token != NULL){
      	
		looks_like_number=1;

		for(int j=0; j<strlen(tek_token); j=j+1){
		if (!(tek_token[j] >= '0' && tek_token[j] <= '9')) {looks_like_number=0;}
		}
  		

		if(looks_like_number==1) {if (my_handler_for_ints !=0 ){my_handler_for_ints(tek_token); }}
								

		if(looks_like_number==0) {if (my_handler_for_strings !=0 ){my_handler_for_strings(tek_token); }}
				

      		tek_token = strtok (NULL, sep);
   	}

	

	printf("parse ended! \n");
	printf("my_handler_for_end_work =%p\n",my_handler_for_end_work);
	if (my_handler_for_end_work !=0 ) {my_handler_for_end_work(); }



}
