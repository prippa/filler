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

static int	fi_get_player(t_filler *fil)
{
	char *line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	fil->mine = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	fil->enemy = (fil->mine == 'O') ? 'X' : 'O';
	free(line);
	return (1);
}

static int	fi_initialize(t_filler *fil)
{
	fil->point = NULL;
	fil->board = NULL;
	fil->figur = NULL;
	if ((fi_get_board(fil)) == -1)
		return (-1);
	if ((fi_get_figur(fil)) == -1)
		return (-1);
	if ((fi_get_points(fil)) == -1)
		return (-1);
	fil->point_y = 0;
	fil->point_x = 0;
	return (1);
}

int			main(void)
{
	t_filler	fil;

	if ((fi_get_player(&fil)) == -1)
		return (-1);
	fil.game = 1;
	while (fil.game)
	{
		if ((fi_initialize(&fil)) == -1)
			return (-1);
		if (fil.point)
			fi_algorithm(&fil);
		else
			fil.game = 0;
		ft_arr_free(&fil.figur);
		fi_point_free(&fil);
		ft_printf("%d %d\n", fil.point_y, fil.point_x);
	}
	ft_arr_free(&fil.board);
	return (1);
}
