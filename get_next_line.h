#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int     get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_gnldup(const char *s1, const char *srcfree);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnljoin(char const *s1, char const *s2);

#endif
