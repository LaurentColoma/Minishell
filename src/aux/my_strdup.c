/*
** my_strdup.c for my_strdup.c in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Mon May 15 16:21:11 2017 Laurent Coloma
** Last update Thu May 18 15:32:50 2017 Laurent Coloma
*/

#include <stdlib.h>

#include "aux.h"

/*Strdup take a string and duplicate before returning it*/
char *my_strdup(char *str)
{
  char *new_str;
  int i;
  int len_str;

  i = -1;
  len_str = my_strlen(str);
  new_str = malloc(sizeof(char) * len_str + 1);
  while (str[++i])
    new_str[i] = str[i];
  new_str[i] = '\0';
  return (new_str);
}

/*Same as Strdup, except that it work on char ** */
char **my_strdup_two(char **str)
{
  char **new_str;
  int lines;
  int i;
  int j;

  i = -1;
  j = 0;
  lines = 0;
  while (str[++i])
    lines = lines + 1;
  new_str = malloc(sizeof(char *) * (lines + 1));
  i = 0;
  while (str[i])
  {
    new_str[j] = malloc(sizeof(char) * my_strlen(str[i]) + 1);
    new_str[j] = str[i];
    new_str[j][my_strlen(new_str[j])] = '\0';
    j = j + 1;
    i = i + 1;
  }
  new_str[j] = NULL;
  return (new_str);
}
