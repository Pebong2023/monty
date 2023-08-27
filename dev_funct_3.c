#include "monty.h"

/**
 * mul - Multiply the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n = (*stack)->next->n * (*stack)->n;
    pop(stack, line_number);
}

/**
 * mod - Calculate the modulus of the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n = (*stack)->next->n % (*stack)->n;
    pop(stack, line_number);
}

/**
 * pchar - Print the character value of the top element of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    if (isascii((*stack)->n))
    {
        printf("%c\n", (*stack)->n);
        return;
    }
    
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    free_all();
    exit(EXIT_FAILURE);
}

/**
 * pstr - Print the string representation of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void) line_number;

    while (tmp && tmp->n != 0 && isascii(tmp->n))
    {
        putchar(tmp->n);
        tmp = tmp->next;
    }
    putchar('\n');
}
