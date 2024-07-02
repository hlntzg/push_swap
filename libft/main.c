#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*s;
	char	c;
	char	**split;
	int		i;

	i = 0;
	s = "__hello_hi_bye__World__Kavini__";
	c = '_';
	printf("%s\n", s);
	split = ft_split(s, c);
	while (split[i])
	{
		printf("\n%s", split[i]);
		i++;
	}
	return (0);
}
