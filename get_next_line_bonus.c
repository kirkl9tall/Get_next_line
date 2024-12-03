/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:24 by abismail          #+#    #+#             */
/*   Updated: 2024/12/02 20:07:20 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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

char	*bomaamar(int fd, char *boby)
{
	int		a;
	char	*buff;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (boby == NULL)
	{
		boby = malloc(1);
		if (!boby)
			return (NULL);
		boby[0] = '\0';
	}
	buff = malloc(BUFFER_SIZE + 1);
	while (checker(boby, '\n') == 0)
	{
		a = read(fd, buff, BUFFER_SIZE);
		buff[a] = '\0';
		if (a == 0)
			break ;
		boby = ft_strjoin(boby, buff);
	}
	free(buff);
	return (boby);
}

char	*get_next_line(int fd)
{
	static char	*boby[MAX_F];
	char		*buffreturned;
	char		*tmp;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	boby[fd] = bomaamar(fd, boby[fd]);
	if (!boby[fd] || *boby[fd] == '\0')
		return (free(boby[fd]), boby[fd] = NULL, NULL);
	x = 0;
	while (boby[fd][x] != '\n' && boby[fd][x] != '\0')
		x++;
	if (boby[fd][x] == '\n' && boby[fd][x] != '\0')
		x++;
	buffreturned = ft_strldup(boby[fd], x);
	tmp = boby[fdHH];
	boby[fd] = ft_strchr(tmp, '\n');
	if (!boby[fd] || *boby[fd] == '\0')
		free(boby[fd]), boby[fd] = NULL;
	free(tmp);
	if (*buffreturned == '\0')
		return (free(buffreturned), NULL);
	return (buffreturned);
}
/*

int	main(void)
{
	int i = open("test.txt", O_CREAT | O_RDWR, 0666);
	int j = open("test1.txt", O_CREAT | O_RDWR, 0666);
	char *a;
	int k = i;
	while ((a = get_next_line(k)) != NULL)
	{
		if (k == i)
			k = j;
		else if (k == j)
			k = i;
		printf("new line --->%s", a);
		free(a);
	}
	close(i);
	close(j);
} */