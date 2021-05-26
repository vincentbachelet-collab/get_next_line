/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:15:12 by vbachele          #+#    #+#             */
/*   Updated: 2021/05/26 16:57:53 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_gnlcheck(char *line, char *gnline)
{
	if (!line || !gnline)
		return (-1);
	return(1);
}

int ft_gnl_find(char *gnline)
{
	int i;

	i = 0;
	while (gnline && gnline[i])
	{
		if (gnline[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}

int     get_next_line(int fd, char **line)
{
	static char 	*gnline = ""; 
	char 			buffer[BUFFER_SIZE + 1]; 
	int 			n; 
	static int		flag;

	n = read(fd, buffer, BUFFER_SIZE); // On lit le fichier et on stock le retour dans n
	if (!line || fd < 0 || BUFFER_SIZE < 1 || n < 0)
		return (-1);
	if (flag != -1)
	{
		buffer[n] = '\0'; // met le caractere NULL a la fin de la chaine de caractere
		gnline = ft_gnljoin(gnline, buffer); // Attribue la valeur du fichier restant dans gnline
		flag = ft_gnl_find(gnline); // On trouve la taille de la ligne jusqu'au \n
		*line = ft_substr(gnline, 0, flag); //
		gnline = ft_gnldup(&gnline[flag +1], gnline);
		free(gnline);
		return (ft_gnlcheck(*line, gnline));
	}
	return(0);
}