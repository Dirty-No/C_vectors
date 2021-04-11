/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:13:40 by smaccary          #+#    #+#             */
/*   Updated: 2021/04/11 18:03:04 by smaccary         ###   ########.fr       */
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

/*
void
	vect_puts(void **ptr)
{
	char *str;

	str = *ptr;
	puts(str);
}

int
	main(int argc, char **argv)
{
	t_stackgroup 	*group;
	t_vector		*output;
	char			*tmp;
	int				temp;

	output = new_vector(256, sizeof(char *));
	for (size_t i = 0; i < 10; i++)
	{
		tmp = malloc(10);
		snprintf(tmp, 9, "fuck %zu", i);
		vector_append(output, &tmp, 1);
	}
	vector_iter(output, vect_puts);
}
*/