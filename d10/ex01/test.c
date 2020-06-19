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

/* ************************************************************************** */
void		ft_putchar(char c)	/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void		ft_putnbr(int nb)	/* Функция печати числа */
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

void	ft_foreach(int *tab, int length, void(*f)(int)) /* Принимаем в аргументах функции адресс 
								 * массива целых чисел, длинну этого массива и  адресс функции(которую 
								 * мы применим по оношению к каждому элементу целочисленного массива) */
{
	int	i;						/* Обьявляем счетчик количества пройденых элементов */

	i = 0;						/* Инициализируем нулем счетчик количества пройденых элементов */
	while (i < length)			/* Запускаем цикл который пройдеться по каждому элементу массива */
	{
		f(tab[i++]);			/* Используем каждое число массива отправляя его в функцию, адресс
								 * которой мы получили в аргументах */
	}
}


int 		main(void)
{
	int	tab[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};/* Создаем массив целых чисел */
	ft_foreach(tab, 17, &ft_putnbr);/* Отправляем в функцию адресс массива целых чисел, длинну 
								 * этого массива и адресс функции 'ft_putnbr'.
								 * Таким образом мы для каждого элемента массива 'tab' применим
								 * функцию 'ft_putnbr' */
	ft_putchar('\n');			/* Печатаем символ переноса строки для корректного отображения вывода */
    return (0);					/* Возвращаем 0 и завершаем программу */
}