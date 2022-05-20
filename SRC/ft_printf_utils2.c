#include "push_swap.h"

int ft_print_upper_hexa(unsigned int nb)
{
    char    *hex;
    int cpt;
    
    cpt = 0;
    hex = "0123456789ABCDEF";
    if (nb >= 0 && nb < 16)
    {
        cpt += ft_putchar(hex[nb]);
    }
    else if (nb >= 16)
    {
        cpt += ft_print_upper_hexa(nb >> 4);
        cpt += ft_print_upper_hexa(nb & 0xf);
    }
    return (cpt);
}

int ft_print_addrs(long unsigned int nb)
{
    int cpt;
    char    *hex;

    cpt = 0;
    cpt += ft_putstr("0x");
    hex = "0123456789abcdef";
    if (nb >= 0 && nb < 16)
    {
        cpt += ft_putchar(hex[nb]);
    }
    else if (nb >= 16)
    {
        cpt += ft_print_lower_hexa(nb >> 4);
        cpt += ft_print_lower_hexa(nb & 0xf);
    }
    return (cpt);
    return (cpt);
}