#ifndef HEADER_TP1_H
#define HEADER_TP1_H

#define MAX_ARG 100

void minibash(void);
void force_exit(int);

char** line_to_argv(char*);
char* argv_to_line(char**);

int execute(char**);

void display_argv(char**);

#endif