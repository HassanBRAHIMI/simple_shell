#include "paprota.h"

/**
 * ft_strcmp - compares 2 strings
 * @str1: str1
 * @str2: str2
 *
 * Return: diff or 0
*/
int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int i;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * ft_strdup - dup a string
 * @s1: str1
 *
 * Return: dup of 0
*/
char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * ft_strlen - len of a string
 * @str: str
 *
 * Return: len
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * ft_strcmp - copyy one to one
 * @str1: dest
 * @str2: src
 *
 * Return: shiit
*/
char *ft_strcpy(char *dest, const char *src)
{
char *save;
int i;

save = dest;
i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (save);
}

/**
 * ft_strcat - concatenate 2 strings
 * @dest: dest
 * @src: src
 *
 * Return: shit
*/
char *ft_strcat(char *dest, const char *src)
{
char *rdest;
int i;

rdest = dest;
while (*dest)
{
dest++;
}
i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (rdest);
}
