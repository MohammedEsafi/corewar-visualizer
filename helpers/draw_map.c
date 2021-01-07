/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:33:39 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/23 09:33:41 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizer.h>

static void	filler(t_kit *kit, char cursor[128][32], int *processesAlive)
{
	t_process	*node;

	node = kit->procs;
	while (node != NULL)
	{
		cursor[node->pc % 128][node->pc / 128] = NEW;
		cursor[node->op_pc % 128][node->op_pc / 128] = OLD;
		node = node->next;
		*processesAlive += 1;
	}
}

static int	getBackground(char cursor, int playerId)
{
	if (cursor == NEW)
		return (NEW);
	if (cursor == OLD)
		return (OLD);
	else
		return (playerId);
}

static int	getForeground(char cursor, int playerId)
{
	if (cursor == NEW || cursor == OLD)
		return (playerId);
	else
		return (0);
}

void		draw_map(t_dlist *node)
{
	int		i;
	int		x;
	int		y;
	t_kit	*kit;
	char	hex[3];
	char	cursor[128][32] = {0};
	int		processesAlive = 0;
	int		background;
	int		foreground;

	kit = (t_kit *)(node->content);
	i = -1;
	filler(kit, cursor, &processesAlive);
	while (++i < MEM_SIZE)
	{
		x = (i % 128);
		y = (i / 128);
		background = getBackground(cursor[x][y], kit->procs->arena[1][i]);
		foreground = getForeground(cursor[x][y], kit->procs->arena[1][i]);
		x = x + (13 * x) - (WIDTH / 2);
		y = y - (15 * y) + (HEIGHT / 2);
		rectangle(x, y, x + 13, y - 13, background);
		if (kit->procs->arena[1][i])
		{
			sprintf(hex, "%X", kit->procs->arena[0][i]);
			hex[1] = 0;
			renderBitmapString(x + 2.6, y - 11, hex, foreground);
		}
	}
}
