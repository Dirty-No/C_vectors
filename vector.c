/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:28:09 by smaccary          #+#    #+#             */
/*   Updated: 2021/03/27 15:51:23 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void
	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (char)c;
		i++;
	}
	return (b);
}

void
	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void
	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	buff = malloc(count * size);
	return (ft_memset(buff, 0, count * size));
}

t_vector
	*vector_resize(t_vector *vector, size_t new_size)
{
	char	*new;
	size_t	ncpy;

	new = ft_calloc(new_size, vector->obj_size);
	if (vector->len > new_size)
	{
		ncpy = new_size;
		vector->available = 0;
		vector->len = ncpy;
		vector->size = new_size;
	}
	else
	{
		ncpy = vector->len;
		vector->available += new_size - vector->size;
		vector->size = new_size;
	}
	ft_memcpy(new, vector->bytes, ncpy * vector->obj_size);
	free(vector->bytes);
	vector->bytes = new;
	return (vector);
}

t_vector
	*vector_append(t_vector *vector, void *add, size_t count)
{
	if (count > vector->available)
		vector_resize(vector, (vector->size + count) * 2);
	ft_memcpy(vector->bytes + vector->len * vector->obj_size, add,
				count * vector->obj_size);
	vector->len += count;
	vector->available -= count;
	return (vector);
}

t_vector
	*new_vector(size_t count, size_t size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	vector->bytes = ft_calloc(count, size);
	vector->size = count;
	vector->available = count;
	vector->len = 0;
	vector->obj_size = size;
	return (vector);
}

void
	free_vector(t_vector *vector)
{
	free(vector->bytes);
	free(vector);
}

#define STR "fuck\n"

int main(void)
{
	t_vector *v;

	v = new_vector(strlen(STR),  1);
	for (size_t i = 0; i < 10; i++)
		vector_append(v, STR, strlen(STR));
	write(1, v->bytes, v->len);
//	free_vector(v);
	return (0);
}