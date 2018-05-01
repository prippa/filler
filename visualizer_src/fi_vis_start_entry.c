#include "vis.h"

char	*fi_vis_get_player(char *str)
{
	str = ft_strrchr(str, '.');
	str = ft_strchr(str, '[');
	// while (ft_strchr(str, '/'))
	// 	str = ft_strchr(str, '/');
	return (ft_strdup(str));
}

int		fi_vis_start_entry(t_visualizer *vis)
{
	int		i;
	int		catch_error;

	i = 0;
	ft_str_free(&vis->buf);
	while ((catch_error = get_next_line(0, &vis->buf)) > 0 && i < 9)
	{
		if (i == 5)
		{
			if (!(vis->player_1 = fi_vis_get_player(vis->buf)))
				return (-1);
		}
		else if (i == 7)
		{
			if (!(vis->player_2 = fi_vis_get_player(vis->buf)))
				return (-1);
		}
		ft_str_free(&vis->buf);
		i++;
	}
	if (catch_error == -1)
		return (-1);
	return (1);
}
