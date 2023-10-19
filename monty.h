#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

#define null NULL
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Globals - globe vars
 * @filename: as name suggests
 * @fmonty: file
 *
 * Description: noop
 */
typedef struct Globals
{
        char* filename;
        char* errmsg;
        int number;
        FILE* fmonty;
        
} globs;


/***************************/
/***********MONTY.C*********/
void pErr(const char* err);
void* memAlloc(u_int size);
void openfile();
void freeStack(stack_t* stack);

/***************************/
/**********INTERP.C*********/
void interperter();
void checkOpcode(char* op, char* val, u_int linenum);
instruction_t initInstruct( char *op);

/***************************/
/**********OPC-3.C*********/
void push(stack_t** stack,u_int line);
void pall(stack_t** stack,u_int line);
void pint(stack_t** stack,u_int line);
void pop(stack_t** stack,u_int line);
void swap(stack_t** stack,u_int line);
void add(stack_t** stack,u_int line);
void sub(stack_t** stack,u_int line);
void _mod(stack_t** stack,u_int line);
void _mul(stack_t** stack,u_int line);
void _div(stack_t** stack,u_int line);
void pchar(stack_t** stack,u_int line);
void pstr(stack_t** stack,u_int line);
void rotl(stack_t **stack, u_int line);
#endif
