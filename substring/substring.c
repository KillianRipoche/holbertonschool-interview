#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * match_word - compares a substring of s with a word of given length
 * @s: pointer into the string to scan
 * @word: word to compare against
 * @wlen: length of the word
 *
 * Return: 1 if they match, 0 otherwise
 */
static int match_word(char const *s, char const *word, int wlen)
{
	int i;

	for (i = 0; i < wlen; i++)
		if (s[i] != word[i])
			return (0);
	return (1);
}

/**
 * check_pos - checks if s starts a valid concatenation of all words
 * @s: pointer to the position in the string to check
 * @words: array of words
 * @nb_words: number of words
 * @wlen: length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_pos(char const *s, char const **words, int nb_words, int wlen)
{
	int *used;
	int i, j, found;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);
	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && match_word(s + i * wlen, words[j], wlen))
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * find_substring - finds all indices where a concatenation of all words starts
 * @s: the string to scan
 * @words: array of words to concatenate
 * @nb_words: number of words
 * @n: address to store the number of found indices
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int slen, wlen, total, i, count;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);
	slen = (int)strlen(s);
	wlen = (int)strlen(words[0]);
	total = wlen * nb_words;
	if (slen < total)
		return (NULL);
	result = malloc((slen - total + 1) * sizeof(int));
	if (!result)
		return (NULL);
	count = 0;
	for (i = 0; i <= slen - total; i++)
	{
		if (check_pos(s + i, words, nb_words, wlen))
			result[count++] = i;
	}
	*n = count;
	if (count == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
