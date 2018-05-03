#include "vis.h"

int			vis_print_pice(t_visualizer *vis, int flag)
{
	vis->i = 0;
	vis->j = 0;
	if (flag)
	{
		ft_str_free(&vis->buf);
		if ((get_next_line(0, &vis->buf)) == -1)
			return (-1);
	}	
	fi_get_y_x(vis->buf, &vis->i, &vis->j);
	vis_skip_line(vis->i);
	if (vis_skip_line(1) == -1)
		return (-1);
	return (1);
}
