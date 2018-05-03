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

static int	fi_check_top_right(t_filler *fil, t_point *tmp)
{
	X = tmp->x_left;
	while (X <= tmp->x_right)
	{
		if (fil->board[tmp->y_up][X] == fil->enemy)
			return (1);
		X++;
	}
	Y = tmp->y_up;
	while (Y <= tmp->y_down)
	{
		if (fil->board[Y][tmp->x_right] == fil->enemy)
			return (1);
		Y++;
	}
	return (0);
}

static int	fi_check_bottom_left(t_filler *fil, t_point *tmp)
{
	X = tmp->x_right;
	while (X >= tmp->x_left)
	{
		if (fil->board[tmp->y_down][X] == fil->enemy)
			return (1);
		X--;
	}
	Y = tmp->y_down;
	while (Y >= tmp->y_up)
	{
		if (fil->board[Y][tmp->x_left] == fil->enemy)
			return (1);
		Y--;
	}
	return (0);
}

static void	fi_get_radius(t_filler *fil, t_point *tmp)
{
	tmp->radius = 1;
	while (1)
	{
		if ((tmp->y_up = tmp->touched_y - tmp->radius) < 0)
			tmp->y_up = 0;
		if ((tmp->y_down = tmp->touched_y + tmp->radius) >= fil->b_y)
			tmp->y_down = fil->b_y - 1;
		if ((tmp->x_left = tmp->touched_x - tmp->radius) < 0)
			tmp->x_left = 0;
		if ((tmp->x_right = tmp->touched_x + tmp->radius) >= fil->b_x)
			tmp->x_right = fil->b_x - 1;
		if (fi_check_top_right(fil, tmp))
			break ;
		if (fi_check_bottom_left(fil, tmp))
			break ;
		tmp->radius++;
	}
}

void		fi_algorithm(t_filler *fil)
{
	t_point	*tmp;
	int		radius;

	tmp = fil->point;
	while (tmp)
	{
		fi_get_radius(fil, tmp);
		tmp = tmp->next;
	}
	tmp = fil->point;
	radius = tmp->radius;
	fil->point_y = tmp->point_y;
	fil->point_x = tmp->point_x;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->radius <= radius)
		{
			radius = tmp->radius;
			fil->point_y = tmp->point_y;
			fil->point_x = tmp->point_x;
		}
		tmp = tmp->next;
	}
}
