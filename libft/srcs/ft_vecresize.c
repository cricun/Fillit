#include "libft.h"

void    ft_vecresize(t_vector *vec)
{
    char *tmp;

    if (!vec || !(tmp = (char*)malloc(vec->max * 2 + 1)))
        return ;
    ft_memmove(tmp, vec->arr, vec->len);
    *(tmp + vec->len + 1) = 0;
    free(vec->arr);
    vec->arr = tmp;
    vec->max *= 2;
}