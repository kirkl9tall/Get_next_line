#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    static char  *boby;
    char *buff;
    char *buff2;
    char *chyata;

    int a = 0;
    while (checker(boby,'\n') == 0)
    {
        buff = malloc(BUFFER_SIZE + 1);
        a = read(fd,buff,BUFFER_SIZE);
        //printf("here\n");
        if (!buff)
            return (NULL);
        buff[a] = '\0';
        boby = ft_strjoin(boby, buff);
        if (a <= 0)
        {
            free(buff);
            break ;
        }
    } 
    chyata = ft_strrchr(buff,'\n');
    int j= 0;
    printf("%s\n",boby);
    while (boby[j] != '\n' && boby[j])
        j++;
   if (boby[j] == '\n')
        j++; 
    buff2 = ft_strldup(boby, j); 
    printf("returned : [%s]\n",buff2); 
    printf("--------------------------------------\n"); 
    free(boby);
    boby = chyata;
    printf("\nboby is : %s\n",boby);
}

int main ()

{
    int i = open("abdo.txt",O_CREAT| O_RDWR , 0666);
    //write (i,"Hello Fucki\nng blinders !lalala no\nnono",35);
    //lseek(i,0,SEEK_SET);
    get_next_line(i);
    get_next_line(i);
    get_next_line(i);

    // get_next_line(i);
    // get_next_line(i);  */
}