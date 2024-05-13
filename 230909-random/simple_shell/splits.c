#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splits(char *str, char *delim)
{
	int i, words;
	const char *token;
	char **words_array;

	char *strcopy1 = strdup(str);
	char *strcopy2 = strdup(str);

	token = strtok(strcopy1, delim);

	words = 0;
	while (token)
	{
		words++;
		token = strtok(NULL, delim);
	}

	words_array = malloc(sizeof(char *) * words + 1);
	if (!words_array)
		return (NULL);

	token = strtok(strcopy2, delim);

	i = 0;
	while (token)
	{
		words_array[i] = strdup(token);
		if (!words_array[i])
			return (NULL);
		i++;
		token = strtok(NULL, delim);
	}
	words_array[words] = NULL;

	return (words_array);
}

int main(int argc, char **argv)
{
        char **words = splits(argv[1], " ");
        int index;

        if (words == NULL)
        {
                printf("Error splitting string\n");
                return (1);
        }

	if (argc != 2)
	{
		printf("Error| Usage: %s \"string\"\n", argv[0]);
		return (2);
	}

        index = 0;
        while (words[index] != NULL)
        {
                printf("%s\n", words[index]);
                index++;
        }

        index = 0;
        while (words[index] != NULL)
        {
                free(words[index]);
                index++;
        }
        free(words);

        return (0);
}
