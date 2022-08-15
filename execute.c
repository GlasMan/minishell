/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 17:59:40 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**path(char **path, char *command)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (!ft_strncmp(g_shell->env[i], "PATH", 4) && \
		g_shell->env[i][4] == '=')
			break ;
	}
	path = ft_split(g_shell->env[i], ':');
	free(path[0]);
	path[0] = ft_strdup((ft_strchr(path[0], '=') + 1));
	i = -1;
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], \
		command);
	}
	return (path);
}

int	exec(char **commandlist, char *path)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		execve(path, commandlist, g_shell->env);
		kill(getpid(), SIGTERM);
	}
	else
		wait(NULL);
	return (0);
}

void	searchfor(char **path, char **commandlist, char *command)
{
	int	i;

	i = -1;
	g_shell->exeflag = 0;
	while (path[++i])
	{
		if (access(path[i], F_OK) == 0)
		{
			exec(commandlist, path[i]);
			g_shell->exeflag = 1;
		}
		else if (ft_strchr(command, '/'))
		{
			if (access(command, X_OK) == 0)
				exec(commandlist, command);
			else
				g_shell->exeflag = -1;
		}
	}
}

void	checkerror(char *command)
{
	if (g_shell->exeflag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(g_shell->path[0], '/') + 1));
	}
	if (g_shell->exeflag == -1)
		printf("minishell: %s: %s\n", command, strerror(errno));
}

void	runcommand(char *command)
{
	g_shell->builtflag = 0;
	if (g_shell->op_flag == 1)
		op_handle(g_shell->command);
	else if (g_shell->pipe_flag > 0)
		run_pipes();
	else
	{
		g_shell->path = path(g_shell->path, command);
		if (builtinsearch(command) == 0)
		{
			searchfor(g_shell->path, g_shell->commandlist, command);
			checkerror(command);
		}
	}
}