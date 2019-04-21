#include "../includes/ft_select.h"

static void	up_or_down(t_env *env, unsigned long key)
{
	if (key == KEY_DOWN)
	{
		if (env->words[env->current_word + 1] != NULL)
			env->current_word++;
		else
			env->current_word = 0;
	}
	else
	{
		if (env->current_word != 0)
			env->current_word--;
		else
			env->current_word = env->word_count - 1;
	}
}

static void	space(t_env *env)
{
	if (env->h_word[env->current_word] == 0)
		env->h_word[env->current_word] = 1;
	else if (env->h_word[env->current_word] == 1)
		env->h_word[env->current_word] = 0;
	if (env->words[env->current_word + 1] != NULL)
		env->current_word++;
	else
		env->current_word = 0;
}

static void	left_or_right(unsigned long key, t_env *env)
{
	int	ncurrent_word;
	int	position_from_top;

	ncurrent_word = 0;
	position_from_top = env->current_word % env->height;
	if (key == KEY_RIGHT)
	{
		ncurrent_word = env->current_word + env->height;
		if (ncurrent_word >= env->word_count)
			env->current_word = position_from_top;
		else
			env->current_word = ncurrent_word;

	}
	else if (key == KEY_LEFT)
	{
		ncurrent_word = env->current_word - env->height;
		if (ncurrent_word < 0)
			return ;
		else
			env->current_word = ncurrent_word;
	}

}

void	input_loop(void)
{
	unsigned long	key;
	t_env		*env;
	int		refresh;

	env = save_env(NULL);
	refresh = 0;
	while (key = 0, (read(0, &key, 6)) != 0)
	{
		refresh = 1;
		if (key == KEY_LEFT || key == KEY_RIGHT)
			left_or_right(key, env);
		else if (key == KEY_UP || key == KEY_DOWN)
			up_or_down(env, key);
		else if (key == KEY_ESCAPE)
			exit_term(0);
		else if (key == KEY_BACKSPACE || key == KEY_DELETE)
			env = remove_word(env);
		else if (key == KEY_ENTER)
			print_hwords(env);
		else if (key == KEY_SPACE)
			space(env);
		else
			refresh = 0;
		if (refresh)
			refresh_screen(0);
	}
}
