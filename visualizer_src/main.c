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

int			main(void)
{
	t_visualizer	vis;

	vis_init(&vis);
	if ((vis_start_entry(&vis)) == -1)
		return (vis_error("some error in START entry"));
	if ((vis_game(&vis)) == -1)
		return (vis_error("some error in GAME entry"));
	// ft_printf("%s\n%s\ny = %d\nx = %d\n", vis.player_1, vis.player_2, vis.map_y, vis.map_x);
	vis_free(&vis);
	return (0);
}
