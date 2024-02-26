#include "paprota.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(void)
{
char *command = NULL;
char **parsed = NULL;
int i = 0;
write(1, "$ ", 2);
while (get_line(&command) != -1)
{
if (command[0] != 0)
{
if (ft_strcmp(command, "exit") == 0)
exit(1);
if (ft_strcmp(command, "env") == 0)
{
i = 0;
while (environ[i])
{
write(1, environ[i], ft_strlen(environ[i]));
write(1, "\n", 1);
i++;
}
}
parsed = parse_da_shit(command);
if (parsed)
{
ft_excec(parsed);
ft_free(parsed);
}
}
free(command);
write(1, "$ ", 2);
}
return (0);
}
