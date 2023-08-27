#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int tmp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}

/**
 * add - Add the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n = (*stack)->next->n + (*stack)->n;
    pop(stack, line_number);
}

/**
 * sub - Subtract the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n = (*stack)->next->n - (*stack)->n;
    pop(stack, line_number);
}

/**
 * divi - Divide the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void divi(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n = (*stack)->next->n / (*stack)->n;
    pop(stack, line_number);
}

