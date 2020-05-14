#include "monty.h"


/**
 * is_all_whtspc - Returns if a string is all whitespace
 * @string: THe string to check
 *
 * Return: 1 if a string is all wtspc, 0 otherwise
 */
int is_all_whtspc(char *string)
{
	int iter = 0;

	if (string == NULL)
		return (1);
	for (; string[iter] != '\0'; iter++)
		if (isspace(string[iter]) == 0)
			return (0);

	return (1);
}
