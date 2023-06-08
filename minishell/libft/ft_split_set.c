#include "libft.h"

/*This function is called with a char from str and the charset string.
 *Verifies if char is present in charset. */ 
int	ft_is_delimiter(char c, char *delims)
{
	int	i;

	i = 0;
	while (delims[i])
	{
		if (delims[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/*Defines the index of the next char of str present in charset.
 * At the first iteration, i is the index of the first char of charset found in str. */
int	ft_strlen_mod(char *str, char *delims)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_delimiter(str[i], delims)) //remember: !ft_is_delimiter means that the char isnt found in charset
		i++;
	return (i);
}

/*This function is called with str and the index of the next char of str present in charset */
char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup; //string is declared

	i = 0;
	dup = (char *)malloc(n + 1); //string is initialized with the lenght + 1 for the null character
	if (dup == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*Count the number of strings the generated array will have. Count it by determining 
 * the number of characters from charset are present in str. */
int	ft_wordcount(char *str, char *delims)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_is_delimiter(str[i], delims))
			i++;
		len = ft_strlen_mod(str + i, delims);
		if (len > 0)
			words++;
		i += len;
	}
	return (words);
}

char	**ft_split_set(char *str, char *charset)
{
	int		i;
	int		k;
	int		len;
	char	**words;	//declare array to store splited strings

	k = 0;
	i = 0;
	/*Initializes array with the size returned by ft_wordcount + 1(NULL) */
	words = (char **)malloc((ft_wordcount(str, charset) + 1) * sizeof(char *));
	if (words == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[i]) //iterate through the string
	{
		while (str[i] && ft_is_delimiter(str[i], charset)) //while char in i position isn't a char present in charset - i++
			i++;
		/*find out the index of separators - at first, str + i points to index 0.Then, acording with the pointer arithmetic points 
		 * to 0 + len...*/
		len = ft_strlen_mod(str + i, charset); 
		if (len > 0)
			words[k++] = ft_strndup(str + i, len); //copies str, to the index k of **words, till reach the first char present in charset.
		i += len; //define the index of str for the first separator to continue iterating and searching for the next char from charset.
	}
	words[k] = NULL;
	return (words);
}
/*%%%%%% THIS PART IS ONLY FOR TEST PURPOSIS %%%%%%% */
/* 
void ft_print_array(char **array)
{
	int i;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; array[i] != NULL; i++)
        {
			printf("%d - %s\n", i, array[i]);
            //free (array[i]);
        }
	}
} */
/*
int main(void)
{
    char *s = "ls -a | wc -l >> file1";
    char **splited = ft_split(s, " ");
	ft_print_array(splited);
    free(splited);
} */