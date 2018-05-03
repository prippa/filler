#include "vis.h"

static char	vis_op(int score_1, int score_2)
{
	if (score_1 > score_2)
		return ('>');
	else if (score_1 < score_2)
		return ('<');
	return ('=');
}

static int	vis_get_score(t_visualizer *vis)
{
	int score;

	if (ft_strchr(vis->buf, 'O'))
		vis->player_1_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	else
		vis->player_2_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	ft_str_free(&vis->buf);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	if (ft_strchr(vis->buf, 'O'))
		vis->player_1_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	else
		vis->player_2_score = ft_atoi(ft_strchr(vis->buf, ':') + 1);
	ft_str_free(&vis->buf);
	return (1);
}

static int	vis_the_end(t_visualizer *vis)
{
	// ft_printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$ %s", vis->buf);
	char c;

	if ((vis_get_score(vis)) == -1)
		return (-1);
	c = vis_op(vis->player_1_score, vis->player_2_score);
	ft_printf("\n\t\t\t%s %s%s%s (%d) %s%c%s (%d) %s%s%s%s\n\n",
		VIS_PLAYER_1, BOLD_WHITE, vis->player_1, COLOR_RESET,
		vis->player_1_score,
		BOLD_GREEN, c, COLOR_RESET,
		vis->player_2_score,
		BOLD_MAGENTA, vis->player_2, COLOR_RESET, VIS_PLAYER_2);
	return (0);
}

int			vis_end(t_visualizer *vis)
{
	ft_str_free(&vis->buf);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	if (ft_strstr(vis->buf, "fin"))
		return (vis_the_end(vis));
	return (1);
}
