/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:03:52 by kroselin          #+#    #+#             */
/*   Updated: 2020/05/16 19:13:30 by ginger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen((char *)s);
	str = ft_memalloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f((unsigned int)i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
