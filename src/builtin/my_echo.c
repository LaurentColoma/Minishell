/*
** my_echo.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 14:45:42 2017 Laurent Coloma
** Last update Thu May 18 15:41:18 2017 Laurent Coloma
*/

#include "aux.h"

/*Echo builtin,
there is the only the -n and the normal function implement here
-n don't put a '\n' when you output the char put in argument*/
char **my_echo(char **env, char **input_wordtab)
{
  int nb_word;
  int i;

  (void) env;
  nb_word = -1;
  i = 0;
  while (input_wordtab[++nb_word]);
  if (nb_word > 1)
  {//check -n
    if (input_wordtab[1] && my_strncmp(input_wordtab[1], "-n",
                                      my_strlen(input_wordtab[1])) == 0)
    {
      i = 1;
      while (input_wordtab[++i])
        my_putstr(input_wordtab[i], 1);
    }//normal function
    else
      while (input_wordtab[++i])
      {
        my_putstr(input_wordtab[i], 1);
        my_putchar('\n', 1);
      }
  }
  else
    my_putchar('\n', 1);
  return (env);
}
