/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_get_y_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:14:43 by prippa            #+#    #+#             */
/*   Updated: 2018/02/05 16:14:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fi_get_y_x(char *str, int *y, int *x)
{
	int i;
	int flag;

	flag = 1;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (flag)
			{
				*y = ft_atoi(str + i);
				i += ft_nbrlen(*y);
				flag = 0;
			}
			else
			{
				*x = ft_atoi(str + i);
				i += ft_nbrlen(*x);
				break ;
			}
		}
		else
			i++;
	}
}
