/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:08:12 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 16:36:08 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(const char *str)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= '0' && str[a] <= '9')
			a++;
		else if (str[a] == '.')
		{
			a++;
			c++;
		}
		else if (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
			a++;
		else if (str[a] == '-' || str[a] == '+')
			a++;
		else
			return (0);
	}
	if (c > 1)
		return (0);
	return (1);
}

double	ft_atofrac(const char **str)
{
	double	res;
	double	power;

	res = 0.0;
	power = 1.0;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10.0 + (**str - '0');
		power = power * 10.0;
		(*str)++;
	}
	return (res / power);
}

double	ft_atodigit(const char **str)
{
	double	res;

	res = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10.0 + (**str - '0');
		(*str)++;
	}
	return (res);
}

double	float_conversion(const char *str)
{
	double	res;
	double	sign;

	res = 0.0;
	sign = 1.0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	res = ft_atodigit(&str);
	if (*str == '.')
	{
		res += ft_atofrac(&str);
	}
	return (res * sign);
}

double	ft_atof(const char *str)
{
	if (!(check_input(str) == 1))
	{
		perror("ERROR : wrong input string\n");
		exit(EXIT_FAILURE);
	}
	return (float_conversion(str));
}
