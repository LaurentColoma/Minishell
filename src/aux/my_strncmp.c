/*
** my_strncmp.c for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell1/PSU_2016_minishell1/src/aux/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Tue May 16 16:52:36 2017 Laurent Coloma
** Last update Thu May 18 15:35:02 2017 Laurent Coloma
*/

/*Strncmp will compare two char * and return the difference between them looking at
the Ascii code, if it is '0', it means that the chain are the same*/
int my_strncmp(char *str1, char *str2, int n)
{
  int i;

  i = 0;
  while ((str1[i] == str2[i]) && (str1[i] != '\0') &&
          (str2[i] != '\0') && (i < n))
          i = i + 1;
  return (str1[i] - str2[i]);
}
