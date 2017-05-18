/*
** my_env.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 14:13:27 2017 Laurent Coloma
** Last update Thu May 18 15:41:37 2017 Laurent Coloma
*/

#include "aux.h"

/*Display the env*/
char **my_env(char **env, char **input_wordtab)
{
  int i;

  i = 0;
  (void) input_wordtab;
  while (env[i])
  {
    my_putstr(env[i], 1);
    my_putchar('\n', 1);
    i = i + 1;
  }
  return (env);
}
