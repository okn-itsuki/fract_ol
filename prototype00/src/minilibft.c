#include "fractol.h"

// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main(int ac,char **av)
// {
//     printf("%d\n",ft_strcmp(av[1],"test"));
//     printf("%d\n",strcmp(av[1],"test"));
//     return (0);
// }
