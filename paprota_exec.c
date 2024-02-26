#include "paprota.h"

/*
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
            return(ft_strdup(file));
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
    if(path_buffer)
        free(path_buffer);
    return(NULL);
}
/*
 * to_look_in - it looks for the directories in path
 * @str: the enviroment variable name
 * @list: the list of directories
 * 
 * Return: none
*/
void to_look_in(char *str, t_list **list)
{
    //getenv to code later
    char *holder = ft_strdup(getenv(str));
    char *tmp = holder;
    holder = strtok(holder, ":");
    while (holder != NULL)
    {
        ft_lstadd_back(list, ft_lstnew(ft_strdup(holder)));
        holder = strtok(NULL, ":");
    }
    free(tmp);
}
