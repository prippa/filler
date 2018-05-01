#include "vis.h"

char	*fi_vis_get_player(char *str)
{
	int i;
	int j;
	
	str = ft_strchr(str, '[');
	i = 1;
	j = 1;
	while (str[i])
	{
		if (str[i] == '.')
			return (ft_strsub(str, j, i - j));
		else if (str[i] == '/')
			j = i + 1;
		i++;
	}
	return (NULL);
}

int		fi_vis_start_entry(t_visualizer *vis)
{
	int		i;
	int		catch_error;

	i = 0;
	while ((catch_error = get_next_line(0, &vis->buf)) > 0 && i < 9)
	{
		if (i == 6)
		{
			if (!(vis->player_1 = fi_vis_get_player(vis->buf)))
				return (-1);
		}
		else if (i == 8)
		{
			if (!(vis->player_2 = fi_vis_get_player(vis->buf)))
				return (-1);
		}
		ft_str_free(&vis->buf);
		i++;
	}
	if (catch_error == -1)
		return (-1);
	ft_str_to_upper(&vis->player_1);
	ft_str_to_upper(&vis->player_2);
	return (1);
}
