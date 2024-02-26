#include "paprota.h"
/**
 * ft_lstadd_back - add a node at the end of file
 * @lst: the list
 * @new: a node
 *
 * Return: none
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!new || !lst)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	tail = ft_lstlast(*lst);
	tail->next = new;
}

/**
 * ft_lstclear - clear the linkes list
 * @lst: the list
 * @del: the func to do so
 * Return: none
*/
void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

/**
 * ft_lstnew - add a node
 * @content: the content
 *
 * Return: the created node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
