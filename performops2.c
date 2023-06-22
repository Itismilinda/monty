#include "monty.h"
/**
* pcharnode - prints the char at the top of the stack,
* followed by a new line
* @head: stack head
* @line_num: line_number
* Return: no return
*/
void pcharnode(stack_t **head, unsigned int line_num)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
freestack(*head);
exit(EXIT_FAILURE);
}
if ((*head)->n < 0 || (*head)->n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
freestack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", (*head)->n);
}
/**
* modnode - computes the rest of the division of the second
* top element of the stack by the top element of the stack
* @head: stack head
* @line_num: line_number
* Return: no return
*/
void modnode(stack_t **head, unsigned int line_num)
{
stack_t *current;
int len = 0, modu;
current = *head;
while (current)
{
current = current->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
freestack(*head);
exit(EXIT_FAILURE);
}
current = *head;
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
freestack(*head);
exit(EXIT_FAILURE);
}
modu = current->next->n % current->n;
current->next->n = modu;
*head = current->next;
free(current);
}
/**
* pstrnode - prints the string starting at the top of the stack,
* followed by a new
* @head: stack head pointer
* @line_num: line_number
* Return: no return
*/
void pstrnode(stack_t **head, unsigned int line_num)
{
stack_t *current;
(void)line_num;
current = *head;
while (current)
{
if (current->n > 127 || current->n <= 0)
{
break;
}
printf("%c", current->n);
current = current->next;
}
printf("\n");
}
/**
* rotlnode - rotates the stack to the top
*@head: stack head
*@line_num: line_number
*Return: no return
*/
void rotlnode(stack_t **head, unsigned int line_num)
{
stack_t *temp, *last;
(void)line_num;
if (*head == NULL || (*head)->next == NULL)
return;
temp = *head;
last = (*head)->next;
last->prev = NULL;
while (temp->next != NULL)
temp = temp->next;
temp->next = *head;
(*head)->next = NULL;
(*head)->prev = temp;
(*head) = last;
}
/**
* rotrnode - rotates the stack to the bottom
*@head: stack head
*@line_num: unused
*Return: no return
*/
void rotrnode(stack_t **head, unsigned int line_num)
{
stack_t *rot;
(void)line_num;
if (*head == NULL || (*head)->next == NULL)
return;
rot = *head;
while (rot->next != NULL)
rot = rot->next;
rot->next = *head;
rot->prev->next = NULL;
rot->prev = NULL;
(*head)->prev = rot;
*head = rot;
}
