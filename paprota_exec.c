#include "paprota.h"


void to_lok_in(char *str, t_list **list)
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
