/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_print_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:29:59 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:30:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int	vis_print_board_logic(t_visualizer *vis)
{
	int che;

	ft_str_free(&vis->buf);
	vis->j = 0;
	while (vis->j < vis->map_y && (che = get_next_line(0, &vis->buf)) > 0)
	{
		vis->i = 0;
		ft_printf("%s%c%s", BOLD_CYAN, '|', COLOR_RESET);
		while (vis->buf[vis->i])
		{
			if (vis->buf[vis->i] == '.')
				ft_printf("%s%c", VIS_SPACE, VIS_OP_CHAR);
			else if (vis->buf[vis->i] == 'o' || vis->buf[vis->i] == 'O')
				ft_printf("%s%c", VIS_PLAYER_1, VIS_OP_CHAR);
			else if (vis->buf[vis->i] == 'x' || vis->buf[vis->i] == 'X')
				ft_printf("%s%c", VIS_PLAYER_2, VIS_OP_CHAR);
			vis->i++;
		}
		ft_printf("%s%c%s\n", BOLD_CYAN, '|', COLOR_RESET);
		ft_str_free(&vis->buf);
		vis->j++;
	}
	if (che == -1)
		return (-1);
	return (1);
}

int			vis_print_board(t_visualizer *vis)
{
	if (vis_skip_line(1) == -1)
		return (-1);
	vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	if ((vis_print_board_logic(vis)) == -1)
		return (-1);
	vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	return (1);
}
