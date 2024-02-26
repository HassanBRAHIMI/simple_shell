#include "paprota.h"

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
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char *ft_strcpy(char *dest, const char *src)
{
    char *save = dest;
    while((*dest++ = *src++));
    return save;
}
char *ft_strcat(char *dest, const char *src) 
{
    char *rdest = dest;

    while (*dest)
      dest++;
    while ((*dest++ = *src++))
      ;
    return rdest;
}