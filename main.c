#include "paprota.h"
/*  a forged algo for a simple shell >>>>
                                            1- get the command line:
                                            >> get the line using getline
                                                - a loop that will keep running until it hits EOF  
                                            >> tokenize it using strtok if there's a new line
                                            2 - parse it
                                            3 - execute
*/

int main()
{
    char *command;
    char **parsed;
    int i;
     // i need a function that will keep returing me the retrived command
    write(1, "$ ", 2);
    while (get_line(&command) != -1)
    {
        if (command[0] != 0)
        {
            if (strcmp(command, "exit") == 0)
                exit(1);
            if (strcmp(command, "env") == 0)
            {
                i = 0;
                while (environ[i])
                {
                    write(1, environ[i], strlen(environ[i]));
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
}
