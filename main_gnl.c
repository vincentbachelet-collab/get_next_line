/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:31:37 by vbachele          #+#    #+#             */
/*   Updated: 2021/05/26 15:38:29 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     get_next_line(int fd, char **line);


int	main(int argc, char **argv)
{
	(void) argc;
	static  char	*line;
	int		fd;
	int		flag;

	fd = open(argv[1], O_RDONLY);
	flag = 1;
	while (flag)
	{
		flag = get_next_line(fd, &line);
		printf("Return value: %s\nReturn value: %d\n", line, flag);
	   	//free(line);
	}
	get_next_line(fd, &line);
	return (0);
}
