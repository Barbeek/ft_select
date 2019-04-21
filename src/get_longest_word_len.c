#include "../includes/ft_select.h"

int	get_longest_word_len(t_env *env)
{
	int	len;
	int	current_len;
	int	i;
	
	len = 0;
	i = 0;
	while (i < env->word_count)
	{
		current_len = ft_strlen(env->words[i]);
		if (current_len > len)
			len = current_len;
		i++;
	}
	return (len);
}
