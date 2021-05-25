/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:31:29 by vbachele          #+#    #+#             */
/*   Updated: 2021/05/25 12:25:54 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int gnlcheck(char *line, char *gnline)
{
	if (!line || !gnline)
		return (-1);
	return (1);
}

int		gnl_find(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int			gnl_return(char **line, char **gnline)
{
	int		ret;

	ret = 0;
	if (*gnline)
		*line = *gnline;
	else
	{
		*line = malloc(sizeof(char) * 1);
		if (*line == NULL)
			return (-1);
		*line[0] = '\0';
	}
	*gnline = NULL;
	return (ret);
}

int     get_next_line(int fd, char **line) // **line = on doit remplir le **line grace au fd qu'on nous envoie.
{
        static char		*gnline;
		char 			buffer[BUFFER_SIZE +1];
		int				n;
		int				flag;

		//if ((read(fd, buffer, 0) < 0) || fd < 0 || !line || BUFFER_SIZE < 1)
		//	return (-1);
		while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[n] = '\0';
			if (!(gnline = ft_gnljoin(gnline, buffer)))
				return (-1);
			flag = gnl_find(gnline);
			if (flag != -1)
				break ;
		}
		flag = gnl_find(gnline); // je stock le nombre de caractere present jusqu'au /n
		if (flag != -1) // si on a pas rencontre d'erreurs en cherchant le /n
		{
			*line = ft_substr(gnline, 0, flag); // on copie la chaine de caractere gnline dans *line en prenant la valeur de gnline et la longueur trouve dans flag
			gnline = ft_gnldup(&gnline[flag + 1], gnline); //On envoie gnline dans gnl_dup pour pouvoir free sa chaine de caractere passe et ne malloc + cree que la ligne quon souhaite
			return (gnlcheck(line, gnline));
		}
		return (gnl_return(line, &gnline));
}
