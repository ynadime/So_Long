

#ifndef FT_ERRPRINTF_H
# define FT_ERRPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	printerr(const char *str, ...);
int	ft_errputchar(char c);
int	ft_errputstr(char *s);
int	ft_errputnbr(int n);
int	ft_errputunbr(unsigned int n);
int	ft_errhexa(unsigned long int nb, char format);

#endif
