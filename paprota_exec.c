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
    // ft_lstclear(list, free);
    // if(path_buffer)
    //     free(path_buffer);
    return(NULL);
}

void to_look_in(char *str, t_list **list)
{
    t_list *new;
    char *env_holder = getenv(str);
    //getenv to code later
    char *holder = strdup(env_holder);
    holder = strtok(holder, ":");
    while (holder != NULL)
    {
        new = ft_lstnew(strdup(holder));
        ft_lstadd_back(list, new);
        holder = strtok(NULL, ":");
    }
    free(holder);
}
// int main()
// {
    // t_list *list = NULL;
    // to_look_in("PATH", &list);
    // char *str = get_exec_path("grep", &list);
    // printf("%s\n", str);
// }