#include "monty.h"
/**
* pushnode - pushes a node to the top of the stack in a linked list
* @head: the pointer to the hea node
* @value: the dataa to be pushed onto the stack
* Return: no return
*/
void pushnode(stack_t **head, int value)
{
stack_t *new_node, *curr;
curr = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (curr)
curr->prev = new_node;
new_node->n = value;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}
