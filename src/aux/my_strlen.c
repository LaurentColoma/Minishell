/*
** my_strlen.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May 16 16:50:35 2017 Laurent Coloma
** Last update Thu May 18 15:33:21 2017 Laurent Coloma
*/

/*Count each char in a char * and return the nb of char */
int my_strlen(char *str)
{
  int i;

  i = 0;
  if (str[0] == '\0')
    return (0);
  while (str[i])
    i = i + 1;
  return (i);
}
