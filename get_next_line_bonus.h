/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:00:04 by sgmira            #+#    #+#             */
/*   Updated: 2021/11/29 14:41:16 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define  GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin_bonus(char	*s1, char	*s2);
char	*ft_strchr_bonus(const char *str, int c);
size_t	ft_strlen_bonus(const char *str);
char	*get_next_line(int fd);

#endif