/*
** path.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/src/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Fri Apr 28 14:46:22 2017 Laurent Coloma
** Last update Thu May 18 15:55:55 2017 Laurent Coloma
*/

#include <stdio.h>

#include "aux.h"

/*Function that will parse the env and check if the char * "string"
exist in*/
char *my_getenv(char **env, char *string)
{
  int i;
  int len;
  char *output;

  i = 0;
  len = my_strlen(string) - 1;
  while (env[i])
  {
    if (my_strncmp(string, env[i], len) == 0)
    {
      output = &env[i][len + 2];
      return (output);
    }
    i = i + 1;
  }
  return (NULL);
}
