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
     // i need a function that will keep returing me the retrived command
    write(1, "$ ", 2);
    while (get_line(&command) != -1)
    {
        parsed = parse_da_shit(command);
        // printf("%s\n", parsed[0]);
        ft_excec(parsed);
        write(1, "$ ", 2);
    } 
}