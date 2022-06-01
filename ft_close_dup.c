/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:09:38 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/18 16:10:53 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_cl(t_pipe *cmd, int file)
{
	close(cmd->fd[0]);
	dup2(file, 0);
	dup2(cmd->fd[1], 1);
}

void	child_cl2(t_pipe *cmd, int file1)
{
	close(cmd->fd[1]);
	dup2(cmd->fd[0], 0);
	dup2(file1, 1);
}
