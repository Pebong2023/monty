#include "monty.h"

/**
 * rotl - Rotate the stack to the left
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tm = *stack;
    (void) line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;
    
    (*stack)->next->prev = NULL;
    
    while (tm->next)
        tm = tm->next;
    
    tm->next = *stack;
    (*stack) = (*stack)->next;
    tm->next->next = NULL;
    tm->next->prev = tm;
}

/**
 * rotr - Rotate the stack to the right
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void) line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;

    (*stack)->prev = tmp;
    *stack = tmp;
}

/**
 * stack - Set the stack mode
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    (void) stack;

    var.MODE = 0;
}

/**
 * queue - Set the queue mode
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    (void) stack;

    var.MODE = 1;
}

