#ifndef HEADER_TP1_H
#define HEADER_TP1_H

#define MAX_ARG 100
#define MAX_CMD 1000

void minibash(void);
void exec_file(char*);

char** resize_argv(char**);

char*** file_to_argv(char*, int*);
char** line_to_argv(char*);

char* argv_to_line(char**);

void display_argv(char**);

int execute(char**);

#endif
