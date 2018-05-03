#ifndef VIS_H
# define VIS_H

# include "libft.h"
# include "ft_printf.h"

# define VIS_PLAYER_1 "😇"
# define VIS_PLAYER_2 "😈"
# define VIS_SPACE "⚫"

typedef	struct		s_visualizer
{
	char			*player_1;
	char			*player_2;
	int				player_1_score;
	int				player_2_score;
	char			*buf;
	int				map_y;
	int				map_x;
	int				i;
	int				j;
}					t_visualizer;

int					vis_start_entry(t_visualizer *vis);
int					vis_game(t_visualizer *vis);
void				fi_get_y_x(char *str, int *y, int *x);
int					vis_skip_line(int how_many);
void				vis_print_frame(int count, char c, char *color);
int					vis_end(t_visualizer *vis);

#endif
