#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		x;
	int		y;
 	if (!s1 && !s2)
		return (malloc(1)); 
	if (!s1)
		s1 = ""; 
	if (!s2)
		s2 = "";
	x = 0;
	y = 0;
	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[x])
		p[y++] = s1[x++];
	x = 0;
	while (s2[x])
		p[y++] = s2[x++];
	p[y] = '\0';
	return (p);
}

int	checker(const char *str, int c)
{
	int		x;
	size_t	y;

	if (str == NULL)
		return (0);
	x = 0;
	if (c == '\0')
		return (0);
	while (str[x])
	{
		if (str[x] == (char)c)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	int		x;
	size_t	y;

	y = ft_strlen((char *)str);
	x = 0;
	if (c == '\0')
		return ((char *)(str + y));
	while (str[x])
	{
		if (str[x] == (char)c)
			return ((char *)str + x + 1);
		x++;
	}
	return (NULL);
}
char	*ft_strldup(char *s, int i)
{
	char	*p;
	int		x;

	x = 0;
	p = malloc(ft_strlen((char *)s) + 1);
	if (p == NULL)
		return (NULL);
	while (i--)
	{
		p[x] = s[x];
		x++;
	}
	p[x] = '\0';
	free(s);
	return (p);
}
