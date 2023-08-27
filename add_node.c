#include "monty.h"

void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Update previous pointer of the existing head node */
    if (aux)
        aux->prev = new_node;

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    /* Update head to point to the new node */
    *head = new_node;
}

