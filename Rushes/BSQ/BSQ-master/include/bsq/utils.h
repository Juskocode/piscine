/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:27:46 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:49 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "error.h"

# ifndef SUCCESS
#  define SUCCESS (0)
# endif

# ifndef FAILURE
#  define FAILURE (1)
# endif

# define UNUSED(x) ((void)(x))
# define MIN(a, b) ((a) + ((b) - (a)) * ((a) > (b)))

#endif
