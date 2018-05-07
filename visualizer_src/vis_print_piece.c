/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_print_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:29:47 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:29:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void	vis_piece_logic_while_body(t_visualizer *vis)
{
	if (vis->buf[vis->i] == '.')
		ft_printf("%s%c", VIS_SPACE, VIS_OP_CHAR);
	else if (vis->buf[vis->i] == '*')
		ft_printf("%s%c", VIS_PIECE, VIS_OP_CHAR);
}

static int	vis_print_piece_logic(t_visualizer *vis)
{
	int che;

	ft_str_free(&vis->buf);
	vis->j = 0;
	while (vis->j < vis->piece_y && (che = get_next_line(0, &vis->buf)) > 0)
	{
		vis->i = 0;
		ft_printf("%s%c%s", BOLD_CYAN, '|', COLOR_RESET);
		while (vis->buf[vis->i])
		{
			vis_piece_logic_while_body(vis);
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

static void	vis_print_got(t_visualizer *vis)
{
	int i;

	i = 0;
	while (vis->buf[i])
	{
		if (vis->buf[i] == 'O')
		{
			ft_printf("%s%c", VIS_PLAYER_1, VIS_OP_CHAR);
			vis->player_1_score++;
		}
		else if (vis->buf[i] == 'X')
		{
			ft_printf("%s%c", VIS_PLAYER_2, VIS_OP_CHAR);
			vis->player_2_score++;
		}
		else
			ft_printf("%s%c%s", BOLD_WHITE, vis->buf[i], COLOR_RESET);
		i++;
	}
	ft_putchar('\n');
}

static int	vis_print_piece_main(t_visualizer *vis)
{
	ft_printf("\n%s<Piece: y = %d, x = %d%s\n",
		BOLD_WHITE, vis->piece_y, vis->piece_x, COLOR_RESET);
	vis_print_frame(vis->piece_x * 2, '-', BOLD_CYAN);
	if ((vis_print_piece_logic(vis)) == -1)
		return (-1);
	vis_print_frame(vis->piece_x * 2, '-', BOLD_CYAN);
	ft_str_free(&vis->buf);
		if ((get_next_line(0, &vis->buf)) == -1)
			return (-1);
	vis_print_got(vis);
	vis_print_score(vis);
	return (1);
}

int			vis_print_piece(t_visualizer *vis, int flag)
{
	if (flag)
	{
		ft_str_free(&vis->buf);
		if ((get_next_line(0, &vis->buf)) == -1)
			return (-1);
	}
	fi_get_y_x(vis->buf, &vis->piece_y, &vis->piece_x);
	if (vis->bonus_flags[VIS_FLAG_D])
	{
		if ((vis_print_piece_main(vis)) == -1)
			return (-1);
	}
	else
	{
		vis_skip_line(vis->piece_y);
		if (vis_skip_line(1) == -1)
			return (-1);
	}
	return (1);
}
