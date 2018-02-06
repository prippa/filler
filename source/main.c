/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:52:08 by prippa            #+#    #+#             */
/*   Updated: 2018/02/05 15:52:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fi_initialize(t_filler *fil)
{
	char *line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	fil->mine = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	fil->enemy = (fil->mine == 'O') ? 'X' : 'O';
	free(line);
	if ((fi_get_board(fil)) == -1)
		return (-1);
	if ((fi_get_figur(fil)) == -1)
		return (-1);
	return (1);
}

int			main(void)
{
	t_filler	fil;

	if ((fi_initialize(&fil)) == -1)
		return (-1);
	ft_dprintf(2, "mine - %c, enemy - %c\n", fil.mine, fil.enemy);
	ft_dprintf(2, "BOARD (y - %d, x - %d)\n", fil.b_y, fil.b_x);
	ft_putarr_fd(2, fil.board);
	ft_dprintf(2, "FIGUR (y - %d, x - %d)\n", fil.f_y, fil.f_x);
	ft_putarr_fd(2, fil.figur);
	write(1, "8 2\n", 4);
	return (1);
}
