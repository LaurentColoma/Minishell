/*
** data.h for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/include/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 10 17:51:46 2017 Laurent Coloma
** Last update Thu May 18 15:15:06 2017 Laurent Coloma
*/

/*Here are the different structure regrouping
variable, we have a struct for path data, the input we write and one
when we parse the builtin function*/

#ifndef DATA_H_
# define DATA_H_

typedef struct  s_path
{
  char *path;
  char **pthwdtb;
}               t_path;

typedef struct  s_input
{
  char *input;
  char **inwdtb;
}               t_input;

typedef struct  s_check
{
  int code;
  int iterator;
}               t_check;

#endif /* !DATA_H_ */
