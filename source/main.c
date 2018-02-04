#include "filler.h"

int main(void)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 20)
	{
		get_next_line(0, &line);
		write(2, line, ft_strlen(line));
		write(2, "\n", 1);
		free(line);
		i++;
	}
	write(1, "8 2\n", 4);
	return (0);
}
