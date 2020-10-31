/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:15:13 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include "unistd.h"
#include "ft_stock_par.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int					ft_isspace(char c)/* Функция узнает является ли наш символ разделителем между словами */
{
	return (c == ' ' || c == '\t' || c == '\n');/* Если наш символ это пробел или табуляция, или концом строки */
								/* То завершаем функцию и возвращаем '1' */ 
								/* Если это какой то др символ то завершаем функцию и возвращаем '0' */
}



int					ft_wordcount(char *str)/* Функция считает количество слов в строке */
{
	int		words;				/* Обьявляем переменную для хранения количества найденых слов */

	words = 0;					/* Инициализируем переменную хранящую количество найденых слов нулем */
	while (*str)				/* Запускаем цикл который пройдеться по строке и посчитает слова пока не дойдет до конца строки */
	{
		if (!(words) && !(ft_isspace(*str)))/* Если нам не встречались символы слова и эта ячейка содержит не пустой символ */ 
			words++;			/* Значит мы встретили первое слово. Прибавляем к переменной один */
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))/* Если в этой ячейке ячейке хранится первая буква слова */
			words++;			/* Значит мы встретили еще одно слово. Прибавляем к переменной один */
		str++;					/* Проходимся по всему массиву символо(строке) пока не дойдем до последней */
	}
	return (words);				/* Завершаем функцию и возвращаем количество слов в строке */
}



int					ft_wordlen(char *str)/* Функция вычисляет размер первого слова найденого в строке */
{
	int		len;				/* Обьявляем переменную для хранения размера слова */

	len = 0;					/* Инициализируем переменную хранящую размер слова нулем */
	while (ft_isspace(*str))	/* Цикл пропустит символы в начале массива, которые не являются словом */
		str++;
	while (*str && !(ft_isspace(*str)))/* Цикл который будет считать каждый символ пока не закончится слово */
	{
		str++;
		len++;
	}
	return (len);				/* Завершаем функцию и возвращаем размер слова */
}



char				**ft_split_whitespaces(char *str)/* функция разбирает строку на отдельные слова создавая для них массивы символов, 
								 * записывает адреса созданных массивов в массив указателлей на указатели и 
								 * возвращает адресс массива указателей на указатели */
{
	int		i;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданным строкам */
	int		j;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданному массиву символов */
	char	**arr;				/* Обьявляем указатель на указатель в который мы сохраним адресс выдленой памяти с адресами массивов */
	int		words;				/* Обьявим переменную для хранения вычесленного количества строк */

	words = ft_wordcount(str);	/* Вызываем функцию по вычислению количества слов в строке и записываем результат в переменную */
	i = 0;						/* Инициализируем счетчик 'i' нулем чтобы начать работу с нулевого массива */
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))/* Выделяем память нужного размера
								 * под указатели на адресам массивов которые будут содержать строки со словами.
								 * И проверяем прошло ли выделение памяти без ошибок. */ 
		return ((void*)0);		/* Если были проблемы то завершаем функцию и возвращаем нулевой указатель */
	/* Если выше всё прошло удачно то мы переходим к созданию памяти для каждого слова */
	while (i < words)			/* Этот цикл будет создавать память под слова и записывать символы этих слов в выделеную память  */
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str) + 1))) == ((void *)0))/* Выделяем память под указатели(их будет
								 * столько же сколько слов нашла функция ft_wordcount в строке, плюс один указатель под завершающий
								 * - нулевой указатель). В эти указатели мы поместим адреса каждого добытого слова помещеных в строку
								 * (массивов символов). И проверяем прошло ли выделение памяти без ошибок. */ 
			return ((void*)0);	/* Если что то пошло не так то завершаем функцию и возвращаем нулевой указатель */
		j = 0;					/* Инициализируем счетчик 'j' нулем чтобы начать работу с нулевой ячейки выбранного массива */
		while (ft_isspace(*str))/* Пропускаем ячейки с символами которые не являються частью слова */
			str++;				/* чтобы добраться до ячейки массива где начинается слова */
		while (*str && !(ft_isspace(*str)))/* Пока мы не дошли символа конца строки или не встретили пустой символ */
			arr[i][j++] = *str++;/* Копируем символы найденого текущего слова в новый массив */
		arr[i][j] = '\0';		/* После слова в конце массива добавляем символ конца массива */
		i++;					/* Переходим к след строке чтобы скопировать туда след слово, которое мы найдем с помощью
								 * str, в котором сохранилась информация о позиции ячейки после прошлого слова. 
								 * Эту позицию мы и используем как точку отсчета для поиска нового(последующего) слова */
	}
	arr[i] = ((void*)0);		/* В конце массива указателей на указатели, хранящего адреса строк, добавляем нулевой адрес как 
								 * символ конца этого массива указателей на указатели */
	return (arr);				/* Заавершаем функцию и возвращаем адресс массива с указателями на указатели(адреса массивов со
								 * словами) */
}

/*#############################################################################*/


