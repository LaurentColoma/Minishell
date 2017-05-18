/*
** main.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu Apr 27 14:57:38 2017 Laurent Coloma
** Last update Fri Apr 28 08:39:26 2017 Laurent Coloma
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
  (void) argc;
  (void) argv;
  mysh(env);
  return (1);
}
