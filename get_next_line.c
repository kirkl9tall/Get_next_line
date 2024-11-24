#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    static char  *boby;
    char *buff;
    char *buff2;
    char *origin;
    char *chyata;
    buff = NULL;
    boby = NULL;

    int a = 0;

     while (checker(boby,'\n') == 0)
    {
        buff = malloc(BUFFER_SIZE + 1);
        a = read(fd,buff,BUFFER_SIZE);
        if (!buff)
            return (NULL);
        boby = ft_strjoin(boby, buff);
        if (a == 0)
            break;
    } 
        chyata = ft_strrchr(buff,'\n');
        int j= 0;
        while (boby[j] != '\n')
            j++;
        if (buff[j] == '\n')
            j++;
        buff2 = ft_strldup(boby, j);   
        
    printf("the  string that was read is   : [%s]\n",boby); 
    printf(" the reste of the read  after the new line  : [%s]\n",chyata);
    printf("the  string that will be returned isss  : [%s]\n",buff2); 
    printf("\n--------------------------------------\n"); 
    free(boby);
    boby = chyata;

    printf("the new boby is  : %s   operation done \n ", boby);
    printf("\n***************************************\n"); 
   // free(buff2);
}

int main ()

{
    int i = open("abdo.txt",O_CREAT| O_RDWR , 0666);
    write (i,"Hello Fucki\nng world !lalala no\nnono",35);
    lseek(i,0,SEEK_SET);
    get_next_line(i);
    get_next_line(i);

/*      get_next_line(i);
    get_next_line(i);
    get_next_line(i);  */
}