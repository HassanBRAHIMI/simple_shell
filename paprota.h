#ifndef PAPROTA_H
# define PAPROTA_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_line(char **command);
void ft_excec(char **parsed);
char **parse_da_shit(char *command);
#endif