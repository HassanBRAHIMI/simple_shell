#include "paprota.h"

void ft_free(char **splitted)
{
	int	c;

	c = 0;
	while (splitted[c])
	{
		free(splitted[c]);
		c++;
	}
	free(splitted);
}
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
    token = strtok(command, " ");
    if (!token)
    {
        ft_free(arr);
        return (NULL);
    }
    i = 0;
    while (token)
    {
        arr[i] = strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
    arr[i] = NULL;
    return (arr);
}
void ft_excec(char **parsed)
{
    char *full_path;
    int status;
    int pid;
    t_list *exec_directories = NULL;
    to_look_in("PATH", &exec_directories);
    full_path = get_exec_path(parsed[0], &exec_directories);
    pid = fork();
    if(pid == 0)
    {
        execve(full_path, parsed, environ);
        exit(1);
    }
    // if (full_path && strcmp(full_path, parsed[0]))
    free(full_path);
    waitpid(pid, &status, 0);
}
