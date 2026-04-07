#include "regex.h"

/**
 * regex_match - checks whether a pattern matches a string
 * @str: the string to scan
 * @pattern: the regular expression (supports '.' and '*')
 *
 * Return: 1 if pattern matches string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return (regex_match(str + 1, pattern));
		return (0);
	}

	if (*str != '\0' && (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
