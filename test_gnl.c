/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:26:32 by vbachele          #+#    #+#             */
/*   Updated: 2021/05/25 17:00:25y vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int ft_gnlcheck()

int ft_gnl_find(char *gnline)
{
	int i;

	i = 0;
	while (gnline[i])
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
	int				flag;
	
	n = read(fd, buffer, BUFFER_SIZE); // On lit le fichier et on stock le retour dans n
	if (n > 0)
	{
		buffer[n] = '\0'; // met le caractere NULL a la fin de la chaine de caractere
		//printf("%s\n", buffer);
		//printf("%d\n", n);
		gnline = ft_gnljoin(gnline, buffer); 
		//printf("%s : j'affiche ici le resultat de ma variable static\n", gnline);	
		flag = ft_gnl_find(buffer); // On trouve la taille du fichier jusqu'au \n
		//printf("%d\n", flag);		
		*line = ft_substr(gnline, 0, flag);
		gnline = ft_gnldup(gnline + 1, gnline);
		//printf("%s\n", gnline)
		return (1);
	}
	return(0);
}