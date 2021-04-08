/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:13:40 by smaccary          #+#    #+#             */
/*   Updated: 2021/04/08 14:14:54 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.h"

int main(void)
{
	t_vector *v;

	v = new_vector(strlen("hello "),  1);
	for (size_t i = 0; i < 10; i++)
		vector_append(v, "hello ", strlen("hello "));
	write(1, v->bytes, v->len);
	free_vector(v);
	return (0);
}
