#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif 
char *get_next_line(int fd);
char	*ft_strjoin(char  *s1, char *s2);
size_t	ft_strlen(char *str);
int checker(char *str, int c);
char	*ft_strchr( char *str, int c);
char	*ft_strldup( char *s, int i);
char	*ft_strdup(char *s);

#endif