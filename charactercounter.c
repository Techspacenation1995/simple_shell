/**
 * countCharacters - Counts the occurrences of characters
 * @string: The input string.
 * @character: The character to count.
 * Return: The number of occurrences of the character in the string.
 */
unsigned int countCharacters(char *string, char character)
{
	unsigned int c = 0;

	while (*string != '\0')
	{
		if (*string != character && *(string + 1) == character)
			c++;
		string++;
	}
	return (c + 1);
}
