/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/14 12:33:14 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/15 10:51:23 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                       */
/*                                                                            */
/*      gcc test.c && chmod +x ./a.out && ./a.out	                      */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_put_arr_char(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int 	main(void)
{
	char *p;
	char i[] = {"54321"};

	p = ft_strrev(i);
	ft_put_arr_char(p);

	return 0;
}