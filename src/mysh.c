/*
** mysh.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/src/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu Apr 27 14:59:21 2017 Laurent Coloma
** Last update Thu May 18 15:57:19 2017 Laurent Coloma
*/

#include <unistd.h>

#include "aux.h"
#include "my.h"

t_builtin g_builtin[] =
{
  {"cd", &my_cd},
  {"echo", &my_echo},
  {"env", &my_env},
  {"exit", &my_exit},
  {"setenv", &my_setenv},
  {"unsetenv", &my_unsetenv},
  {NULL, NULL}
};

/*Function that will display the prompt if we are in a terminal*/
int prompt()
{
  if (isatty(0))
    my_putstr("(づ｡◕ ‿‿ ◕) >", 1);
  return (1);
}

/*Function that will display an error message if the cmd is not found*/
void cmd_not_found(char *input)
{
  my_putstr(input, 1);
  my_putstr(": command not found\n", 1);
}

/*Main function of the mysh, all the things start here*/
void mysh(char **env)
{
  t_check my_check;
  t_path my_path;
  t_input my_input;
  char **my_env;

  my_env = my_strdup_two(env);
  my_path.path = my_getenv(my_env, "PATH");
  my_path.pthwdtb = my_str_to_wordtab(my_path.path, ":");
  while (prompt() && (my_input.input = gnl(0)))
  {
    if (my_input.input[0] != '\0' && my_input.input[0] != '\n')
    {
      my_input.inwdtb = my_str_to_wordtab(my_input.input, " \n\0");
      my_check = is_exec(my_input.inwdtb, g_builtin, my_check,
                          my_path.pthwdtb);
      if (my_check.code == 1)
        my_env =
          g_builtin[my_check.iterator].function_pointer(my_env, my_input.inwdtb);
      else if (my_check.code == 2)
        exec_sys(my_path.pthwdtb, my_input.inwdtb, my_env, my_check);
      else if (my_check.code == 3)
        exec_prog(my_input.inwdtb, my_env);
      else
        cmd_not_found(my_input.inwdtb[0]);
    }
  }
}
