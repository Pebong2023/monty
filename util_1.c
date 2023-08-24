#include "monty.h"

/**
 * start_vars - Initialize global variables
 * @var: Pointer to global variables
 * Return: 0 for success, 1 for failure
 */
int start_vars(vars *var)
{
    var->file = NULL;
    var->buff = NULL;
    var->tmp = 0;
    var->dict = create_instru();
    if (var->dict == NULL)
        return (EXIT_FAILURE);
    var->head = NULL;
    var->line_number = 1;
    var->MODE = 0;

    return (EXIT_SUCCESS);
}

/**
 * create_instru - Create a new functions dictionary
 * Return: Pointer to the dictionary
 */
instruction_t *create_instru()
{
    instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

    if (!ptr)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    ptr[0].devcode = "pall"; ptr[0].f = pall;
    ptr[1].devcode = "push"; ptr[1].f = push;
    /* ... (remaining entries) */
    ptr[17].devcode = NULL; ptr[17].f = NULL;

    return (ptr);
}

/**
 * call_funct - Call functions based on opcode
 * @var: Pointer to global variables
 * @devcode: Command to execute
 * Return: 0 for success, 1 for failure
 */
int call_funct(vars *var, char *devcode)
{
    int i;

    for (i = 0; var->dict[i].devcode; i++)
    {
        if (strcmp(devcode, var->dict[i].devcode) == 0)
        {
            if (!var->dict[i].f)
                return (EXIT_SUCCESS);
            var->dict[i].f(&var->head, var->line_number);
            return (EXIT_SUCCESS);
        }
    }

    if (strlen(devcode) != 0 && devcode[0] != '#')
    {
        fprintf(stderr, "L%u: unknown instruction %s\n",
                var->line_number, devcode);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/**
 * free_all - Free allocated memory
 * Return: None
 */
void free_all(void)
{
    if (var.buff != NULL)
        free(var.buff);
    if (var.file != NULL)
        fclose(var.file);
    free(var.dict);

    if (var.head != NULL)
    {
        while (var.head->next != NULL)
        {
            var.head = var.head->next;
            free(var.head->prev);
        }
        free(var.head);
    }
}

/**
 * _isdigit - Check if a string contains only digits
 * @string: String to validate
 * Return: 0 for success, 1 for failure
 */
int _isdigit(char *string)
{
    int i;

    for (i = 0; string[i]; i++)
    {
        if (string[i] < 48 || string[i] > 57)
            return (1);
    }
    return (0);
}

