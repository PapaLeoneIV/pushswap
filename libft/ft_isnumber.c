#include "libft.h"

int ft_isnumber(char *str)
{
    int i;

    i = 0;
    while(str && str[i] != '\0')
    {
        if(str[i] == 45 || str[i] == 43)
            i++;
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}