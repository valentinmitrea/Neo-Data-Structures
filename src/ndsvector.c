/**
 * NDS - Neo Data Structures
 * Copyright (C) 2017-2017 MiVal Software
 *
 * This file is part of Neo Data Structures.
 *
 * Neo Data Structures is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Neo Data Structures is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Neo Data Structures. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * NdsVector is a generic vector that offers features such as dynamic
 * allocation, adding/removing elements, finding elements, etc. which
 * are standard for an array data structure.
 *
 * @author      Valentin Gabriel Mitrea <mitrea.valentin@gmail.com>
 * @created     13 July 2017
 * @modified    18 July 2017
 */

#include <nds/ndsvector.h>

#include <stdlib.h>


struct NdsVectorPrivate
{
	void *elements;
	size_t sizeof_element;

	/* current size and capacity of the vector */
	size_t size;
	size_t capacity;
};


NdsVector* nds_vector_new(size_t sizeof_element)
{
	/* ideal starting capacity for a vector is 10 */
	return nds_vector_new_with_capacity(sizeof_element, 10);
}


NdsVector* nds_vector_new_with_capacity(size_t sizeof_element, size_t capacity)
{
	NdsVector *vector;

	/* sanity checks */
	if (sizeof_element == 0 || capacity == 0)
		return NULL;

	/* we allocate memory for the structure of the NdsVector */
	vector = (NdsVector*)malloc(sizeof(NdsVector));
	if (!vector)
		return NULL;

	/* we allocate memory for the private part of the NdsVector */
	vector->private = (NdsVectorPrivate*)malloc(sizeof(NdsVectorPrivate));
	if (!vector->private)
	{
		/* cleanup */
		free(vector);

		return NULL;
	}

	/* we allocate memory for the elements that will be stored in the NdsVector */
	vector->private->elements = (void*)malloc(capacity * sizeof_element);
	if (!vector->private->elements)
	{
		/* cleanup */
		free(vector->private);
		free(vector);

		return NULL;
	}

	/* various initializations */
	vector->private->size = 0;
	vector->private->capacity = capacity;

	return vector;
}


void nds_vector_destroy(NdsVector *vector)
{
	free(vector->private->elements);
	vector->private->elements = NULL;

	free(vector->private);
	vector->private = NULL;

	free(vector);
	vector = NULL;
}


int nds_vector_is_empty(NdsVector *vector)
{
	/* sanity checks */
	if (vector == NULL || vector->private == NULL || vector->private->elements == NULL)
		return -1;

	return vector->private->size == 0;
}


int nds_vector_size(NdsVector *vector)
{
	/* sanity checks */
	if (vector == NULL || vector->private == NULL || vector->private->elements == NULL)
		return -1;

	return vector->private->size;
}


int nds_vector_capacity(NdsVector *vector)
{
	/* sanity checks */
	if (vector == NULL || vector->private == NULL || vector->private->elements == NULL)
		return -1;

	return vector->private->capacity;
}

