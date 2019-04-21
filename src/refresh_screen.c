#include "../includes/ft_select.h"

void		wash_screen(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->height)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		i++;
	}
}

static int	screen_fit(t_env *env)
{
	int		n_columns;

	n_columns = env->word_count / env->height + 1;
	return ((n_columns * env->single_col_width) < env->width);
}

void		s_window(t_env *env)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	env->width = window.ws_col;
	env->height = window.ws_row;
}

void		refresh_screen(int signum)
{
	t_env 		*env;
	
	(void)signum;
	env = save_env(NULL);
	s_window(env);
	wash_screen(env);
	if (screen_fit(env))
		print_words(env);
	else
		ft_putstr_fd("not enough room", 2);
}
