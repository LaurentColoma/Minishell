/*
** is_alphanum.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Wed May 17 16:51:39 2017 Laurent Coloma
** Last update Thu May 18 15:23:21 2017 Laurent Coloma
*/

/*This function take a char for argument and will check if this one
is an alpha minuscule, an alph majuscule or a number*/
int is_alphanum(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  else if (c >= 'A' && c <= 'Z')
    return (2);
  else if (c >= '0' && c <= '9')
    return (3);
  return (0);
}
