/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:42:03 by lverniss          #+#    #+#             */
/*   Updated: 2014/08/03 19:21:02 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_space(int nb_space, int stars)
{
	int		count;

	count = -1;
	while (++count < (nb_space - stars))
		ft_putchar(' ');
	ft_putchar('/');
}

void	write_stars(int stars, int door, char end)
{
	int		count;

	count = -1;
	while (++count < stars - door / 2)
		ft_putchar('*');
	if (end)
		ft_putchar('\\');
}

void	write_door(int door, int lines, int size)
{
	int		count;

	count = -1;
	while (++count < door)
	{
		if (size > 4 && lines == size / 2 - !(size % 2) && count + 2 == door)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
}

void	sastantua(int size)
{
	unsigned int	count;
	unsigned int	lines;
	unsigned int	door;
	unsigned int	nb_space;
	unsigned int	stars;

	count = -1;
	nb_space = -2 - size / 2 - size % 2;
	while (++count < size)
		nb_space += 5 + count / 2 + count;
	count = -1;
	stars = 0;
	while (++count < size)
	{
		lines = 2 + count + 1;
		while (lines-- && !(door = 0))
		{
			if (count + 1 == size && lines < ((size - 1) / 2) * 2 + 1)
				door = ((size - 1) / 2) * 2 + 1;
			write_space(nb_space, stars), write_stars(stars, door, 0);
			(door > 0) ? write_door(door, lines, size) : ft_putchar('*');
			write_stars(stars++, door, 1), ft_putchar('\n');
		}
		stars += 2 + count / 2;
	}
}
