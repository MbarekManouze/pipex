/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:23:00 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/18 16:39:32 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct pipex
{
	int		fd[2];
	int		id;
	int		id2;
	int		file1;
	int		file2;
	char	**commands;
	char	*path_cmd;
	char	**take;
}	t_pipe;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const	*s1, char const	*s2);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	len);
size_t	ft_strlen(const	char	*s);
void	ft_error(char *str);
void	child_cl(t_pipe *cmd, int file);
void	child_cl2(t_pipe *cmd, int file1);

#endif
