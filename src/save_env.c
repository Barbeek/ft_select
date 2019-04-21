#include "../includes/ft_select.h"

t_env	*save_env(t_env *new_env)
{
	static t_env	*stored_env = NULL;
	
	if (new_env)
		stored_env = new_env;
	return (stored_env);
}
