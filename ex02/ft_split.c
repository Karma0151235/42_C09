#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (is_sep(str[0], sep) == 0)
		count += 1;
	i++;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], sep) == 0 && is_sep(str[i-1], sep) == 1)
			count++;
		i++;
	}
	return (count);
}

char	*wordsplit(char *str, char *sep)
{
	char	*word;
	int	i;

	i = 0;
	while (str[i] != '\0' && is_sep(str[i], sep) == 0)
		i++;
	word = (char *) malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && is_sep(str[i], sep) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**wordarr;
	int	i;
	int	j;

	wordarr = (char **) malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (wordarr == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (is_sep(str[i], charset) == 0)
		{
			wordarr[j] = wordsplit(&str[i], charset);
			while (str[i] != '\0' && is_sep(str[i], charset) == 0)
				i++;
			j++;
		}
		else if (is_sep(str[i], charset) == 1)
			i++;
	}
	wordarr[j] = '\0';
	return (wordarr);
}

int	main(void)
{
	char	*str = "This is a test case";
	char	*sep = " ";
	char	**wordarr = ft_split(str, sep);
	int	i = 0;

	printf("Word Count: %d\n", count_words(str, sep));
	printf("First Word: %s\n", wordsplit(str, sep));
	printf("Original String: %s\n", str);
	printf("Words: \n");
	while (i < count_words(str, sep) - 1)
	{
		printf("%s, ", wordarr[i]);
		free(wordarr[i]);
		i++;
	}
	printf("%s", wordarr[i]);
	free(wordarr);
}