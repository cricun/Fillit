#include "libft.h"

void    ft_vecdel(t_vector *vec, size_t start, size_t end)
{
    char    *tmp;

    if (!vec || end < start || start > vec->len || end > vec->len
        || !(tmp = (char *)malloc(vec->len - (end - start))))
        return ;
    ft_memmove(tmp, vec->arr, start - 1);
    ft_memmove(tmp + start, vec->arr + end, vec->len - end);
    *(tmp + 1) = 0;
    free(vec->arr);
    vec->arr = tmp;
    vec->len = vec->len - (end - start + 1);
    vec->max = vec->len;
}
