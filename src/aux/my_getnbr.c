/*
** my_getnbr.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May 16 17:02:30 2017 Laurent Coloma
** Last update Thu May 18 15:24:50 2017 Laurent Coloma
*/

/*Getnbr take a char * and will look to change each char into
an int and return it*/
int my_getnbr(char *str)
{
  int nb;
  int i;

  i = 0;
  nb = 0;
  while (str[i])
  {
    nb = (nb * 10) + str[i] - 48;
    i = i + 1;
  }
  return (nb);
}
