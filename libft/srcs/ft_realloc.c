/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 14:41:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 14:42:47 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *pt, int sizeold, int new_size)
{
	void	*to_do;

	if (sizeold >= new_size)
		return (pt);
	to_do = ft_memalloc(new_size);
	ft_memmove(to_do, pt, sizeold);
	free(pt);
	return (to_do);
}
