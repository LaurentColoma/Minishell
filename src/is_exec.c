/*
** is_exec.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/src/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu May 11 13:48:42 2017 Laurent Coloma
** Last update Thu May 18 15:55:04 2017 Laurent Coloma
*/

#include <stdio.h>
#include <unistd.h>

#include "aux.h"
#include "my.h"

/*We check if the input is a builtin one and return the iterator and the
code 1
The iterator correspond of the index of the function corresponding*/
t_check check_builtin(t_builtin *my_builtin, t_check my_check, char *input)
{
  int i;

  i = 0;
  while (my_builtin[i].name_builtin)
  {
    if (my_strncmp(my_builtin[i].name_builtin, input, my_strlen(input)) == 0)
    {
      my_check.code = 1;
      my_check.iterator = i;
    }
    i = i + 1;
  }
  return (my_check);
}

/*We check if the input is a system function, we return the iterator and the code
2
The iterator correspond of the index of the path corresponding*/
t_check check_sys(t_check my_check, char **path_wordtab, char *input)
{
  int i;
  int is_access;
  char *path_str;

  i = 0;
  is_access = 0;
  while (path_wordtab[i])
  {
    path_str = my_strcat_path(path_wordtab[i], input);
    is_access = access(path_str, F_OK | X_OK);
    if (is_access != -1)
    {
      my_check.code = 2;
      my_check.iterator = i;
    }
    i = i + 1;
  }
  return (my_check);
}

/*Check if the input is a program write by user
return a code 3*/
t_check check_prog(t_check my_check, char *input)
{
  int is_access;

  is_access = 0;
  is_access = access(input, F_OK | X_OK);
  if (is_access != -1)
    my_check.code = 3;
  return (my_check);
}

/*function that regroup the check_~ one*/
t_check is_exec(char **input, t_builtin *my_builtin, t_check my_check,
                char **path_wordtab)
{
  t_check check;

  check.code = 0;
  check.iterator = 0;
  my_check.code = 0;
  my_check.iterator = 0;
  check = check_builtin(my_builtin, my_check, input[0]);
  if (check.code != 0 && check.code == 1)
    return (check);
  check = check_sys(my_check, path_wordtab, input[0]);
  if (check.code != 0 && check.code == 2)
    return (check);
  check = check_prog(my_check, input[0]);
  if (check.code != 0 && check.code == 3)
    return (check);
  return (my_check);
}
