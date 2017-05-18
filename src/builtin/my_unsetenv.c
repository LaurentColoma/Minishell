/*
** my_unsetenv.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 14:24:16 2017 Laurent Coloma
** Last update Thu May 18 15:50:51 2017 Laurent Coloma
*/

#include "aux.h"
#include <stdlib.h>

/*This function will parse the env and see if the input_wordtab[1] exist
and delete it from the env*/
char **my_unsetenv(char **env, char **input_wordtab)
{
  int		i;
  int		len;
  int		is_free;

  i = 0;
  is_free = 0;
  len = my_strlen(input_wordtab[1]) - 1;
  if (input_wordtab[1])
    {
      while (env[i])
	{
	  if ((my_strncmp(env[i], input_wordtab[1], len) == 0))
	    {
	      env[i] = NULL;
	      is_free = 1;
	    }
	  if (is_free == 1)
	    env[i] = env[i + 1];
	  i++;
	}
    }
  return (env);
}
