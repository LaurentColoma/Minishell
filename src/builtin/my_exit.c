/*
** my_exit.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 14:47:25 2017 Laurent Coloma
** Last update Thu May 18 15:42:32 2017 Laurent Coloma
*/

#include <stdlib.h>
#include <stdio.h>

#include "aux.h"

/*When call, this function will quit the program and display "exit"*/
char **my_exit(char **env, char **input_wordtab)
{
  int code;
  (void) env;

  code = 0;
  if (input_wordtab[1])
    code = (unsigned char) my_getnbr(input_wordtab[1]);
  my_putstr("exit\n", 1);
  exit(code);
  return (env);
}
