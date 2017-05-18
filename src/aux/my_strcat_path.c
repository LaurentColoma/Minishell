/*
** str_handler.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May  9 15:48:37 2017 Laurent Coloma
** Last update Thu May 18 15:30:59 2017 Laurent Coloma
*/

#include <stdlib.h>

#include "aux.h"

/*A function that will concatenate two string, puting a '/' between the two of
them*/
char *my_strcat_path(char *str1, char *str2)
{
  char *new_str;
  int len_str1;
  int len_str2;
  int i;
  int j;

  len_str1 = my_strlen(str1);
  len_str2 = my_strlen(str2);
  new_str = malloc(sizeof(char) * (len_str1 + len_str2) + 2);
  i = -1;
  j = 0;
  while (str1[++i])
  {
    new_str[j] = str1[i];
    j = j + 1;
  }
  i = -1;
  new_str[j++] = '/';
  while (str2[++i])
  {
    new_str[j] = str2[i];
    j = j + 1;
  }
  new_str[j] = '\0';
  return (new_str);
}
