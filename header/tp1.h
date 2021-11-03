#ifndef HEADER_TP1_H
#define HEADER_TP1_H

#include <time.h>
#include <stdbool.h>

#define MAX_ARG 100
#define MAX_CMD 1000 

typedef struct CommandRecord {

    int pid;
    int status;
    int retval;
    time_t begin;
    time_t end;
    char** argv;

} CommandRecord;

void minibash(void);
void exec_file(char*);
int exec_batch(char**, CommandRecord*);
void exec_file_batch(char*);

CommandRecord* get_record(const int*, CommandRecord*, int);

char** resize_argv(char**);

//char*** file_to_argv(char*, int*);
struct CommandRecord* file_to_record(char*, int*);
char** line_to_argv(char*);

char* argv_to_line(char**);

void display_argv(char**);

int execute(char**);

#endif
