#include "monty.h"

void f_add(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;

    /* Calculate the length of the stack */
    while (h)
    {
        h = h->next;
        len++;
    }

    /* Check if there are at least 2 elements in the stack */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    h = *head;
    aux = h->n + h->next->n;

    /* Update the second element with the sum and remove the first element */
    h->next->n = aux;
    *head = h->next;
    free(h);
}

