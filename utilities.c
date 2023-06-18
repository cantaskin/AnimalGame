#include "Animal.h"

void	*my_memset(void *str, int letter, size_t n)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)str;
	index = 0;
	while (index < n)
	{
		ptr[index] = letter;
		index++;
	}
	return (ptr);
}
size_t	my_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index])
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}

void	*my_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;	

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!(dst))
		return (0);
	my_memset(dst, 0, tot_size);
	return (dst);
}

int	find_len(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*my_itoa(int n)
{
	char	*str;
	int		digit;

	digit = find_len(n);
	str = (char *) my_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			my_strlcpy(str, "-2147483648", digit + 1);
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*(str + --digit) = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	my_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s)
		while (s[index] != '\0')
			write(fd, &s[index++], 1);
}

int	my_atoi(const char *str)
{
	long int	number;
	int			isaret;

	isaret = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isaret = -1;
		str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0') * isaret;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		str++;
	}
	return (number);
}

int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}
