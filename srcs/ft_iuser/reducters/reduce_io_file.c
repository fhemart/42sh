/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_io_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/11 16:53:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void	*reduce_io_file(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_iocontent	*io_file;
	t_exptoken	*filename;
	t_token		*type;
	char		*str;

	filename = ft_zebu_get_curr_tok(tfactory);
	type = ft_zebu_get_curr_tok(tfactory);
	str = filename->reduced;
	token_del(&type);
	token_del((t_token**)&filename);
	if (!(io_file = new_iocontent(str, expr->validstate)))
		tfactory->main_status = TF_STATUS_ERROR;
	return (io_file);
}
