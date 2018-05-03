#include "vis.h"

static int	vis_print_board(t_visualizer *vis)
{
	int che;

	ft_str_free(&vis->buf);
	vis->j = 0;
	while (vis->j < vis->map_y && (che = get_next_line(0, &vis->buf)) > 0)
	{
		vis->i = 0;
		ft_printf("\t%s%c%s", BOLD_CYAN, '|', COLOR_RESET);
		while (vis->buf[vis->i])
		{
			if (vis->buf[vis->i] == '.')
				ft_printf("%s ", VIS_SPACE);
			else if (vis->buf[vis->i] == 'o' || vis->buf[vis->i] == 'O')
				ft_printf("%s ", VIS_PLAYER_1);
			else if (vis->buf[vis->i] == 'x' || vis->buf[vis->i] == 'X')
				ft_printf("%s ", VIS_PLAYER_2);
			vis->i++;
		}
		ft_printf("%s%c%s\n", BOLD_CYAN, '|', COLOR_RESET);
		ft_str_free(&vis->buf);
		vis->j++;
	}
	if (che == -1)
		return (-1);
	return (1);
}

static int	vis_print_pice(t_visualizer *vis)
{
	vis->i = 0;
	vis->j = 0;
	ft_str_free(&vis->buf);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	fi_get_y_x(vis->buf, &vis->i, &vis->j);
	vis_skip_line(vis->i);
	return (1);
}

static int	vis_game_while_body(t_visualizer *vis)
{
	ft_clear();
	ft_printf("\n\t\t\t%s %s%s%s %s%s%s %s%s%s%s\n\n",
		VIS_PLAYER_1, BOLD_WHITE, vis->player_1, COLOR_RESET,
		BOLD_RED, "VS", COLOR_RESET,
		BOLD_MAGENTA, vis->player_2, COLOR_RESET, VIS_PLAYER_2);
	if (vis_skip_line(1) == -1)
		return (-1);
	vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	if ((vis_print_board(vis)) == -1)
		return (-1);
	vis_print_frame(vis->map_x * 2, '-', BOLD_CYAN);
	if ((vis_print_pice(vis)) == -1)
		return (-1);
	if (vis_skip_line(1) == -1)
		return (-1);
	return (vis_end(vis));
}

int			vis_game(t_visualizer *vis)
{
	int status;

	while (42)
	{
		status = vis_game_while_body(vis);
		if (status == -1)
			return (-1);
		else if (status == 0)
			return (0);
		// sleep(1);
		usleep(70000);
	}
	return (1);
}
