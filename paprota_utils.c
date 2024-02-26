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
*command = malloc(size * sizeof(char));
if (!*command)
return (0);
indicator = getline(command, &size, stdin);
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
if(pid == 0)
{
execve(full_path, parsed, environ);
exit(1);
}
free(full_path);
waitpid(pid, &status, 0);
}
