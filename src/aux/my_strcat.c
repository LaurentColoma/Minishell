/*
** my_strcat.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu May 18 13:15:14 2017 Laurent Coloma
** Last update Thu May 18 15:31:43 2017 Laurent Coloma
*/

#include <stdlib.h>

#include "aux.h"

/*Strcat will concatenate two string into one before returning it*/
char *my_strcat(char *str1, char *str2)
{
  char *new_str;
  int len1;
  int len2;
  int i;
  int j;

  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  new_str = malloc(sizeof(char) * (len1 + len2) + 1);
  i = -1;
  j = 0;
  while (str1[++i])
  {
    new_str[j] = str1[i];
    j = j + 1;
  }
  i = -1;
  while (str2[++i])
  {
    new_str[j] = str2[i];
    j = j + 1;
  }
  new_str[j] = '\0';
  return (new_str);
}
