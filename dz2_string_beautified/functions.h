#ifndef FUNCTIONS_H
#define FUNCTIONS_H


using Handler_for_begin_work = void (*)(); //псевдонимы
using Handler_for_end_work = void (*)();
using Handler_for_ints = void (*)(int num);
using Handler_for_strings = void (*)(const char* tek_token );


void register_handler_for_ints(Handler_for_ints my_handler);
void register_handler_for_strings(Handler_for_strings my_handler);
void register_handler_for_begin_work (Handler_for_begin_work  my_handler);
void register_handler_for_end_work(Handler_for_end_work my_handler);


void parse(const char* text);

#endif
