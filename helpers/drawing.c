/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:46:01 by mesafi            #+#    #+#             */
/*   Updated: 2021/01/25 12:46:02 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizer.h>

static int newCursor = 6;
static int oldCursor = 5;

static void	filler(t_kit *kit, char cursor[64][64], int *processesAlive)
{
	t_process	*node;

	node = kit->procs;
	while (node != NULL)
	{
		cursor[(node->pc - 1) % 64][(node->pc - 1) / 64] = newCursor;
		cursor[(node->op_pc - 1) % 64][(node->op_pc - 1) / 64] = oldCursor;
		node = node->next;
		*processesAlive += 1;
	}
}

static int	getBackground(char cursor, int playerId)
{
	if (cursor == newCursor)
		return (newCursor);
	else
		return (playerId);
}

static int	getForeground(char cursor, int playerId)
{
	// if (cursor == newCursor || cursor == oldCursor)
	// 	return (playerId);
	// else
		return (0);
}

void		drawing(t_dlist *node)
{
	int		i;
	int		x;
	int		y;
	t_kit	*kit;
	char	hex[3];
	char	cursor[64][64] = {0};
	int		processesAlive = 0;
	int		background;
	int		foreground;

	kit = (t_kit *)(node->content);
	i = -1;
	filler(kit, cursor, &processesAlive);
	while (++i < MEM_SIZE)
	{
		x = (i % 64);
		y = (i / 64);
		background = getBackground(cursor[x][y], kit->procs->arena[1][i]);
		foreground = getForeground(cursor[x][y], kit->procs->arena[1][i]);
		x = x + (19 * x) - (WIDTH / 2);
		y = y - (21 * y) + (HEIGHT / 2);
		rectangle(x, y, x + 19, y - 19, background);
		if (kit->procs->arena[1][i])
		{
			sprintf(hex, "%02X", kit->procs->arena[0][i]);
			hex[2] = 0;
			renderBitmapString(x + 2, y - 14, hex, foreground);
		}
	}
}
