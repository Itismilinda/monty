#include "monty.h"
/**
* fileError - error message to be printed if the file cannot be opened
* @filename: name of the file that couldn't be opened
*/
void fileError(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
