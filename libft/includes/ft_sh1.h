/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 23:42:45 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 23:16:40 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

typedef struct		s_env
{
	char			**path;
	char			*home;
	char			*oldpwd;
}					t_env;
int					open_dir(const char *path, int args, t_env *env);
char				**put_env(char **env);
char				**ft_setenv(char **env, char **str);
char				**ft_unsetenv(char **env, char **str);
char				**ft_exec_cmd(char *line, char **env,
						char **path, t_env *save);
char				**ft_multi_exec(char *line, char **env,
						char **path, t_env *save);
int					ft_builtins(char **line, char ***env,
						char **path, t_env *save);
int					ft_binary(char **path, char **av, char **env);
void				path_binary(char **path, char **av, char **env);
int					verif_path(char **env);
t_env				*copy_env(char **env);
int					args(char **cmd);

#endif
