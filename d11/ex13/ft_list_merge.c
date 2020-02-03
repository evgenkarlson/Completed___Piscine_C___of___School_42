/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 06:20:37 by adespond          #+#    #+#             */
/*   Updated: 2015/09/17 06:38:23 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list;

	list = *begin_list1;
	while (list->next != 0)
		list = list->next;
	list->next = begin_list2;
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (*begin_list1)
	{
		list_ptr = *begin_list1;
		while (list_ptr->next)
			list_ptr = list_ptr->next;
		list_ptr->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */