#include "monty.h"
/**
* pushqueue - add node to the tail stack
* @value: new_value
* @head: head of the stack
* Return: no return
*/
void pushqueue(stack_t **head, int value)
{
stack_t *current, *new_node;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
}
else
{
current = *head;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_node;
new_node->prev = current;
}
}
/**
* pintnode - prints the data at the top of the stack
* @head: the head pointer to the top node
* @line_num: the number of the line for the bytecode
*/
void pintnode(stack_t **head, unsigned int line_num)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
/**
* popnode - prints the top
* @head: stack head
* @line_num: line_number
* Return: no return
*/
void popnode(stack_t **head, unsigned int line_num)
{
stack_t *temp;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
exit(EXIT_FAILURE);
}
temp = *head;
*head = temp->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
}
/**
* swapnode - swaps the top two elements of the stack.
* @head: the pointer to the head stack
* @line_num: the line number of the bytecode
*/
void swapnode(stack_t **head, unsigned int line_num)
{
stack_t *temp;
int swp;
if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
temp = *head;
swp = temp->n;
temp->n = temp->next->n;
temp->next->n = swp;
}
