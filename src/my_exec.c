/*
** my_exec.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/src/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu May 11 16:51:32 2017 Laurent Coloma
** Last update Thu May 18 15:55:17 2017 Laurent Coloma
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "aux.h"
#include "data.h"

/*Function that execute a prog made by the user*/
void exec_prog(char **input_wordtab, char **env)
{
  int status;
  pid_t pid;

  if ((pid = fork()) == -1)
    exit(84);
  else if (pid == 0)
    execve(input_wordtab[0], input_wordtab, env);
  else
    wait(&status);
}

/*Function that execute a sys function*/
void exec_sys(char **path_wordtab, char **input_wordtab, char **env,
              t_check my_check)
{
  int status;
  pid_t pid;
  char *path;

  path = my_strcat_path(path_wordtab[my_check.iterator], input_wordtab[0]);
  if ((pid = fork()) == -1)
    exit(84);
  else if (pid == 0)
    execve(path, input_wordtab, env);
  else
    wait(&status);
}
