#ifndef MONTY_HEAD_H
#define MONTY_HEAD_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Parsing and lexing "monty_parsing.c" */
char **sep_lines(char *raw);
char *read_file(char *filename);
char **tokenize_line(char *line);

/* Driving/Execution */
int monty_driver(char *parsed_line);
void error_handler(int status, int line_n, char *line);

/* Op code functions. No im not using your function pointers go away */
int push(char *value);
void pall();
int pint(void);
int pop(void);
int swap(void);
int add(void);
int sub(void);
int op_div(void);
int mul(void);
int mod(void);
int pchar(void);

/* useful stuff "monty_help.c" */
void free_stack(stack_t *head);
int is_all_whtspc(char *string);

/* The stack */
extern stack_t *global_stack;

#endif