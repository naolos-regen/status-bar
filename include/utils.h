#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// file utils
char	*get_next_line(int fd);

// file recursive utils
char	*get_next_line_recursive(int fd);


// iterative 
int	ft_strcmp(const char *s1, const char *s2);
size_t 	ft_strlen(const char *s);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	*ft_mempcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);


// recursive
int	ft_strcmp_recursive(const char *s1, const char *s2);
size_t	ft_strlen_recursive(const char *s);
char	*ft_strcat_recursive(char *dest, char *src);
char 	*ft_strcpy_recursive(char *dest, char *src);
void	*ft_mempcpy_recursive(void *dest, const void *src, size_t n);
void	*ft_memset_recursive(void *s, int c, size_t n);
char	*ft_strchr_recursive(const char *s, int c);


#endif//UTILS_H

