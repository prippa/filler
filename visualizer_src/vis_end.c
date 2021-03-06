/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:29:31 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:29:32 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int	vis_get_score(t_visualizer *vis)
{
	if (ft_strchr(vis->buf, 'O'))
		vis->player_1_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	else
		vis->player_2_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	ft_str_free(&vis->buf);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	if (ft_strchr(vis->buf, 'O'))
		vis->player_1_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	else
		vis->player_2_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	ft_str_free(&vis->buf);
	return (1);
}

void		vis_print_score(t_visualizer *vis)
{
	char c;

	if (vis->player_1_score > vis->player_2_score)
		c = '>';
	else if (vis->player_1_score < vis->player_2_score)
		c = '<';
	else
		c = '=';
	ft_printf("\n\t%s %s%s%s %s(%d)%s %s%c%s %s(%d)%s %s%s%s%s\n\n",
		VIS_PLAYER_1, BOLD_YELLOW, vis->player_1, COLOR_RESET,
		BOLD_WHITE, vis->player_1_score, COLOR_RESET,
		BOLD_GREEN, c, COLOR_RESET,
		BOLD_WHITE, vis->player_2_score, COLOR_RESET,
		BOLD_MAGENTA, vis->player_2, COLOR_RESET, VIS_PLAYER_2);
}

int			vis_the_end(t_visualizer *vis)
{
	if (!vis->bonus_flags[VIS_FLAG_D])
	{
		if ((vis_get_score(vis)) == -1)
			return (-1);
		vis_print_score(vis);
	}
	return (0);
}

int			vis_end(t_visualizer *vis)
{
	ft_str_free(&vis->buf);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	if (ft_strstr(vis->buf, "fin"))
		return (vis_the_end(vis));
	else if (ft_strstr(vis->buf, "Piece"))
		return (vis_break(vis));
	return (1);
}
