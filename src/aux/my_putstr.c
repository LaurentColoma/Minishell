/*
** my_putstr.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May 16 16:50:06 2017 Laurent Coloma
** Last update Thu May 18 15:26:40 2017 Laurent Coloma
*/

#include <unistd.h>

#include "aux.h"

/*Putstr will write a char * in the output given in argument*/
void my_putstr(char *str, int out)
{
  int i;

  i = 0;
  while (str[i])
  {
    my_putchar(str[i], out);
    i = i + 1;
  }
}
