/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:18:50 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/03 18:06:43 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_wordcount(const char *s)
{
    int	count;
    int	i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
            ++i;
        if (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
        {
            ++count;
            while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
                ++i;
        }
    }
    return (count);
}
