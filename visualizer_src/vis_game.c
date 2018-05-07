/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:30:11 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:30:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int	vis_game_while_body(t_visualizer *vis)
{
	ft_clear();
	ft_printf("\n\t%s %s%s%s %s%s%s %s%s%s%s\n\n",
		VIS_PLAYER_1, BOLD_YELLOW, vis->player_1, COLOR_RESET,
		BOLD_RED, "VS", COLOR_RESET,
		BOLD_MAGENTA, vis->player_2, COLOR_RESET, VIS_PLAYER_2);
	if ((vis_print_board(vis)) == -1)
		return (-1);
	if ((vis_print_piece(vis, 1)) == -1)
		return (-1);
	return (vis_end(vis));
}

int			vis_game(t_visualizer *vis)
{
	int status;

	while (42)
	{
		status = vis_game_while_body(vis);
		if (status == -1)
			return (-1);
		else if (status == 0)
			return (0);
		if (vis->bonus_flags[VIS_FLAG_D])
			read(1, 0, 1);
		else
			usleep(vis->sleep);
	}
	return (1);
}
