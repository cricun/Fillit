#include "libft.h"

t_vector *t_vecnew(void *arr, size_t len)
{
    t_vector *tmp;

    if (!arr || !len || !(tmp = (t_vector*)malloc(sizeof(t_vector))))
    {
        tmp->arr = NULL;
        tmp->len = 0;
        tmp->max = 0;
    }
    else if ((tmp->arr = (char*)malloc(len + 1)))
    {
        ft_memmove(tmp->arr, arr, len);
        *(tmp->arr + len + 1) = 0;
        tmp->len = len;
        tmp->max = len;
    }
    return (tmp);
}