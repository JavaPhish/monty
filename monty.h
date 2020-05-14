#ifndef MONTY_HEAD_H
#define MONTY_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

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
void monty_driver(char **parsed_lines);

/* Op code functions. No im not using your function pointers go away */
void push(int value);
void pall();

/* useful stuff "monty_help.c" */
int _contains(char *str, char *keyword);
void free2d_str(char **arr);
int verify_malloc(void *mal);
void free_stack(stack_t *head);

/* The stack */
extern stack_t *global_stack;

#endif