/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:21:41 by prippa            #+#    #+#             */
/*   Updated: 2018/02/11 11:21:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fi_take_point(t_filler *fil, t_point *points)
{
	int radius;

	fil->point_y = points->point_y;
	fil->point_x = points->point_x;
	radius = points->radius;
	points = points->next;
	while (points)
	{
		if ((fil->mine == 'X' && points->radius <= radius)
		|| (fil->mine == 'O' && points->radius < radius))
		{
			fil->point_y = points->point_y;
			fil->point_x = points->point_x;
			radius = points->radius;
		}
		points = points->next;
	}
}

static void	fi_get_radius_of_one_point(t_filler *fil, t_point *point)
{
	int y;
	int x;

	y = 0;
	while (y < fil->f_y)
	{
		x = 0;
		while (x < fil->f_x)
		{
			if (fil->figur[y][x] == '*')
			{
				point->y = point->point_y + y;
				point->x = point->point_x + x;
				point->radius += fi_get_radius(fil, point);
			}
			x++;
		}
		y++;
	}
}

static void	fi_get_radius_of_all_points(t_filler *fil, t_point *points)
{
	while (points)
	{
		fi_get_radius_of_one_point(fil, points);
		points = points->next;
	}
}

void		fi_algorithm(t_filler *fil)
{
	fi_get_radius_of_all_points(fil, fil->point);
	fi_take_point(fil, fil->point);
}
