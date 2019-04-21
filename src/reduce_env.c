#include "../includes/ft_select.h"

static char	**reduce_env(int size, t_env *env)
{
	int	i;
	char	**new_words;

	i = 0;
	new_words = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	new_words[size] = NULL;
	while (env->words[i] && i < size)
	{
		new_words[i] = env->words[i];
		env->words[i] = NULL;
		i++;
	}
	env->words = NULL;
	env->word_count = i;
	if (env->word_count == env->current_word)
		env->current_word--;
	if (i == 0)
		exit_term(0);
	return (new_words);
}

t_env		*remove_word(t_env *env)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	if (env->h_word[env->current_word] != 1)
		return (env);
	else
	{
		env->words[env->current_word] = NULL;
		env->h_word[env->current_word] = 0;
		i = env->current_word;
		size = i + 1;
		while (i + 1 < env->word_count)
		{
			env->words[i] = env->words[i + 1];
			env->h_word[i] = env->h_word[i + 1];
			env->words[i + 1] = NULL;
			i++;
			size++;
		}
	}
	env->words = reduce_env(size - 1, env);
	return (env);
}
