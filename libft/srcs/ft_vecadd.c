#include "libft.h"

void    ft_vecstrconcat(t_vector *vec, char *str)
{
    size_t i;

    if (!vec || !str)
        return ;
    i = ft_strlen(str);
    if (vec->len + i > vec->max)
        ft_vecresize(vec);
    ft_memmove(vec->arr + vec->len, str, i);
}