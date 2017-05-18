/*
** wordtab2.0.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Fri Apr 28 17:18:06 2017 Laurent Coloma
** Last update Thu May 18 15:30:18 2017 Laurent Coloma
*/

#include <stdlib.h>

#include "aux.h"
#include "my.h"

/*Will parse the sep array, to see if the char given in argument correspond to
one of the char in the sep array*/
int check_sep(char character, char *sep)
{
  int i;

  i = -1;
  while (sep[++i])
  {
    if (sep[i] == character)
      return (0);
  }
  return (1);
}

/*Will count how many word there is a chain of char, the char in the sep array
being the separator*/
int count_word(char *string, char *sep)
{
  int i;
  int is_word;
  int nb_word;

  i = 0;
  is_word = 0;
  nb_word = 0;
  while (string[i])
  {
    if (string[i] && is_word == 0 && check_sep(string[i], sep) == 1)
    {
      is_word = 1;
      nb_word = nb_word + 1;
    }
    else if (string[i] && is_word == 1 && check_sep(string[i], sep) == 0)
      is_word = 0;
    i = i + 1;
  }
  return (nb_word);
}

/*Will transform a char * in a char **, it mean that each word will be store in
an index*/
char **my_str_to_wordtab(char *string, char *sep)
{
  int i;
  int j;
  int k;
  int nb_word;
  char **output;

  i = 0;
  k = 0;
  nb_word = count_word(string, sep);
  output = malloc(sizeof(char *) * (nb_word + 1));
  while (i < nb_word)
  {
    j = 0;
    output[i] = malloc(sizeof(char) * my_strlen(string) + 1);
    while (string[k] && check_sep(string[k], sep) == 0)
      k = k + 1;
    while (string[k] && check_sep(string[k], sep) == 1)
     output[i][j++] = string[k++];
    output[i][j] = '\0';
    i = i + 1;
  }
  output[i] = '\0';
  return (output);
}
