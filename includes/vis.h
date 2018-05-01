#ifndef VIS_H
# define VIS_H

# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_visualizer
{
	char			*player_1;
	char			*player_2;
	char			*buf;
}					t_visualizer;

int		fi_vis_start_entry(t_visualizer *vis);

#endif
