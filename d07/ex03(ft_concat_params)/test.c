/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:14:29 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для подсчета размера переменной(sizeof) */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void	ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/*#############################################################################*/



char	*ft_concat_params(int argc, char **argv) /* функция конкатенации всех строк в одну строку с разделением их между собой знаком перевода строки '\n' */
{
	int		i;					/* Обьявим переменную для счетчика */
	int		j;					/* Обьявим переменную для счетчика */
	int		z;					/* Обьявим переменную для счетчика */
	char	*str;				/* Обьявим указатель в который мы потом сохраним адресс выделеной нами памяти для итоговой строки */
	int		length;				/* Обьявим переменную для хранения общего количества символов во всех строках */

	i = 1;						/* Инициализируем 'i' единицей чтобы начать подсчет символов строк не с нулевой строки где храниться имя программы, а со следующей и дальше */
	length = 0;
	while (i < argc)			/* Запустим цикл вычисления общего количества символов во всех строках и сохраним в length */
	{
		j = 0;					/* Инициализируем 'j' нулем чтобы начать подсчет символов текущей строки с нулевой ячейки */
		while (argv[i][j])		/* Вычисляем сколько символов в этой строке и прибавляем результат к переменной хранящей количество символов предыдущих строк */ 
			j++;				/* Увеличиваем счетчик j чтобы перейти к след ячейке */
		length += j;			/* Сохраняем полученое количество символов прибавляя их к переменной хранящей количество символов предыдущих строк */
		i++;					/* Увеличиваем счетчик для перехода к след строке */
	}
	if ((str = (char *)malloc(sizeof(char) * (length + argc))) == ((void *)0))/* Выделяем память чтобы убрались все символы строк а так же знаки перехода на новую строку */
		return ((void *)0);		/* Если что то пошло не так(не достаточно памяти) то возвращаем NULL */
	i = 0;						/* Используем переменную 'i' как счетчик нужен для перемещения с помощью него по строке, для которой мы выделили память под символы всех строк */
	j = 1;						/* Используем переменную 'j' как счетчик нужен для перемещения с помощью него по строкам. Запишем туда единицу чтобы начать копирование символов 
								 * строк не с нулевой строки где храниться имя программы, а со следующей и дальше */
	z = 0;						/* Инициализируем переменную 'z' нулем чтобы использовать ее как счетчик для перемещения внутри каждой строки и копирования каждой ее ячейки */
	while (j < argc)			/* Запускаем цикл который пройдется по каждой строке */
	{
		z = 0;
		while (argv[j][z])		/* Запускаем цикл который пройдется по каждой ячейке каждой строки */
		{
			str[i] = argv[j][z];/* Копируем содержимое каждой ячейки каждой строки в в итоговую строку */
			z++;				/* Увеличиваем счетчик для перехода к след ячейке текущей строки пока она не закончится и мы не перейдем к след строке */
			i++;				/* Увеличиваем счетчик для перехода к след ячейке итоговой строки*/
		}
		str[i] = '\n';			/* Если строка закончилась то в итоговоую строку(str) записываем знак перехода на новую строку(после копирования туда строки из аргументов)  */
		i++;					/* Увеличиваем счетчик для перехода к след ячейке итоговой строки*/
		j++;					/* Увеличиваем счетчик для перехода к след строке для копирования ее итоговую строку(str) */
	}
	str[i] = '\0';				/* После добавления в "str" всех строк, добавляем в конце символ завершающего нуля */
	return (str);
}


int     main(int argc,char **argv)/* Основаная функция. Принимаем в аргументах их количество(argc) и массив содержащий строки с аргументами(**argv)  */
{
	if (argc > 2)				/* Если в аргументов рядом с именем программы больше чем 1 то запускаем код ниже */ 
		ft_putstr(ft_concat_params(argc, argv));/* Запускам функцию конкатенации всех аргументов в одну строку и печатаем результат */
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}