/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:49:10 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/17 18:49:12 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H

/*
 ** Definitions
*/

# define VISUALIZER_H

# define MEM_SIZE 4096
# define WIDTH 896
# define HEIGHT 896
# define SIDE 448

/*
 ** Includes
*/

# include <stdio.h>
# include <GLUT/glut.h>
# include <GLUT/glutbitmap.h>
# include "../includes/virtual_machine.h"

/*
 ** Structures
*/


/*
 ** Functions ProtoType
*/

void	*visualizer(void *queue);
void	draw_map();
void	rectangle(int x1, int y1, int x2, int y2);
void	renderBitmapString(float x, float y, char *str);

#endif
