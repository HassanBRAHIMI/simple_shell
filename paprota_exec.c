#include "paprota.h"

/**
 * get_exec_path - it extracts the full path of our executable
 * @file: the command or the exec file
 * @list: the list that we will store the directories of our path
 *
 * Return: the full path on succes or null on failure
*/
char *get_exec_path(char *file, t_list **list)
{
t_list *head;
char *path_buffer;
struct stat stat_box;

head = *list;
path_buffer = NULL;
while (head)
{
if (access(file, X_OK | F_OK) == 0)
{
ft_lstclear(list, free);
return (ft_strdup(file));
}
if (path_buffer)
{
free(path_buffer);
path_buffer = NULL;
}
path_buffer = malloc(ft_strlen(head->content) + ft_strlen(file) + 2);
ft_strcpy(path_buffer, head->content);
ft_strcat(path_buffer, "/");
ft_strcat(path_buffer, file);
ft_strcat(path_buffer, "\0");
if (stat(path_buffer, &stat_box) == 0 && access(path_buffer, X_OK) == 0)
{
ft_lstclear(list, free);
return (path_buffer);
}
head = head->next;
}
perror(file);
ft_lstclear(list, free);
if (path_buffer)
free(path_buffer);
return (NULL);
}

/**
 * to_look_in - it looks for the directories in path
 * @str: the enviroment variable name
 * @list: the list of directories
 *
 * Return: none
*/
void to_look_in(char *str, t_list **list)
{
char *holder = ft_strdup(get_env(str));
char *tmp = holder;
holder = strtok(holder, ":");
while (holder != NULL)
{
ft_lstadd_back(list, ft_lstnew(ft_strdup(holder)));
holder = strtok(NULL, ":");
}
free(tmp);
}

/**
 * ft_calloc - allocates a chunck of zroed memory
 * @count: the count
 * @size: the size
 *
 * Return: none
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_memset(s, 0, count * size);
	return (s);
}

/**
 * ft_memset - it fills a chunck of memory with 0s
 * @b: the b
 * @c: the c
 * @len: the len
 *
 * Return: none
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*kda;
	size_t			i;

	i = 0;
	kda = b;
	while (i < len)
	{
		kda[i] = (unsigned char)c;
		i++;
	}
	return (kda);
}
