/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderBitmapString.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:49:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/17 18:49:46 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizer.h>

void	renderBitmapString(float x, float y, char *str) {
	int		i;

	glRasterPos2f(x, y);
	i = -1;
	while (str[++i])
		glutBitmapCharacter(GLUT_STROKE_ROMAN, str[i]);
}