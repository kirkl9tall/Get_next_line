#include "get_next_line.h"
#include <stdio.h>

char *bomaamar(int fd,char *boby)
{
    char *buff;
    int a;
    char *temp;
   

    a = 0;
    while (checker(boby,'\n') == 0)
    {
        buff = malloc(BUFFER_SIZE + 1);
        a = read(fd,buff,BUFFER_SIZE);
        if (!buff)
            return (NULL);
        buff[a] = '\0';
        temp = boby;
        boby = ft_strjoin(boby,buff);
        if (boby == NULL)
                return (free(temp),free (boby),NULL);
         if (a > 0)
            {
                free(buff);
                free(temp);
            }
        if (a <= 0)
        {
            free(buff);
            free(temp);
            break ;
        }
    }
    //free(buff);
    return (boby);
}
char *get_next_line(int fd)
{
    static char  *boby;
    char *buff2;
    char *labo;
    if(fd == -1)
        return (NULL);
    boby = bomaamar(fd,boby);
    int j= 0;
    while (boby[j] != '\n' && boby[j])
        j++;
   if (boby[j] == '\n')
        j++; 
    buff2 = ft_strldup(boby, j);
    
    boby = ft_strchr(boby,'\n');
    if(boby)
        boby = NULL;
    //free(boby);
    return (buff2);
}

int main ()
{
    int i = open("test.txt",O_CREAT| O_RDWR , 0666);
    // write (i,"Hello Fucki\nng blinder\ns !lalala no\nnono",35);
    // lseek(i,0,SEEK_SET);
    char *a;
    a =  get_next_line(i);
    printf("%s", a);
       free(a);
/* 
    a =  get_next_line(i);
   printf("%s", a);
      free(a);

    a =  get_next_line(i);
    printf("%s", a);
       free(a);

    a =  get_next_line(i);
   printf("%s", a);
   free(a);
    a =  get_next_line(i);
   printf("%s", a);
   free(a); */

} 