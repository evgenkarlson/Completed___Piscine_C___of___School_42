/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:14:47 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для подсчета размера переменной(sizeof) */

void	ft_putchar(char c)			/* функция печати символа */
{
	write(1, &c, 1);
}

void	ft_printstr(char *str)		/* Функция печати массива символов(строки) */
{
	while(*str)
		ft_putchar(*str++);
}

int		ft_strlen(char *str)		/* функция подсчета длинны массива символов(строки) */
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strdup(char *src)		/* Функция дублирования строки. Она принимает в аргументах адресс массива символов строки. Дублирует ее и возвращает адресс дубликата */
{
	int		l;						/* Обьявляем переменную для хранения длинны полученной строки */
	char	*dest;					/* Обьявляем указатель который будет хранит адресс выделеной нами памяти под дубликат */

	l = ft_strlen(src);				/* Подсчитываем длинну полученой нами строки и сохраняем в переменную */
	if ((dest = malloc(sizeof(*src) * (l + 1))) == ((void *)0))	/* Подсчитываем какого размера нужно выделить память(+1 байт для завершающего нуля), 
																 * выделяем память и сохраняем ее адресс в dest */
		return (((void *)0));		/* Если что то пошло не так(не достаточно памяти) то возвращаем NULL */
	while (l >= 0)					/* Цикл дублирования, каждой ячейки массива символо(строки) в ячейки выделенной нами памяти, начиная с конца к началу*/
	{
		dest[l] = src[l];			/* Копируем значение из исходного массива в ячейку выделеной памяти под дубликат */
		l--;						/* Спускаемся к след ячейкам */
	}
	return (dest);					/* Возвращаем адресс полученой копии массива символо(строки) */
}

int     main(int argc, char **argv)	/* Основаная функция. Она принимает количество аргументов и массив со строками(массив указателей на указатели) */
{
	if (argc > 1)					/* Используя переданные нам данные о количество аргументов в "argc" проверяем есть ли в аргументах хоть что то включая имя программы */
		ft_printstr(ft_strdup(argv[1]));
	ft_putchar('\n');
	
	return (0);						/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}