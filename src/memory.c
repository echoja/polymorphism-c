#include <stdlib.h>
#include "polymorphism.h"

t_bool	m(void *target, size_t size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == 0)
		return (FALSE);
	return (TRUE);
}
