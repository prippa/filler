/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_get_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:16:09 by prippa            #+#    #+#             */
/*   Updated: 2018/02/06 13:16:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define BP fil->board[y + Y][x + X]

static int	fi_check_point(t_filler *fil, int y, int x, int flag)
{
	while (y < fil->f_y)
	{
		x = 0;
		while (x < fil->f_x)
		{
			if (fil->figur[y][x] == '*' && BP == fil->mine)
			{
				if (flag > 1)
					return (0);
				fil->point_y = y + Y;
				fil->point_x = x + X;
				flag++;
			}
			else if (fil->figur[y][x] == '*' && BP == fil->enemy)
				return (0);
			x++;
		}
		y++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int			fi_get_points(t_filler *fil)
{
	Y = 0;
	while (Y < fil->b_y)
	{
		X = 0;
		while (X < fil->b_x)
		{
			if ((Y + fil->f_y) <= fil->b_y
				&& (X + fil->f_x) <= fil->b_x
				&& fi_check_point(fil, 0, 0, 0))
			{
				if ((fi_point_add(fil)) == -1)
					return (-1);
			}
			X++;
		}
		Y++;
	}
	return (1);
}
