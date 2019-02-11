/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:28:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/26 14:16:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_H
# define FT_DICTIONARY_H
# include "libft.h"

# define DIC_DEBUG	0

typedef struct s_word	t_word;
struct				s_word
{
	t_word			*next;
	size_t			len;
	char			*word;
};

typedef struct s_dict_result	t_dict_result;
struct				s_dict_result
{
	t_word			*result;
	int				count;
	int				checked;
};

typedef struct s_dictionary	t_dictionary;
struct				s_dictionary
{
	t_word			*indexes[128];
	t_dict_result	*result;
};

int					ft_dictionary_destroy_result(t_dict_result **result);
int					ft_dictionary_destroy(t_dictionary **dictionary);
int					ft_dictionary_new(t_dictionary **dictionary);
int					ft_dictionary_addword(char *detail, char *word, \
											t_dictionary *dictionary);
int					ft_dictionary_addword_ni(char *detail, char *word, \
											t_dictionary *dictionary);
int					ft_dictionary_get(t_dictionary *dictionary, \
										char *tosearch, size_t len);
void				ft_dictionary_dbug_printfd(t_dictionary *dictionary);
void				ft_dictionary_dbug_print(t_dictionary *dictionary);
int					dictionary_get_index(char c);
t_word				*dictionary_new_word(char *word);
t_dict_result		*dictionary_new_result(void);
#endif
