#include "paprota.h"
/**
 * ft_free - frees 2D arrays
 * @splitted: the 2D array
 *
 * Return: void
*/
void ft_free(char **splitted)
{
int c;

c = 0;

if (!splitted)
{
return;
}
while (splitted[c])
{
free(splitted[c]);
c++;
}
free(splitted);
}

/**
 * get_line - gets the command line
 * @command: the command line itself
 *
 * Return: to check the value of the command
*/
int get_line(char **command)
{
size_t size;
int indicator;

size = 1024;
*command = malloc(size *sizeof(char));
if (!*command)
return (0);
indicator = getline(command, &size, stdin);
if (indicator < 0)
    free(*command);
if (indicator > 0 && (*command)[indicator - 1] == '\n')
(*command)[indicator - 1] = '\0';
return (indicator);
}

/**
 * parse_da_shit - it parses the command
 * @command: the commmand
 *
 * Return: the parsed command on succes and null on failure
*/
char **parse_da_shit(char *command)
{
char **arr;
char *token;
int i;
arr = ft_calloc(sizeof(char *), 1024);
token = strtok(command, " ");
if (!token)
{
ft_free(arr);
return (NULL);
}
i = 0;
while (token)
{
arr[i] = ft_strdup(token);
token = strtok(NULL, " ");
i++;
}
arr[i] = NULL;
return (arr);
}
/**
 * ft_excec - it executes the parsed command
 * @parsed: the parsed command
 *
 * Return: none
*/
void ft_excec(char **parsed)
{
char *full_path;
int status;
int pid;
t_list *exec_directories = NULL;
to_look_in("PATH", &exec_directories);
full_path = get_exec_path(parsed[0], &exec_directories);
pid = fork();
if (pid == 0)
{
execve(full_path, parsed, environ);
free(full_path);
ft_free(parsed);
ft_lstclear(&exec_directories, free);
exit(1);
}
free(full_path);
waitpid(pid, &status, 0);
}

/**
 * get_env - retrieves the value of the environment variable named by name
 * @name: the name of the environment variable
 *
 * Return: a pointer to the value of the environment variable,
 * or NULL if the environment variable does not exist
 */
char *get_env(const char *name)
{
int i = 0;
char *env_var;
int len = ft_strlen(name);

while (environ[i] != NULL)
{
env_var = ft_strchr(environ[i], '=');
if (env_var && ft_strncmp(environ[i], name, len) == 0)
{
return (env_var + 1);
}
i++;
}
return (NULL);
}
