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

static void	vis_print_usage(void)
{
	ft_putstr("Usage: ./visualizer [plus number for usleep, -d, -s]\n");
	ft_putstr("####################### Flags Manual #######################\n");
	ft_putstr("[Plus number] : Delay next turn in milliseconds.\n");
	ft_putstr("-d : Debug mode.\n");
	ft_putstr("-s : Epic Mortal Kombat Theme Music.\n");
	ft_putstr("-help : prints usage.\n");
	ft_putstr("############################################################\n");
	exit(0);
}

int			vis_get_bonus_flags(t_visualizer *vis, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_isstrdigit(argv[i]) && ft_atoi(argv[i]) >= 0)
			vis->sleep = ft_atoi(argv[i]);
		else if (!ft_strcmp(argv[i], "-d"))
			vis->bonus_flags[VIS_FLAG_D] = 1;
		else if (!ft_strcmp(argv[i], "-s"))
			vis->bonus_flags[VIS_FLAG_S] = 1;
		else if (!ft_strcmp(argv[i], "-help"))
			vis_print_usage();
		else
			return (-1);
		i++;
	}
	return (1);
}
