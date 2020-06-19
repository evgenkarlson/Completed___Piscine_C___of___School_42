/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>				/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>				/* Подключаем библиотеку содержащую функцию "malloc" */

/* ************************************************************************** */

void	ft_putchar(char c)	/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void	ft_putnbr(int nb)	/* Функция печати числа */
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

/* ************************************************************************** */

void	ft_printnumtab(int *tab, int length)/* функция печати массива целых чисел */
{
	int i;						/* Обьявляем счетчик количества пройденых элементов */

	i = 0;						/* Инициализируем нулем счетчик количества пройденых элементов */
	while(i < length)			/* Запускаем цикл который пройдеться по всем элементам массива */
	{
		ft_putnbr(tab[i++]);	/* печатаем каждую ячейку массива целочисленного массива */
		ft_putchar(' ');		/* печатаем символ 'пробела' после печати числа для корректного
								 * отображения вывода */
	}
}

/* ************************************************************************** */


int		ft_maximise(int n)		/* Функция для теста. Она увеличивает полученое число в два раза */
{
	return (n * 2);				/* Увеличиваем полученое число в два раза и возвращаем его */
}

/* ************************************************************************** */

int		*ft_map(int *tab, int length, int(*f)(int))	/* Принимаем в аргументах функции адресс 
								 * массива целых чисел, длинну этого массива и  адресс функции(которую 
								 * мы применим по оношению к каждому элементу целочисленного массива) */
{
	int	*mytab;					/* Обьявляем указатель в кторый сохраним адресс выделеной памяти */
	int	i;						/* Обьявляем счетчик количества пройденых элементов */

	if ((mytab = (int*)malloc(sizeof(*tab) * length)) == ((void *)0))/* выделяем память под массив чисел */
		return ((void *)0);
	i = 0;						/* Инициализируем нулем счетчик количества пройденых элементов */
	while (i < length)			/* Запускаем цикл который пройдеться по каждому элементу массива */
	{
		mytab[i] = f(tab[i]);	/* Используем каждое число массива отправляя его в функцию, а результат
								 * сохраняем в одну из ячеек нового массива */
		i++;					/* Увеличиваем счетчик для перехода к след ячейке массива */
	}
	return (mytab);				/* Завершаем функцию и возвращаем адресс массива */
}


int 	main(void)
{
	int	tab[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};/* Создаем массив целых чисел */
	int	*arr;					/* Обьявляем указатель в который мы сохраним адрес целочисленного массива */

	arr = ft_map(tab, 17, &ft_maximise);/* Отправляем в функцию адресс массива целых чисел, длинну 
								 * этого массива и адресс функции 'ft_maximise'. Таким образом мы 
								 * для каждого элемента массива 'tab' применим функцию 'ft_maximise',
								 * а результат запишем в другой массив, после чего вернем адресс этого
								 * массива(с измененнными числами) */
	ft_printnumtab(arr, 17);	/* Печатаем полученный массив целых чисел */
	ft_putchar('\n');			/* Печатаем символ переноса строки для корректного отображения вывода */
    return (0);					/* Возвращаем 0 и завершаем программу */
}