/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/15 01:05:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "unistd.h"

void	ft_exit(void);
int		ft_cd(char *command);
int		ft_env(void);
int		ft_builtinsearch(char *arr);
int		ft_echo(char **command);
int		ft_pwd(void);
int		export(void);
int		equalcheck(char *commandlist);
char	*ft_getenv(char *arr);
int		exportsearch(char *arr);
int		envsearch(char *arr);
int		equalcheck(char *commandlist);
char	*addquote(char *commandlist, int status);
void	envupdate(char *commandlist);
void	addenv(char *commandlist);
void	addexport(char *commandlist);
char	**sortexport(void);
int		exportupdate(char *commandlist);
int		findfirstindex(char *arr, char c);
int		unset(void);
void	pwdupdate(char *new, char *old);
void	notset(int status);
void	envpwdupdate(char *new, char *old);
void	exportpwdupdate(char *new, char *old);
int		cdcheck(char *command);
#endif
