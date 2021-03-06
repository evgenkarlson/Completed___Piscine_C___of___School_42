/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/17 00:58:40 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex13/
**  Файлы для сдачи: ft_list_merge.c, ft_list.h
**  Разрешенные функции: Никаких
**
** ************************************************************************** **
 *
 * 
 *	• Создайте функцию «ft_list_merge», которая помещает элементы списка 
 *	«begin2» в конец списка «begin1».
 *
 * 
 *	• Создание элемента не разрешено.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *			t_list	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (*begin_list1)
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *current;

	current = *begin_list1;
	while (current->next)
		current = current->next;
	current->next = begin_list2;
}


/* ************************************************************************** */
/* ************************************************************************** */