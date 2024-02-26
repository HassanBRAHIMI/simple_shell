#ifndef PAPROTA_H
# define PAPROTA_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

typedef struct node
{
    char *content;
    struct node *next;
} t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (del)(void *));
void	ft_lstdelone(t_list *lst, void (del)(void *));
t_list	*ft_lstlast(t_list *lst);
void ft_free(char **splitted);
t_list	*ft_lstnew(void *content);
int get_line(char **command);
void ft_excec(char **parsed);
char **parse_da_shit(char *command);
void ft_excec(char **parsed);
void to_look_in(char *str, t_list **list);
char *get_exec_path(char *file, t_list **list);

#endif
