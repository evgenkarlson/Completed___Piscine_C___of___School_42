# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bon.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 11:29:27 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/04 12:07:16 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 - Écrire une ligne de commande qui affiche le nombre d’utilisateurs du parc informatique dont le nom de famille contient "bon". (cela comprend aussi monsieur "bonheur")

 - Напишите командную строку, которая отображает количество пользователей компьютерного парка, чья фамилия содержит «bon». (это также включает в себя господин "bonheur")

_________________________________________________________________________________
touch bon.sh
_________________________________________________________________________________

_________________________________________________________________________________
ldapsearch 'cn=*bon*' cn | grep -v '#\|dn\|search\|result\|^[[:space:]]*$' | wc -l | sed 's/ //g'
_________________________________________________________________________________

			-=OR=-
_________________________________________________________________________________
ldapsearch -Q -S cn "(sn=*bon*)" cn | grep "^cn: " | wc -l | sed 's# * ##'
_________________________________________________________________________________

			-=OR=-
_________________________________________________________________________________
ldapsearch -Q sn="*bon*" | grep "^sn" | wc -l | tr -d ' '
_________________________________________________________________________________

			-=OR=-
_________________________________________________________________________________
ldapsearch -LLL "last-name=*bon*" last-name 2> /dev/null | sed -n '/last-name:/p' | wc -l | sed 's/ //g' 
_________________________________________________________________________________

##################################################################################
Документация.
##################################################################################
Google.com
##################################################################################