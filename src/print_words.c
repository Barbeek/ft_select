#include "../includes/ft_select.h"

void		ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t			i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}

void		print_hwords(t_env *env)
{
	int	i;
	int	print_space;
	
	unsetup_term(0);
	i = 0;
	print_space = 0;
	while (env->words[i])
	{
		if (env->h_word[i] == 1)
		{
			if (print_space)
				ft_putchar(' ');
			ft_putstr(env->words[i]);
			print_space = 1;
		}
		i++;
	}
	exit (0);
}

static void	turn_on_special_text(t_env *env, int current)
{
	if (env->h_word[current] == 1)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	if (env->current_word == current)
		ft_putstr_fd(tgetstr("us", NULL), 2);
}

static void	turn_off_special_text(t_env *env, int current)
{
	if (env->current_word == current)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
	if (env->h_word[current] == 1)
		ft_putstr_fd(tgetstr("se", NULL), 2);
}

void		print_words(t_env *env)
{
	int	row;
	int	column;
	int	current;

	row = 0;
	while (row < env->height && row < env->word_count)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (env->height * column) + row)) < env->word_count)
		{
			turn_on_special_text(env, current);
			ft_putstr_fd(env->words[current], 2);
			turn_off_special_text(env, current);
			ft_putcharn_fd(' ', env->single_col_width
					- ft_strlen(env->words[current]), 2);
			column++;
		}
		row++;
	}
}
