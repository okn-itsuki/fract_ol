#include <stdbool.h>
#include <stdio.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_valid_double(const char *arg)
{
	int	dot_count;
	int	digit_count;

	digit_count = 0;
	dot_count = 0;
	if (!arg || !*arg)
		return (false);
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!*arg)
		return (false);
	while (*arg)
	{
		if (*arg == '.')
			dot_count++;
		else if (!ft_isdigit(*arg))
			return (false);
		else if (ft_isdigit(*arg))
			digit_count = 1;
		arg++;
	}
	if (dot_count > 1 || digit_count < 1)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	int res;
	if (ac == 2)
		res = is_valid_double(av[1]);

	if (res)
		printf("true");
	else
		printf("false");
	printf("\n");
	return (0);
}