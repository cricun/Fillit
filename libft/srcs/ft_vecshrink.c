#include "libft.h"

void    ft_vecshrink(t_vector *vec)
{
    char    *tmp;

    if (!vec)
        return ;
    if (!(tmp = (char*)malloc(vec->len + 1)))
        return ;
    ft_memmove(tmp, vec->arr, vec->len);
    free(vec->arr);
    vec->arr = tmp;
    *(vec->arr + vec->len + 1) = 0;
}

