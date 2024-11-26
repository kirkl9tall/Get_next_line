#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*p;
	int		x;

	x = 0;
	p = malloc(ft_strlen((char *)s) + 1);
	if (p == NULL)
		return (NULL);
	while (s[x])
	{
		p[x] = s[x];
		x++;
	}
	p[x] = '\0';
	return (p);
}
 
char *bomaamar(int fd , char  *boby)
{
    int a;
    char *buff;
    if(boby == NULL)
    {
			boby = malloc(1);
			boby[0] = '\0';
	}
    buff = malloc(BUFFER_SIZE + 1);
    while (checker(boby,'\n') == 0)
    {
        a = read(fd,buff,BUFFER_SIZE);

        buff[a] = '\0';
        if (a == 0)
            break; 
        boby = ft_strjoin(boby,buff);
        if (*boby == '\0')
            return (NULL);
    }
    free(buff);
    return (boby);
}

char *get_next_line(int fd)
{
    static char  *boby;
    char    *buffreturned;
    char *tmp;
    int x;


    if (fd <0)
        return (NULL);
    boby = bomaamar(fd,boby);  
    x = 0;
     while (boby[x] != '\n' && boby[x] != '\0')
        x++;
    if (boby[x] == '\n')
         x++;
    buffreturned = ft_strldup(boby,x);
    tmp = boby;
    boby = ft_strchr(tmp, '\n');
    free(tmp);
    if(*buffreturned == '\0')
        return(0);
    return (buffreturned); 
}
#include <stdio.h>
int main ()
{
    int i = open("test.txt",O_CREAT| O_RDWR , 0666);
//     // write (i,"Hello Fucki\nng blinder\ns !lalala no\nnono",35);
//     // lseek(i,0,SEEK_SET);
     //printf("khddf");
    char *a;
    while((a = get_next_line(i)) != NULL)
    {
        printf("new line --->%s", a);
        free(a);
    }
    // a =  get_next_line(i);
    // printf("%s", a);
    // free(a);
    // a =  get_next_line(i);
    // printf("%s", a);
    // free(a);
    // a =  get_next_line(i);
    // printf("%s", a);
    // free(a);
    // a =  get_next_line(i);
    // printf("%s", a);
    // free(a);

//   //  printf("%s", a);

} 