/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 21:14:20 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/21 21:14:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


• The aim of this function is to count the amount of times two strings match.
• When we have two or more stars, multiple string combinations can be suitable.
• nmatch calculates the total amount of combinations.
• Here are some examples :
	"abcbd" & "*b*" match twice : ("a","cbd") and ("abc", "d")
	"abc" & "a**" match 3 times : (nothing,"bc"), ("b", "c") and ("bc", nothing)

• nmatch returns the number of combinations that match.


• Цель этой функции - подсчитать количество совпадений двух строк.
• Когда у нас две или более звездочек, могут подойти несколько комбинаций струн.
• nmatch вычисляет общее количество комбинаций.
• Вот несколько примеров :
	"abcbd" и "* b *" совпадают дважды: ("a", "cbd") и ("abc", "d")
	«abc» и «a **» совпадают 3 раза: (ничего, «bc»), («b», «c») и («bc», ничего)

• nmatch возвращает количество совпадающих комбинаций.


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*')
	{
		if (!*s1)
			return (nmatch(s1, s2 + 1));
		else
			return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}