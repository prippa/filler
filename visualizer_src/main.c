/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_vis_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:47:59 by prippa            #+#    #+#             */
/*   Updated: 2018/03/15 15:48:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void	vis_init(t_visualizer *vis)
{
	vis->buf = NULL;
	vis->player_1 = NULL;
	vis->player_2 = NULL;
	vis->map_y = 0;
	vis->map_x = 0;
	vis->i = 0;
	vis->j = 0;
	vis->sleep = 25000;
	vis->flag_d = 0;
}

static int	vis_error(char *message)
{
	ft_dprintf(2, "%s\n", message);
	return (-1);
}

static void	vis_free(t_visualizer *vis)
{
	ft_str_free(&vis->buf);
	ft_str_free(&vis->player_1);
	ft_str_free(&vis->player_2);
}

static int	vis_get_bonus_flags(t_visualizer *vis, char **argv)
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
			vis->flag_d = 1;
		else
			return (-1);
		i++;
	}
	return (1);
}	

int			main(int argc, char **argv)
{
	t_visualizer	vis;

	vis_init(&vis);
	if (argc > 1)
	{
		if ((vis_get_bonus_flags(&vis, argv + 1)) == -1)
			return (vis_error("ERROR: Invalid flags"));
	}
	if ((vis_start_entry(&vis)) == -1)
		return (vis_error("ERROR: in START entry"));
	if ((vis_game(&vis)) == -1)
		return (vis_error("ERROR: in GAME entry"));
	vis_free(&vis);
	return (0);
}
