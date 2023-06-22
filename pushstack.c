#include "monty.h"
/**
* is_integer - checks if a string is a valid integer
* @str: string to check
* Return: 1 if string is a valid integer, 0 otherwise
*/
int is_integer(char *str)
{
int i = 0;
if (str[0] == '-')
i++;
for (; str[i] != '\0'; i++)
{
if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}
/**
* mpush - add node to the stack
* @head: stack head
* @counter: line number
* Return: no return
*/
void mpush(stack_t **head, unsigned int counter)
{
int f = 0, n;
if (shared.arg == NULL || !is_integer(shared.arg))
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
freestack(*head);
exit(EXIT_FAILURE);
}
if (shared.arg[0] == '-')
f++;
n = atoi(shared.arg + f);
if (shared.tflag == 0)
pushnode(head, n);
else
pushqueue(head, n);
}
/**
* mqueue - sets the stack mode to queue (FIFO)
* @head: unused
* @counter: unused
* Return: no return
*/
void mqueue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
shared.tflag = 1;
}
/**
* mstack - sets the stack mode to stack (LIFO)
* @head: unused
* @counter: unused
* Return: no return
*/
void mstack(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
shared.tflag = 0;
}
/**
* pallnode - prints the stack
* @head: stack head
* @counter: unused
* Return: no return
*/
void pallnode(stack_t **head, unsigned int counter)
{
stack_t *curr;
(void)counter;
curr = *head;
while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}
