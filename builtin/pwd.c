/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:31:24 by agunes            #+#    #+#             */
/*   Updated: 2022/08/14 02:29:28 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	int		i;

	i = 0;
	while (g_shell->env[i++])
	{
		if (!ft_strncmp(g_shell->env[i], "PWD", 3) && \
		g_shell->env[i][3] == '\0')
			break ;
	}
	printf("%s\n", g_shell->env[i]);
	return (1);
}
