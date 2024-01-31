/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:29:22 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:29:24 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq/error.h"
#include "bsq/types.h"

inline unsigned int	bsq_exit(char *msg, int size)
{
	size = (signed)write(1, msg, (size_t)size);
	UNUSED(size);
	exit(1);
	return (0);
}
