/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:57:53 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/02 16:41:30 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_substr(char	*s, char *tofree, unsigned int start, size_t len);

void	boosted_free(char **s);

void	freeall(char **s1, char **s2);

char	*get_next_line(int fd);

ssize_t	ft_strchr(const char *s, int c, int size_read);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char const *s2);
#endif
