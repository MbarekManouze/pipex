/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:25:33 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/19 10:18:48 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void	ft_path_command(char **env, char **av, t_pipe *cmd, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
		{
			cmd->path_cmd = ft_strchr(env[i], '/');
			j++;
			break ;
		}
		i++;
	}
	if (j == 0)
		ft_error("PATH has been unseted %d");
	cmd->take = ft_split(cmd->path_cmd, ':');
	if (c == 0)
		cmd->commands = ft_split(av[2], ' ');
	if (c == 1)
		cmd->commands = ft_split(av[3], ' ');
}

void	check_commands(t_pipe *cmd, char **av, char **env, int k)
{
	int		i;
	char	*acs;
	int		j;

	i = 0;
	if (!access(*cmd->commands, F_OK & X_OK))
		execve(*cmd->commands, cmd->commands, env);
	while (cmd->take[i])
	{
		acs = ft_strjoin(cmd->take[i++], cmd->commands[0]);
		j = access(acs, F_OK & X_OK);
		if (j == 0)
			execve(acs, cmd->commands, env);
		free(acs);
	}
	if (j == -1 && k == 0)
	{
		ft_error(av[2]);
		exit(1);
	}
	if (j == -1 && k == 1)
	{
		ft_error(av[3]);
		exit(1);
	}
}

void	start(int file, int file1, char **av, char **env)
{
	t_pipe	cmd;

	pipe(cmd.fd);
	cmd.id = fork();
	if (cmd.id == 0)
	{
		child_cl(&cmd, file);
		ft_path_command(env, av, &cmd, 0);
		check_commands(&cmd, av, env, 0);
	}
	cmd.id2 = fork();
	if (cmd.id2 == 0)
	{
		child_cl2(&cmd, file1);
		ft_path_command(env, av, &cmd, 1);
		check_commands(&cmd, av, env, 1);
	}
	close(cmd.fd[0]);
	close(cmd.fd[1]);
	waitpid(cmd.id, 0, 0);
	waitpid(cmd.id2, 0, 0);
}

int	main(int ac, char **av, char **env)
{
	int	file;
	int	file1;

	if (ac != 5)
	{
		write(2, "check your arguments\n", 21);
		exit(1);
	}
	file = open (av[1], O_RDONLY);
	if (file == -1)
		ft_error(av[1]);
	file1 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file1 == -1)
		ft_error(av[4]);
	start(file, file1, av, env);
	close(file);
	close(file1);
	return (0);
}
