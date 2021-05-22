/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:06:22 by snarain           #+#    #+#             */
/*   Updated: 2021/05/22 00:41:09 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define  BUFFER_SIZE 4096

static char     stock_gnl()
{
        return ();
}

int     get_next_line(int fd, char **line) // **line = on doit remplir le **line grace au fd qu'on nous envoie.
{
        char            *ret;
        char    buffer[BUFFER_SIZE];

        *line = malloc(sizeof(char) * BUFFER_SIZE);
        if (!*line)
                return (NULL);
        while (1)
        {
                buffer = read(fd,buffer,BUFFER_SIZE);
                if (buffer > BUFFER_SIZE)
                        return (0);
                return (1);
        }
        return (-1);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		flag;

	fd = open();
	flag = 1;
	while (flag)
	{
		flag = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
