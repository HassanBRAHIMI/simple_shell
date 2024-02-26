#include "paprota.h"

char *get_exec_path(char *file, t_list **list)
{
    //list is the list of directories
    //file is the command name
    t_list *head = *list;
        // write(1, "ok\n", 3);
    char *path_buffer = NULL;
    struct stat stat_box;
    //i gotta find the absolute path for my excecutable
    while (head)
    {
        if (access(file, X_OK | F_OK) == 0)
        {
            ft_lstclear(list, free);
            return(strdup(file));
        }

        if (path_buffer)
        {
            free(path_buffer);
            path_buffer = NULL;
        }
        path_buffer = malloc(strlen(head->content) + strlen(file) + 2);
        strcpy(path_buffer, head->content);
        strcat(path_buffer, "/");
        strcat(path_buffer, file);
        strcat(path_buffer, "\0");
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

void to_look_in(char *str, t_list **list)
{
    //getenv to code later
    char *holder = strdup(getenv(str));
    char *tmp = holder;
    holder = strtok(holder, ":");
    while (holder != NULL)
    {
        ft_lstadd_back(list, ft_lstnew(strdup(holder)));
        holder = strtok(NULL, ":");
    }
    free(tmp);
}
