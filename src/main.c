/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:35:27 by pespalie          #+#    #+#             */
/*   Updated: 2018/10/10 22:25:28 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_select.h"

static void	signal_handler(void(*restart)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart);
	signal(SIGTSTP, unsetup_term);
	signal(SIGINT, exit_term);
	signal(SIGHUP, exit_term);
	signal(SIGTERM, exit_term);
	signal(SIGSEGV, exit_term);
	signal(SIGQUIT, exit_term);
	signal(SIGFPE, exit_term);
	signal(SIGKILL, exit_term);
	signal(SIGALRM, exit_term);
	signal(SIGABRT, exit_term);
	signal(SIGUSR1, exit_term);
	signal(SIGUSR2, exit_term);
}

static void	setup_terminal(t_env *env)
{
	char	*term_name;
	char	buf[1024];

	if (!(term_name = getenv("TERM")))
	{
		ft_putstr("Error getting TERM name");
		exit(1);
	}
	if (tcgetattr(0, &env->term) == -1)
	{
		ft_putstr("Error: not a terminal");
		exit (1);
	}
	env->term.c_lflag &= ~(ICANON | ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
	{
		ft_putstr("Error: termios");
		exit (1);
	}
	if (tgetent(buf, getenv("TERM")) <= 0)
	{
		ft_putstr("Error: could not access the termcaps database");
		exit (1);
	}
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

static void	setup_env(char **argv, int argc, t_env *env)
{
	env->words = argv + 1;
	env->word_count = argc - 1;
	env->h_word = malloc((argc - 1) * sizeof(int));
	ft_bzero(env->h_word, (argc - 1) * sizeof(int));
	env->current_word = 0;
	env->single_col_width = get_longest_word_len(env) + 2;
	s_window(env);
	setup_terminal(env);
}

static void	restart(int signum)
{
	t_env	*env;

	(void)signum;
	env = save_env(NULL);
	setup_terminal(env);
	signal_handler(&restart);
	refresh_screen(0);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
	{
		ft_putstr("usage: ft_select [parameter 1] [paramter 2] ...");
		return (1);
	}
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (1);
	setup_env(argv, argc, env);
	signal_handler(&restart);
	save_env(env);
	refresh_screen(0);
	input_loop();
	return (0);
}