struct s_stock_par	*ft_param_to_tab(int ac, char **av)	/* Функция принимает в аргументах целое число с количеством строк, адресс массива строк(массивов символов), и
								 * разбирает каждую строку массива строк на состовляющие(делает копию строки, получает размер строки, отделяет слова в строке друг от 
								 * друга и сохраняет их отдельно в массив строк), а потом сохраняет получены данные по экземплярам и в самом конце возвращает сам адрес
								 * массива с экземплярами структуры "struct s_stock_par" */
{
	int			i;				/* Обьявляем переменную для счетчика, чтобы перемечаться по экземплярам структур и строкам массива строк "av" */
	int			j;				/* Обьявляем переменную для счетчика, которую используем для подсчета выбранной строки и для перемещения по символам выбраной строки */
	t_stock_par	*ret;			/* Создаем указатель на экземпляр структуры "t_stock_par"(struct s_stock_par), который будет хранить адрес выделеной памяти */

	if ((ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))/* выделяем память типа "t_stock_par"(struct s_stock_par) под массив экземпляров 
								 * на столько же экземпляров сколько у нас строк храниться в массиве строк "av" и плюс один для завершающего нуля */
		return ((void *)0);		/* Если что то пошло не так то возвращаем указатель типа NULL и завершаем функцию */
	i = 0;						/* Инициализируем счетчик i нулем чтобы начать разбор каждой строки массива строк на состовляющие части с нулевой ячейки и записывать 
								 * извлеченные данные в экземпляры структуры типа "t_stock_par"(struct s_stock_par) начиная с нулевого экземпляра */
	while (i < ac)				/* Запускаем цикл который разберет каждую строку из массива строк и заполнит этим каждый экземпляр типа t_stock_par"(struct s_stock_par) */
	{
		j = 0;					/* Инициализируем 'j' нулем для подсчета туда количества символов текущей строки*/
		while (av[i][j])		/* Запускаем цикл подсчета количества симолов в строке */
			j++;
		ret[i].size_param = j;	/* Сохраняем найденое количество символов в переменной "size_param" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
		ret[i].str = av[i];		/* Сохраняем адрес текущей строки в указателе "str" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
		if((ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1))) == ((void *)0))/* Выделяем память для копирование текущей строки и сохраняем адресс 
								 * выделеной памяти в указателе "copy" текущего экземпляра типа t_stock_par"(struct s_stock_par) */
			return ((void *)0);	/* Если что то пошло не так то возвращаем указатель типа NULL и завершаем функцию */
		j = 0;					/* Записываем ноль в перменную 'j' для использования её как счетчика при копировании текущей строки в выделеную память */
		while (j < ret[i].size_param)/* Запускаем цикл, который скопирует текущую строку в выделеную для нее память */
		{
			ret[i].copy[j] = av[i][j];/* Копируем каждый символ из текущей строки в выделеную память */
			j++;					  /* увеличиваем счетчик для перехода к след ячейке с символом */
		}
		ret[i].copy[j] = '\0';	/* после создания дубликата строки в конце добавляем завершающий символ нуля */
		ret[i].tab = ft_split_whitespaces(av[i]);/* Запускаем функцию которая разберет текущую строку на слова */
		i++;					/* увеличиваем счетчик для перехода к след экземпляру типа t_stock_par"(struct s_stock_par) */
	}
	ret[i].str = ((void *)0);	/* Сохраняем "нулевой указатель" в указателе "str" последнего экземпляра типа t_stock_par"(struct s_stock_par) как символ того что этот
								 * экземпляр пустой и создан как */ 
	return (ret);				/* Возвращаем адрес нулевого экземпляра полученых и завершаем функцию */
}


/*#############################################################################*/


void				ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void				ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/*#############################################################################*/

void				ft_putnbr(int nb)		/* Функция печати числа */
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

/*#############################################################################*/

void				ft_show_tab(struct s_stock_par *par)/* Функция печати структуры. Печать будет в таком порядке: копия строки, размер строки, слова из которых состоит строка */
{
	int	i;							/* Обьявляем переменную для счетчика чтобы перемечаться по экземплярам структур */
	int	j;							/* Обьявляем переменную для счетчика чтобы перемечаться от строки к строке и печатать таблицу со строками */

	i = 0;							/* Инициализируем счетчик нулем, чтобы начать работать с нулевой ячейки хранящей адресс самого первого экземпляра */
	while (par[i].str)				/* Если в текущей ячейке массива экземпляров структур у этого экземпляра хранится слово то запускаем цикл печатающий все его элементы */ 
	{
		ft_putstr(par[i].copy);		/* Печатаем дубликат строки "str", адрес которой хранится в указателе "copy" */
		ft_putchar('\n');			/* Печатаем символ перехода на новую строку */
		ft_putnbr(par[i].size_param);/* Печатаем число отображающее количество символов в строке "str" */
		ft_putchar('\n');			/* Печатаем символ перехода на новую строку */
		j = 0;						/* Инициализируем счетчик нулем. Он укажет какую строку в на текущей итерации нужно печатать */
		while (par[i].tab[j])		/* Если в текущей ячейке массива строк есть строка то запускаем цикл печати этой строки */
		{
			ft_putstr(par[i].tab[j++]);	/* Печатаем строку из текущей ячейки массива строк и увеличиваем счетчик переходя к след ячейке */
			ft_putchar('\n');			/* Печатаем символ перехода на новую строку */
		}
		i++;						/* Увеличиваем счетчик переходя к след ячейке массива экземпляров структур типа t_stock_par"(struct s_stock_par) */
	}
}



int    				 main(void)	/* Основаная функция */
{
	char	*arr_str[4] = {"строка_без_разделителей", "строка с пробелом", "строка	с	табами"};/* Обьявляем массив указателей, в который мы сохраним адреса строк.
								 * Когда мы помещаем строки в массив указателей, при компиляции, их места занимают адреса из памяти, по которым они будут распложены. */

	struct s_stock_par *a;		/* Создаем указатель на экземпляр структуры типа t_stock_par"(struct s_stock_par) */
	a = ft_param_to_tab(3, arr_str);/* Отправляем в аргументы функции - число с отображающее количество строк и адресс массива со строками */
								/* А теперь проверяем что получилось - печатаем результат */
	ft_show_tab(a);				/* Печатаем полученый в указатель адресс массива экземпляров типа t_stock_par"(struct s_stock_par) содержащий аргументы программы 
								 * разложеные на составляющие */

	return (0);					/* Возвращаем ноль и завершаем программу */
}