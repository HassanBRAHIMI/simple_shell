#include "paprota.h"

int get_line(char **command)
{
    size_t size;
    int indicator;

    size = 1024;
    *command = malloc(size * sizeof(char));
    if (!*command)
        return (0);
    indicator = getline(command, &size, stdin);
    if (indicator > 0 && (*command)[indicator - 1] == '\n')
        (*command)[indicator - 1] = '\0';
    return (indicator);
}

char **parse_da_shit(char *command)
{
    char **arr;
    char *token;
    int i;
    arr = malloc(sizeof (char *) * 1024);
    if (command[0] == '\n')
    {
        arr[0] = ''
    }
    token = strtok(command, " ");
    i = 0;
    while (token)
    {
        arr[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    arr[i] = NULL;
    return (arr);
}
void ft_excec(char **parsed)
{
    int status;
    t_list *exec_directories = NULL;
    to_look_in("PATH", &exec_directories);
    char *full_path = get_exec_path(parsed[0], &exec_directories);
    int pid = fork();
    if(pid == 0)
    {
        execve(full_path, parsed, environ);
        exit(1);
    }
    waitpid(pid, &status, 0);
}