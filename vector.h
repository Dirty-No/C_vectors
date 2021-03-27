/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:24:23 by smaccary          #+#    #+#             */
/*   Updated: 2021/03/27 15:49:22 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"

typedef struct s_vector
{
    void    *bytes;
    size_t  len;
    size_t  available;
    size_t  size;
    size_t  obj_size;
}              t_vector;

#endif