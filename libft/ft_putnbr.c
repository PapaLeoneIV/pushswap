#include "libft.h"

void	ft_putnbr(int n)
{
	char		c;
	long long	nl;

	nl = (long long)n;
	if (nl < 0)
	{
		nl *= -1;
		write(1, "-", 1);
	}
	if (nl >= 10)
	{
		ft_putnbr((nl / 10));
	}
	c = (unsigned int)(nl % 10) + '0';
	write(1, &c, 1);
}