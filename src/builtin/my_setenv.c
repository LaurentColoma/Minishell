/*
** my_setenv.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 14:21:22 2017 Laurent Coloma
** Last update Thu May 18 15:49:11 2017 Laurent Coloma
*/

#include <stdlib.h>
#include <stdio.h>

#include "aux.h"
#include "my.h"

/*In this function we are going to check if the char * follow certain rules :
  - the first char need to be an alpha
  - the full chain need to be an alphanumeric char*/
int check_input(char *str)
{
  int i;

  if (is_alphanum(str[0]) == 1 || is_alphanum(str[0]) == 2)
  {
    i = 1;
    while (str[i])
    {
      if (is_alphanum(str[i]) == 0)
        return (1);
      i = i + 1;
    }
    return (0);
  }
  else
    return (1);
}

/*We parse the env to know if the "input" argument is in the env*/
int find_in_env(char **env, char *input)
{
  int i;
  int len;

  i = 0;
  len = my_strlen(input) - 1;
  while (env[i])
  {
    if (my_strncmp(env[i], input, len) == 0)
      return (0);
    i = i + 1;
  }
  return (1);
}

/*With this function we will update a line of the env*/
void update_env(char **env, char **input_wordtab)
{
  int i;
  char *update_str;

  i = -1;
  while (env[++i]);
  my_unsetenv(env, input_wordtab);
  update_str = my_strcat(input_wordtab[1], "=");
  if (input_wordtab[2])
    update_str = my_strcat(update_str, input_wordtab[2]);
  env[i - 1] = update_str;
}

/*With this function we will add a new element to the env*/
char **add_to_env(char **env, char **input_wordtab)
{
  int i;
  char **tmp_env;
  char *add_str;

  i = -1;
  while (env[++i]);
  tmp_env = malloc(sizeof(char *) * (i + 2));
  i = 0;
  while (env[i])
  {
    tmp_env[i] = malloc(sizeof(char) * my_strlen(env[i]) + 2);
    tmp_env[i] = my_strdup(env[i]);
    i = i + 1;
  }
  add_str = my_strcat(input_wordtab[1], "=");
  if (input_wordtab[2])
    add_str = my_strcat(add_str, input_wordtab[2]);
  tmp_env[i] = add_str;
  tmp_env[i + 1] = NULL;
  return (tmp_env);
}

/*The Setenv function will :
  - display the env if only one entry in the input_wordtab
  - update the env if the entry is present in the env
  - add in the env if the entry is not present in the env*/
char **my_setenv(char **env, char **input_wordtab)
{
  int size_input;
  int in_env;

  size_input = 0;
  in_env = 0;
  while (input_wordtab[size_input])
   size_input = size_input + 1;
  if (size_input == 1)//display env
    my_env(env, input_wordtab);
  else if (size_input == 2 && check_input(input_wordtab[1]) == 0)
  {//if input_wordtab[1] exist and input_wordtab[2] == NULL
    in_env = find_in_env(env, input_wordtab[1]);
    if (in_env == 0)//exist
      update_env(env, input_wordtab);
    else//do not exist
      env = add_to_env(env, input_wordtab);
  }
  else if (size_input == 3 && (check_input(input_wordtab[1]) == 0 &&
                                input_wordtab[2]))
  {//if input_wordtab[2] exist and input_wordtab[3] == NULL
    in_env = find_in_env(env, input_wordtab[1]);
    if (in_env == 0)//exist
      update_env(env, input_wordtab);
    else//do not exist
      env = add_to_env(env, input_wordtab);
  }
  return (env);
}
