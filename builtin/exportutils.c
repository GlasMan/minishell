/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 01:05:57 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	addexport(char *commandlist)
{
	char	*buff;
	char	*temp;

	buff = merge(g_shell->export);
	dbfree(g_shell->export);
	buff = ft_strjoin(buff, " ");
	if (equalcheck(commandlist) == 1)
	{
		temp = addquote(commandlist, 0);
		buff = ft_strjoin(buff, temp);
		free(temp);
	}
	else
		buff = ft_strjoin(buff, commandlist);
	g_shell->export = ft_split(buff, ' ');
	free(buff);
}

void	addenv(char *commandlist)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_shell->env[i])
		i++;
	temp = g_shell->env[i - 1];
	g_shell->env[i] = temp;
	g_shell->env[i - 1] = ft_strdup(commandlist);
	g_shell->env[i + 1] = NULL;
}

void	envupdate(char *commandlist)
{
	int	i;

	i = g_shell->envflag;
	free(g_shell->env[i]);
	g_shell->env[i] = ft_strdup(commandlist);
}

int	exportupdate(char *commandlist)
{
	int	i;

	i = g_shell->exportflag;
	if (g_shell->exportflag != 0)
	{
		if (equalcheck(commandlist))
		{
			free(g_shell->export[i]);
			g_shell->export[i] = addquote(commandlist, 0);
		}
		return (1);
	}
	return (0);
}
