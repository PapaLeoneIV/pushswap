#include "libft.h"

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(1, &s[i], 1);
		i++;
	}
}