#include "paprota.h"

/**
 * main - entry point
 *
 * Return: 0
*/
int main(void)
{
char *command = NULL;
int write_res;
char **parsed = NULL;
int i = 0;

write_res = 0;
write_res = write(1, "$ ", 2);
if (write_res == -1) {
    perror("write");
    return 1;
}
while (get_line(&command) != -1)
{
if (command[0] != 0)
{
if (ft_strcmp(command, "exit") == 0)
{
free(command);
exit(-1);
}
if (ft_strcmp(command, "env") == 0)
{
i = 0;
while (environ[i])
{
write_res = write(1, environ[i], ft_strlen(environ[i]));
if (write_res == -1) {
    perror("write");
    return 1;
}
write_res = write(1, "\n", 1);
if (write_res == -1) {
    perror("write");
    return 1;
}
i++;
}
}
parsed = parse_da_shit(command);
free(command);
if (parsed)
{
ft_excec(parsed);
ft_free(parsed);
}
}
write_res = write(1, "$ ", 2);
if (write_res == -1) {
    perror("write");
    return 1;
}
}
return (0);
}
