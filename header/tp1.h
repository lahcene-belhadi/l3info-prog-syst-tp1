#ifndef HEADER_TP1_H
#define HEADER_TP1_H

#define MAX_ARG 100

void minibash(void);

char** resize_argv(char**);

char** file_to_argv(char*, int*);
char** line_to_argv(char*);

char* argv_to_line(char**);

void display_argv(char**);

int execute(char**);

#endif
