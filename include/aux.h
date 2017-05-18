/*
** aux.h for mysh in /home/laurent/Desktop/Laurent/FirstYear/Project/Minishell/Minishell2/test/mysh1/include/
**
** Made by Laurent Coloma
** Login   <laurent.coloma@epitech.eu>
**
** Started on  Thu Apr 27 16:04:27 2017 Laurent Coloma
** Last update Thu May 18 15:12:50 2017 Laurent Coloma
*/

/*This .h is regrouping the prototype I use to do simple action
like writing, counting the lenght of a char *, etc ...*/
//getnextline
char *gnl(const int);

//is_alphanum
int is_alphanum(char);

//getnbr
int my_getnbr(char *);

//my_str_to_wordtab
char **my_str_to_wordtab(char *, char *);

//functions
int my_strlen(char *);
int my_strncmp(char *, char *, int);
char *my_strcat_path(char *, char *);
char *my_strcat(char *, char *);

//str_handler
void my_putchar(char, int);
void my_putstr(char *, int);

//my_strdup
char *my_strdup(char *);
char **my_strdup_two(char **);
