#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif
char	*ft_strrchr(const char *str, int c);
char *get_next_line(int fd);
int	checker(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strldup(const char *s, int i);

#endif