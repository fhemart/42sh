/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:19:47 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 02:42:26 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_PRIVATE_H
# define FT_DICTIONARY_PRIVATE_H
# include "ft_dictionary.h"

t_word		*dictionary_get_newpos(t_word **first_word, \
					char *word, int (*cmp)(const char*, const char*));
int			dictionary_insert_word(t_word **newpos, t_word **first, \
											char *word);
int			insert_word(t_word **newpos, char *word);
int			insert_first_word(t_word **first, char *word);
#endif
