#include "vis.h"

int		vis_break(t_visualizer *vis)
{
	while (42)
	{
		vis_print_pice(vis, 0);
		ft_str_free(&vis->buf);
		if ((get_next_line(0, &vis->buf)) == -1)
			return (-1);
		if (ft_strstr(vis->buf, "Plateau"))
			return (1);
		else if (ft_strstr(vis->buf, "fin"))
			return (vis_the_end(vis));
	}
	return (1);
}
