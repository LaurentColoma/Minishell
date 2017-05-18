/*
** my.h for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/include/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu Apr 27 16:56:26 2017 Laurent Coloma
** Last update Thu May 18 15:16:36 2017 Laurent Coloma
*/

/*In this .h, we have our struct array of function pointer
we use it for the builtin function_pointer
we also have the prototype for the main function of the mysh*/

#include "data.h"

#ifndef MY_H_
# define MY_H_

typedef struct  s_builtin
{
  char *name_builtin;
  char **(*function_pointer)(char **, char **);
}               t_builtin;

//is_exec.c
t_check is_exec(char **, t_builtin *, t_check, char **);

//my_exec.c
void exec_prog(char **, char **);
void exec_sys(char **, char **, char **, t_check);

//mysh.c
void mysh(char **);

//path.c
char *my_getenv(char **, char *);

//builtin.c
char **my_cd(char **, char **);
char **my_env(char **, char **);
char **my_setenv(char **, char **);
char **my_unsetenv(char **, char **);
char **my_exit(char **, char **);
char **my_echo(char **, char **);

#endif /* !MY_H_ */
