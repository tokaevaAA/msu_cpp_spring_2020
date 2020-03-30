#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "functions.h"

using namespace std;

//using Handler_for_begin_work = void (*)(); //псевдонимы
//using Handler_for_end_work = void (*)();
//using Handler_for_ints = void (*)(int num);
//using Handler_for_strings = void (*)(const char* tek_token );


Handler_for_begin_work my_handler_for_begin_work = nullptr;	//переменные куда класть зарегистрированный хэндлер
Handler_for_end_work my_handler_for_end_work = nullptr;
Handler_for_ints my_handler_for_ints = nullptr;
Handler_for_strings my_handler_for_strings = nullptr;


void
register_handler_for_ints (Handler_for_ints my_handler)
{
  my_handler_for_ints = my_handler;

}

void
register_handler_for_strings (Handler_for_strings my_handler)
{
  my_handler_for_strings = my_handler;

}

void
register_handler_for_begin_work (Handler_for_begin_work my_handler)
{
  my_handler_for_begin_work = my_handler;

}

void
register_handler_for_end_work (Handler_for_end_work my_handler)
{
  my_handler_for_end_work = my_handler;

}




void
parse (const char *text)
{
  //printf("\nparsing this: %s\n",text);

  bool looks_like_number = 0;
  if (text[0] >= '0' && text[0] <= '9')
    {
      looks_like_number = 1;
    }


  if (my_handler_for_begin_work != nullptr)
    {
      my_handler_for_begin_work ();
    }

  std::string tek_token;

  int i = 0;
  char tek;

  int my_len = strlen (text);

  int j = 0;
  while (text[j] == ' ')
    {
      j++;
    }

  i = j;
  tek = text[i];

  while (tek)
    {
      if (tek == ' ')
	{
	  //printf("new word %s : looks_like_number=%d!\n",tek_token.c_str(),looks_like_number); 

	  if (looks_like_number == 1)
	    {
	      if (my_handler_for_ints != nullptr)
		{
		  int num = atoi (tek_token.c_str ());
		  my_handler_for_ints (num);
		}
	    }


	  if (looks_like_number == 0)
	    {
	      if (my_handler_for_strings != nullptr)
		{
		  my_handler_for_strings (tek_token.c_str ());
		}
	    }


	  tek_token.clear ();


	  j = i;
	  while ((j <= (my_len - 1)) && (text[j] == ' '))
	    {
	      j++;
	    }

	  i = j - 1;

	  if ((i < (my_len - 1))
	      && (text[i + 1] >= '0' && text[i + 1] <= '9'))
	    {
	      looks_like_number = 1;
	    }

	}

      else if (!(tek >= '0' && tek <= '9'))
	{
	  looks_like_number = 0;
	}

      tek_token += tek;

      i = i + 1;
      tek = text[i];


    }

  //printf("new word %s : looks_like_number=%d!\n",tek_token.c_str(),looks_like_number); 

  if (looks_like_number == 1)
    {
      if (my_handler_for_ints != nullptr)
	{
	  int num = atoi (tek_token.c_str ());
	  my_handler_for_ints (num);
	}
    }


  if (looks_like_number == 0)
    {
      if (my_handler_for_strings != nullptr)
	{
	  my_handler_for_strings (tek_token.c_str ());
	}
    }





  //printf("parse ended! \n");
  //printf("my_handler_for_end_work =%p\n",my_handler_for_end_work);
  if (my_handler_for_end_work != nullptr)
    {
      my_handler_for_end_work ();
    }



}
