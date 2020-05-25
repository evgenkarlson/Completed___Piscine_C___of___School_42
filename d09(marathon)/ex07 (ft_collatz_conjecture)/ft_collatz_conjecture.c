/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************
**
**
**	• Напишите функцию ft_collatz_conjecture, которая будет возвращать «время
**	полета» для переданного аргумента.
**
**	• Эта функция должна быть рекурсивной.
**
**	• Эта функция будет прототипирована следующим образом:
**
**						unsigned int	ft_collatz_conjecture(unsigned int base)
**
**	• На французском языке «гипотеза Коллатца» называется Conjecture de Syracuse.
**
**
** ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

	/!\	P.S нас просят создать функцию, которая реализует "гипотезу	Коллатца"
	Эта функция должна вернуть количество операций проведенных над числом, 
	которое мы туда	отправим.

   **************************************************************************

	Гипотеза Коллатца заключается в том, что какое бы начальное число n мы ни 
	взяли, рано или поздно мы получим единицу.

	Берём любое натуральное число n. Если оно чётное, то делим его на 2, а если 
	нечётное, то умножаем на 3 и прибавляем 1 (получаем 3n + 1). Над полученным 
	числом выполняем те же самые действия, и так далее.


	Примеры
	
	Например, для числа 3 получаем:
		3 — нечётное, 3×3 + 1 = 10
		10 — чётное, 10:2 = 5
		5 — нечётное, 5×3 + 1 = 16
		16 — чётное, 16:2 = 8
		8 — чётное, 8:2 = 4
		4 — чётное, 4:2 = 2
		2 — чётное, 2:2 = 1
		1 — нечётное, 1×3 + 1 = 4

	Далее, начиная с 1, начинают циклически повторяться числа 1, 4, 2.

	Последовательность, начинающаяся числом 19, приходит к единице уже за двадцать шагов:
		19, 58, 29, 88, 44, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1, …

	Для числа 27 получаем:
		27, 82, 41, 124, 62, 31, 94, 47, 142, 71, 214, 107, 322, 161, 484, 242, 121, 364, 
		182, 91, 274, 137, 412, 206, 103, 310, 155, 466, 233, 700, 350, 175, 526, 263, 790, 
		395, 1186, 593, 1780, 890, 445, 1336, 668, 334, 167, 502, 251, 754, 377, 1132, 566, 
		283, 850, 425, 1276, 638, 319, 958, 479, 1438, 719, 2158, 1079, 3238, 1619, 4858, 
		2429, 7288, 3644, 1822, 911, 2734, 1367, 4102, 2051, 6154, 3077, 9232, 4616, 2308, 
		1154, 577, 1732, 866, 433, 1300, 650, 325, 976, 488, 244, 122, 61, 184, 92, 46, 23, 
		70, 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1, …
	
	Последовательность пришла к единице только через 111 шагов, достигнув в пи́ке значения 9232.

   **************************************************************************

	/!\	Гипотеза может быть реализована следующим образом:
	Возьмите любое положительное целое число n. 
	Если n четное, разделите его на 2, чтобы получить n / 2. 
	Если n нечетное, умножьте его на 3 и добавьте 1, чтобы получить 3n + 1. 
	Повторяйте процесс бесконечно.
	Предположение состоит в том, что независимо от того, с какого числа вы начинаете,
	вы всегда в конечном итоге достигнете 1.
	
   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (!(base %2))
		base = base / 2;
	else
		base = 3 * base + 1;
	return (ft_collatz_conjecture(base) + 1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if ((base % 2) == 0)
		return (1 + ft_collatz_conjecture(base / 2));
	else
		return (1 + ft_collatz_conjecture(base * 3 + 1));
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	else
	{
		if (base % 2)
			base = ft_collatz_conjecture(3 * base + 1) + 1;
		else
			base = ft_collatz_conjecture(base / 2) + 1;
	}
	return (base);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

/*
** The conjecture can be summarized as follows. Take any positive integer n.
** If n is even, divide it by 2 to get n / 2. If n is odd, multiply it
** by 3 and add 1 to obtain 3n + 1. Repeat the process indefinitely.
** The conjecture is that no matter what number you start with,
** you will always eventually reach 1.
** Source: https://en.wikipedia.org/wiki/Collatz_conjecture
**
** https://xkcd.com/710/	   ;)
*/

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if ((base % 2) == 0)
		base = base / 2;
	else
		base = 3 * base + 1;
	return (ft_collatz_conjecture(base) + 1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
