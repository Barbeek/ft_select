#include "libft.h"

char	**make_tab(char **values)
{
	char	**tab;
	int	i;

	i = -1;
	while (values[++i]);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab[i] = NULL;
	i = -1;
	while (values[++i])
		tab[i] = ft_strdup(values[i]);
	return (tab);
}
