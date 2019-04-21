/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:37:06 by pespalie          #+#    #+#             */
/*   Updated: 2018/10/10 22:23:08 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdio.h>

# define KEY_ESCAPE 0x1B
# define KEY_BACKSPACE 0x7F
# define  KEY_DELETE 0x7E335B1B
# define KEY_ENTER 0xA
# define KEY_SPACE 0x20
# define KEY_UP 0x415B1B
# define KEY_RIGHT 0x435B1B
# define KEY_DOWN 0x425B1B
# define KEY_LEFT 0x445B1B

typedef struct		s_env
{
	int				width;
	int				height;
	char			**words;
	int				word_count;
	int				*h_word;
	int				current_word;
	int				single_col_width;
	struct termios	term;
}			t_env;

void	exit_term(int signum);
int		get_longest_word_len(t_env *env);
void	input_loop(void);
int		main(int argc, char **argv);
void	print_hwords(t_env *env);
void	print_words(t_env *env);
void	refresh_screen(int signum);
t_env	*remove_word(t_env *env);
void	s_window(t_env *env);
t_env	*save_env(t_env *new_env);
void	unsetup_term(int signum);
void	wash_screen(t_env *env);
#endif
