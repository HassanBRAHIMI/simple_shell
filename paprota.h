#ifndef PAPROTA_H
# define PAPROTA_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct node - singly linked list
 * @content: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct node
{
char *content;
struct node *next;
} t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (del)(void *));
t_list	*ft_lstlast(t_list *lst);
void ft_free(char **splitted);
int	ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
char *ft_strcat(char *dest, const char *src);
t_list	*ft_lstnew(void *content);
int get_line(char **command);
void ft_excec(char **parsed);
char **parse_da_shit(char *command);
void ft_excec(char **parsed);
void to_look_in(char *str, t_list **list);
char *get_exec_path(char *file, t_list **list);

#endif
