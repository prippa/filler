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
	vis->sleep = 50000;
	ft_bzero(vis->bonus_flags, sizeof(int) * VIS_FLAGS_SIZE);
}

static void	vis_after_flags_init(t_visualizer *vis)
{
	if (vis->bonus_flags[VIS_FLAG_S])
		signal(SIGINT, vis_sound_off_signal);
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

int			main(int argc, char **argv)
{
	t_visualizer	vis;

	vis_init(&vis);
	if (argc > 1)
	{
		if ((vis_get_bonus_flags(&vis, argv + 1)) == -1)
			return (vis_error("ERROR: Invalid flags"));
	}
	vis_after_flags_init(&vis);
	vis_sound_on(1, vis.bonus_flags[VIS_FLAG_S]);
	if ((vis_start_entry(&vis)) == -1)
		return (vis_error("ERROR: in START entry"));
	if ((vis_game(&vis)) == -1)
		return (vis_error("ERROR: in GAME entry"));
	vis_free(&vis);
	vis_sound_off(vis.bonus_flags[VIS_FLAG_S]);
	return (0);
}
