/*
** getnextline.c for ghop in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu Jan 19 15:57:24 2017 Laurent Coloma
** Last update Thu May 18 15:20:56 2017 Laurent Coloma
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*The realloc function is a function that will help us here to fill our array
one char by one, we send it our array 'str', the char 'c', and the size of the
str 'size'
This function will create a new array, with a +2 size for the char and the '\0'.
Then he will return it*/
char *my_realloc(char *str, char c,  int size)
{
  char *new_str;
  int i;

  new_str = malloc(sizeof(char) * (size + 2));
  i = 0;
  while (i < size)
  {
    new_str[i] = str[i];
    i = i + 1;
  }
  new_str[i] = c;
  new_str[i + 1] = '\0';
  return (new_str);
}

/*Getnextline is function that will read a file descriptor (one char by one here)
and will write them in an str*/
char *gnl(const int fd)
{
  char *str;
  char c;
  int size;

  str = malloc(sizeof(char) * 1);
  str = NULL;
  size = 0;
  while (read(fd, &c, 1) > 0)
  {
    str = my_realloc(str, c, size);
    size = size + 1;
    if (c == '\n')
      return (str);
  }
  if (size == 0)
  {
    free(str);
    return (NULL);
  }
  return (str);
}
