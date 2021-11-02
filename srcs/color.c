/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:31:00 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/02 12:02:06 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	lerp_color(int c_a, int c_b, float f)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = ((c_b >> 24 & 0xff) - (c_a >> 24 & 0xff)) * f + (c_a >> 24 & 0xff);
	r = ((c_b >> 16 & 0xff) - (c_a >> 16 & 0xff)) * f + (c_a >> 16 & 0xff);
	g = ((c_b >> 8 & 0xff) - (c_a >> 8 & 0xff)) * f + (c_a >> 8 & 0xff);
	b = ((c_b & 0xff) - (c_a & 0xff)) * f + (c_a & 0xff);

	return (create_trgb(t, r, g, b));
}
