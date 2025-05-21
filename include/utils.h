#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// iterative 
int	ft_strcmp(const char *s1, const char *s2);
size_t 	ft_strlen(const char *s);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	*ft_mempcpy(void *dest, const void *src, size_t n);


// recursive
int	ft_strcmp_recursive(const char *s1, const char *s2);
size_t	ft_strlen_recursive(const char *s);
char	*ft_strcat_recursive(char *dest, char *src);
char 	*ft_strcpy_recursive(char *dest, char *src);
void	*ft_mempcpy_recursive(void *dest, const void *src, size_t n);



#endif//UTILS_H

