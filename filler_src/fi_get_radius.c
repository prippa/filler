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

int			fi_get_radius(t_filler *fil, t_point *tmp)
{
	int radius;

	radius = 1;
	while (1)
	{
		if ((tmp->y_up = tmp->y - radius) < 0)
			tmp->y_up = 0;
		if ((tmp->y_down = tmp->y + radius) >= fil->b_y)
			tmp->y_down = fil->b_y - 1;
		if ((tmp->x_left = tmp->x - radius) < 0)
			tmp->x_left = 0;
		if ((tmp->x_right = tmp->x + radius) >= fil->b_x)
			tmp->x_right = fil->b_x - 1;
		if ((fi_check_top_right(fil, tmp)))
			break ;
		if ((fi_check_bottom_left(fil, tmp)))
			break ;
		radius++;
	}
	return (radius);
}
