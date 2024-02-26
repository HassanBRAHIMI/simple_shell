#include "paprota.h"

/**
 * ft_strncmp - compares at most the first n bytes of str1 and str2
 * @str1: the first string to be compared
 * @str2: the second string to be compared
 * @n: the maximum number of bytes to be compared
 *
 * Return: if str1 < str2, return a negative value;
 * if str1 > str2, return a positive value;
 * if str1 = str2, return 0.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/**
 * ft_strchr - locates the first occurrence of c in the string pointed to by s
 * @s: the string to be scanned
 * @c: the character to be searched
 *
 * Return: a pointer to the first occurrence of the character c in the string s,
 * or NULL if the character is not found
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != uc)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
