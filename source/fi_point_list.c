#include "filler.h"

int		fi_point_add(t_filler *fil)
{
	t_point *tmp;

	if (!(tmp = (t_point *)malloc(sizeof(t_point))))
		return (-1);
	tmp->point_y = Y;
	tmp->point_x = X;
	tmp->touched_y = fil->point_y;
	tmp->touched_x = fil->point_x;
	tmp->next = fil->point;
	fil->point = tmp;
	return (1);
}

void	fi_point_free(t_filler *fil)
{
	while (fil->point)
	{
		free(fil->point);
		fil->point = fil->point->next;
	}
}
