#include "libft.h"

void    ft_vecfree(t_vector **vec)
{
    free((*vec)->arr);
    free(*vec);
    *vec = NULL;
}
