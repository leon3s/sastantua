/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/31 21:08:48 by lverniss          #+#    #+#             */
/*   Updated: 2014/08/02 02:53:14 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sastantua(int size)
{
	unsigned int	nb_spaces;
	unsigned int	stars;
	unsigned int	count;
	unsigned int	lines;

	count = -1;
	stars = -2 - size / 2 - size % 2;
	lines = 0;
	int		cn = -1;
	while (++count < size)
	{
		lines += 2 + count + 1;
		stars += 5 + count / 2 + count;
	}
	nb_spaces = stars;
	stars = 0;
	count = -1;
	int		carry;
	carry = 0;
	while (++count < size)
	{
		lines = 2 + count + 1;
		while (lines--)
		{
			int		x = -1;
			cn = -1;
			int		door;
			door = 0;
			carry = 0;
			if (count + 1 == size && lines < ((size - 1) / 2) * 2 + 1)
			{
				door = ((size - 1) / 2) * 2 + 1;
				carry = 1;
			}
			while (++cn < (nb_spaces - stars))
				ft_putchar(' ');
			ft_putchar('/');
			while (++x < (signed)stars - door / 2)
				ft_putchar('*');
			if (!carry)
				ft_putchar('*');
			else
			{
				int		car;
				car = -1;
				while (++car < door)
				{
					if (size > 4 && lines == size / 2 - !(size % 2) && car + 2 == door)
						ft_putchar('$');
					else
						ft_putchar('|');
				}
			}
			x = -1;
			while (++x < stars - door / 2)
				ft_putchar('*');
			ft_putchar('\\');
			stars++;
			ft_putchar('\n');
		}
		stars += 2 + count / 2;
	}
}

int		main(int ac, char **av)
{

	if ((ac != 2))
		return (0);
	sastantua(atoi(av[1]));
	return (1);
}
