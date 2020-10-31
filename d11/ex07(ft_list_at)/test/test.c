/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:34:14 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)		/* Функция печатает строку */
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void		ft_put_list(t_list *list)	/* Функция печати связанных между собой экземпляров структуры типа 't_list' */
{
	while (list)
	{
		ft_putstr((char *)list->data);
		list = list->next;
	}
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адресс из указателя data
										 * в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										 * конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адресс выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адресс принятого
										 * в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr) /* Функция возвращает адресс нужного нам экземпляра структуры из связанных между 
										 * собой последовательно экземпляров структур */
{
	unsigned int	i;					/* Обьявим переменную для подсчета экземпляров */
	t_list			*list;				/* Обьявим указатель для временного хранения адреса экземпляра */

	if (nbr == 0)						/* Удостоверимся что принятое нами число не равно нулю */
		return ((void *)0);				/* Если число равно нулю то завершаем функцию и возвращам нулевой указатель */
	list = begin_list;					/* Сохраняем адрес, принятого нами в аргументах, экземпляра структуры */
	i = 1;								/* Инициализируем счетчик единицей, зная то что мы уже владеем адресом первого экземпляра структуры */
	while (i < nbr)						/* Если число в счетчике меньше числа в переменной 'nbr', значит хранимый в указателе адрес экземпляра 
										 * не тот что нам нужен и мы запукаем цикл который будет вычислять адрес следующего экземпляра структуры 
										 * в цепи связанных между собой структур, до тех пор пока не дойдет адреса до нужного экземпляра структуры */
	{
		if (list->next)					/* Если в указателе 'next' текущего экземпляра структуры храниться адресс следующего экземпляра структуры */
			list = list->next;			/* То мы сохраняем этот адресс в указателе 'list' */
		else							/* Если условие выше не верно, значит нужный нам экземпляр структуры не существует */
			return ((void *)0);			/* И мы завершаем функцию и возвращам нулевой указатель */
		i++;							/* Увеличиваем счетчик для сохранения информации о том позицию какого экземпляра структуры мы нашли */
	}
	return (list);						/* Если дошли до сюда значит мы нашли адресс экземпляра структуры на нужной позицици среди цепи связанных 
										 * между собой структур.
										 * Завершаем функцию и возвращам адресс найденого экземпляра структуры указатель */
}



int			main(void)
{
	t_list	*list;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */
	t_list	*tmp;

	list = ft_create_elem("Bro ");		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list,
										 * который мы сохраним в указателе на экземпляр структуры типа t_list */
	list->next = ft_create_elem("Hey ");/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list 
										 * И сохранит этот адресс в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
										 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	/* И создадим еще дополнительно несколько экземпляров структуры, которые свяжем между собой и с предыдущим экземпляром */
	list->next->next = ft_create_elem("Hello ");
	list->next->next->next = ft_create_elem("My ");
	list->next->next->next->next = ft_create_elem("Cool ");
	list->next->next->next->next->next = ft_create_elem("Friend ");

	tmp = ft_list_at(list, 3);			/* Оправляем в функцию 'ft_list_at' адресс первого экземпляра структуры цепи связанных между собой последова-
										 * тельно экземпляров структур и число отражающее позицию нужного нам экземпляра стурктуры, который находится
										 * в этой цепи связанных между собой последовательно экземпляров структур.
										 * Функция вернет адресс экземпляра структуры, который мы сохраним в указателе */
	ft_putstr(tmp->data);				/* Напечатаем содержимое полученого нами экземпляра структуры, для проверки работы функции 'ft_list_at' */
	ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	return (0);							/* Завершаем функцию и возвращаем ноль */
}