/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:49:54 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/14 21:49:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).
Воспроизведите поведение функции strdup (man strdup).

Your function must be declared as follows:
Ваша функция должна быть объявлена ​​следующим образом:


char    *ft_strdup(char *src);


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	if (!src || !(cpy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}
