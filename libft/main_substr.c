#include <stdio.h>
#include "libft.a"

int	main(void)
{
	char	*str;

	str = "nowORnever";
	printf("%s", ft_substr(str, 3, 12));
}
