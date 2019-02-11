/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iuser_tkn_chrmsk.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:03:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/13 12:11:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IUSER_TKN_CHRMSK_H
# define IUSER_TKN_CHRMSK_H

# define IUSER_MASK_COUNT		IUSER_WMASK_COUNT + IUSER_DMASK_COUNT
# define IUSER_TOKEN_MASK		IU_WMASK, IU_DMASK

# define IUSER_DMASK_COUNT		1
# define IU_DMASK	IU_DMASK_1
# define IU_DMASK_1	" \t"

# define IUSER_WMASK_COUNT		2
# define IU_WMASK	IU_WMASK_1, IU_WMASK_2
# define IU_WMASK_1	"&;<>|\n()"
# define IU_WMASK_2	"$'\\\"`"

# define IUSER_STARTING_WMASK	0
# define IUSER_STARTING_DMASK	IUSER_WMASK_COUNT

#endif
