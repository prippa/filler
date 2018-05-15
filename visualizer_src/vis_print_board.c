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

static void	vis_print_char(t_visualizer *vis, char c)
{
	if (c == '.')
		ft_printf("%s%c", VIS_SPACE, VIS_OP_CHAR);
	else if (c == 'o' && vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s%c", VIS_PLAYER_1_PIECE, VIS_OP_CHAR);
	else if (c == 'x' && vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s%c", VIS_PLAYER_2_PIECE, VIS_OP_CHAR);
	else if (c == 'o' || c == 'O')
		ft_printf("%s%c", VIS_PLAYER_1, VIS_OP_CHAR);
	else if (c == 'x' || c == 'X')
		ft_printf("%s%c", VIS_PLAYER_2, VIS_OP_CHAR);
	else if (ft_isdigit(c) && vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s%c%c%s", BOLD_WHITE,
		(vis->j == -1 ? ' ' : '\0'), c, COLOR_RESET);
	else if (vis->bonus_flags[VIS_FLAG_D])
		ft_putchar(' ');
}

static void	vis_print_board_base_logic_while_body(t_visualizer *vis)
{
	if (!vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s%c%s", BOLD_CYAN, '|', COLOR_RESET);
	while (vis->buf[vis->i])
	{
		vis_print_char(vis, vis->buf[vis->i]);
		vis->i++;
	}
	if (!vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s%c%s", BOLD_CYAN, '|', COLOR_RESET);
	ft_putchar('\n');
}

static int	vis_print_board_base_logic(t_visualizer *vis)
{
	int che;

	ft_str_free(&vis->buf);
	if (vis->bonus_flags[VIS_FLAG_D])
		vis->j = -1;
	else
		vis->j = 0;
	while (vis->j < vis->map_y && (che = get_next_line(0, &vis->buf)) > 0)
	{
		vis->i = 0;
		vis_print_board_base_logic_while_body(vis);
		ft_str_free(&vis->buf);
		vis->j++;
	}
	if (che == -1)
		return (-1);
	return (1);
}

int			vis_print_board(t_visualizer *vis)
{
	if (!vis->bonus_flags[VIS_FLAG_D])
	{
		if (vis_skip_line(1) == -1)
			return (-1);
	}
	if (vis->bonus_flags[VIS_FLAG_D])
		ft_printf("%s<Board: y = %d, x = %d%s\n",
			BOLD_WHITE, vis->map_y, vis->map_x, COLOR_RESET);
	if (!vis->bonus_flags[VIS_FLAG_D])
		vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	if ((vis_print_board_base_logic(vis)) == -1)
		return (-1);
	if (!vis->bonus_flags[VIS_FLAG_D])
		vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	return (1);
}
