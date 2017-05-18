/*
** my_cd.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/builtin/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu May  4 17:03:38 2017 Laurent Coloma
** Last update Thu May 18 15:39:19 2017 Laurent Coloma
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "aux.h"
#include "my.h"

/*The first builtin, it is the cd command.
the cd function implemented here are :
  - cd
  - cd + directory
  - cd -
*/
char **my_cd(char **env, char **input_wordtab)
{
  static char buffer[2048];
  static char *old_pwd;
  static int start = 1;
  char *tmp_pwd;
  char *cd_home;

  //cd + directory
  if (input_wordtab[1] &&
      my_strncmp(input_wordtab[1], "-", my_strlen(input_wordtab[1])) != 0)
  {
    old_pwd = getcwd(buffer, 2048);
    chdir(input_wordtab[1]);
  }//cd -
  else if (input_wordtab[1] &&
      my_strncmp(input_wordtab[1], "-", my_strlen(input_wordtab[1])) == 0)
  {//At the start there is no oldpwd so its impossible to cd -.
    if (start != 0)
    {
      my_putstr(": no such file or directory\n", 1);
      start = 0;
    }
    else
    {
      tmp_pwd = my_strdup(old_pwd);
      old_pwd = getcwd(buffer, 2048);
      chdir(tmp_pwd);
    }
  }//cd
  else
  {
    cd_home = my_getenv(env, "USER");
    cd_home = my_strcat_path("/home", cd_home);
    old_pwd = getcwd(buffer, 2048);
    chdir(cd_home);
  }
  return (env);
}
