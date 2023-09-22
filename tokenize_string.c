#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Takes a string and separate its words
 * @str: String that separate into words
 * @delims: delimitors to use to delimit words
 * Return: 20 arrays pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	while (i < wc)
	{
		wordlen = get_word_length(str, delims);
		if (is_delim(*str, delim))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordlen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - it checks if stream has delimitor char.
 * @ch: character in stream.
 * @delim: A pointer to null terminated array of delimitor
 * Return: 0 (failure) and 1 (success)
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delim[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Gets the word length for word in str.
 * @str: String to get word length from current word.
 * @delims: Delimitors to use to delimit words.
 * Return: Word length of current word.
 */

int get_word_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wlen++;
		}
		if (wlen > 0 && is_delim(str[i], delim))
			break;
		i++;
	}
	return (wlen);
}

/**
 * get_word_count - Gets the word count of the string.
 * @str: String to get the word count from.
 * @delims: Delimitors to use to delimit words.
 * Return: the word count of the string.
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - Gets the next words in the string.
 * @str: String to get next word from
 * @delims: Delimitors to use to delimit words.
 * Return: A pointer to first char of the next word.
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while ((*str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
