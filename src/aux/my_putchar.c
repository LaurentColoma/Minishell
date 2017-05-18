/*
** my_putchar.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May 16 16:49:24 2017 Laurent Coloma
** Last update Thu May 18 15:26:15 2017 Laurent Coloma
*/

#include <unistd.h>

/*Putchar write one char in the output given in argument*/
void my_putchar(char c, int out)
{
  write(out, &c, 1);
}
