/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Функция проверки массива с нужной на системой счисления на корректность */
int		ft_check_base(char *base)		/* Функция проверки массива с нужной на системой счисления на корректность. Она принимает адресс массива 
										 * и возвращает или 0 или размер проверяемого базового типа, если все корректно */
{
	int	i;								/* обьявляем счетчик */
	int	z;								/* обьявляем счетчик */

	i = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	z = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	if (!base || !base[1])				/* если массив пуст */
		return (0);						/* то возвращаем 0 и завершаем цикл и функцию */
	while (base[i])						/* до тех пор пока выбранная ячейка массива не пуста запускаем цикл */
	{
		z = i + 1;						/* сохраняем в переменную z число указывающее на сл ячейку после i */
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))) /* провеяем массив, чтобы там были только символы чисел и букв алфавита */
			return (0);					/* если в массиве есть что то не нужное нам то возвращаем 0 и завершаем цикл и функцию */
		while (base[z])					/* запускаем цикл, который проверит все ячеки которые следуют за теми на которые указывает переменная i */
			if (base[i] == base[z++])	/* если символ в ячейке на которую указывает i  такой же что и в след ячейке */ 
				return (0);				/* то возвращаем 0 и завершаем цикл и функцию */ /* если нет то продолжаем цикл пробегаясь по остальным ячейка и сравнивая их с i */
		i++;					/* если дошли до сюда значит символ этой ячейки соответсвует условиям и идентичных ему в массиве нет */ /* переходим к проверке сл ячейки */
	}
	return (i);					/* если дошли до сюда, значит массив соответсвует условиям */ /* возвращаем размер базового типа как положительный ответ и завершаем функцию */
}

/* Функция печати числа в нужной системе счисления */
void		ft_putnbr_base(int nbr, char *base)
{
	int		i;								/* обьявляем счетчик для подсчета количества найденых символов*/
	int		base_size;						/* обьявляем переменную для хранения основания чила которое мы получим пройдясь по массиву */
	int		n[100];							/* обьявляем массив целых чисел для печати */

	i = 0;									/* инициализируем счетчик найденых символов нулем */
	base_size = 0;							/* инициализируем размер нулем */
	if (ft_check_base(base))					/* проверяем массив с основанием числа, если он соответствует условиям то запускаем код внутри  */
	{
		if (nbr < 0)						/* проверяем является ли печатаемое число отрицательным */
		{
			nbr *= -1;						/* если да то умножаем его на -1 чтоб получить знак "минус" */
			ft_putchar('-');				/* и печатаем символ отрицательного числа(чтобы оно было перед тем как будет напечатано само число) */
		}
		while (base[base_size])				/* запускаем цикл увеличивающий значение переменной base_size проходясь по массиву base */ /* так мы узнаем системму счисления */
			base_size++;
		while (nbr)							/* пока значение переменной хранящей число не равно нулю */
		{
			n[i] = nbr % base_size;			/* ВЫЧИСЛЯЕМ с помощью base_size ТО, как в нужной нам системе счисления выглядит число.
											 * Для этого делим nbr на base_size по модулю и записывая результат в массив начиная с первой ячейки.
											 * 	Так мы узнаем значение крайнего символа в нужной нам системе счисления */

			nbr /= base_size;				/* Теперь для вычисления оставшихся чисел уменьшаем само число в nbr, разделив его на 
											 * размер base_size (размер нужного нам базового типа) и сохраняем результат в той же переменной nbr */

			i++;							/* Увеличиваем счетчик для перехода к след ячейке. Так же переменная i нам понадобиться позже. 
											 * Накопленное в ней значение скажет нам о размере получившегося массива, которое мы используем 
											 * чтобы напечатать символы в правильном порядке. */
		}
		while (i > 0)						/* Запускаем цикл который напечатает все найденные нами и записанные в массив 'n' значения символов начиная с конца */
			ft_putchar(base[n[--i]]);		/* Для этого мы используем массив с каждым найденным нами числом, как указатель на ячеку массива в котрой храниться его значение.
											 * Вызывать числа из массива 'n' и вставлять как указательна нужное значение мы будем в обратном порядке.
											 * Начиная с конца массива и двигаясь к его началу, чтобы восстановить порядок найденых нами символов */
	}
}


int     main(void)
{
    int     nbr;				/* Обьявляем переменную для хранения числа для печати */
    char    *base;				/* Обьявляем переменную для хранения нужной нам системы счисления */
 
    nbr = 2343;					/* Инициализируем ее записав туда число для печати  */
    base = "01";				/* Инициализируем ее записав туда нужную нам систему счисления */
    ft_putnbr_base(nbr, base);	/* Отправляем число для печати и нужную нам систему счисления в функцию по печати числа в нужной системе счисления */
    return (0);					/* Завершаем функцию и возвращаем ноль */
}