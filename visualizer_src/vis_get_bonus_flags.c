/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_get_bonus_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:29:07 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:29:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		vis_get_bonus_flags(t_visualizer *vis, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_isstrdigit(argv[i]))
		{
			vis->sleep = ft_atoi(argv[i]);
			if (vis->sleep < 1)
				return (-1);
		}
		else if (!ft_strcmp(argv[i], "-d"))
			vis->bonus_flags[VIS_FLAG_D] = 1;
		else if (!ft_strcmp(argv[i], "-s"))
			vis->bonus_flags[VIS_FLAG_S] = 1;
		else
			return (-1);
		i++;
	}
	return (1);
}
