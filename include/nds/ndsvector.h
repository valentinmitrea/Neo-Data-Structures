/**
 * NDS - Neo Data Structures
 * Copyright (C) 2017-2018 MiVal Software
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
 * @modified    23 February 2018
 */

#ifndef __NDS_VECTOR_H__
#define __NDS_VECTOR_H__

#include <nds/ndsutils.h>

#include <stddef.h>


struct NdsVector
{
	struct NdsVectorPrivate *private;
};

typedef struct NdsVector NdsVector;


/**
 * Function that creates a new NdsVector with an initial capacity of 10.
 *
 * NOTE: Do not forget to call nds_vector_destroy() before exiting the scope
 * of the current NdsVector in order to avoid memory leaks!
 *
 * @param     sizeof_element    size of one element in the vector
 *
 * @return    valid pointer    successful initialization
 *                     NULL    failure during initialization
 *
 * @complexity    linear
 */
NdsVector* nds_vector_new(size_t sizeof_element);


/**
 * Function that creates a new NdsVector with a given initial capacity.
 *
 * NOTE: Do not forget to call nds_vector_destroy() before exiting the scope
 * of the current NdsVector in order to avoid memory leaks!
 *
 * @param     sizeof_element    size of one element in the vector
 * @param           capacity    the initial capacity of the vector
 *
 * @return    valid pointer    successful initialization
 *                     NULL    failure during initialization
 *
 * @complexity    linear
 */
NdsVector* nds_vector_new_with_capacity(size_t sizeof_element, size_t capacity);


/**
 * Function that frees the memory occupied by the NdsVector.
 *
 * @param    vector    pointer to a NdsVector structure
 *
 * @complexity    linear
 */
void nds_vector_destroy(NdsVector *vector);


/**
 * Function that checks if the given NdsVector is empty or not.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @return    1    the NdsVector is empty
 *            0    the NdsVector is not empty
 *           -1    the NdsVector is invalid
 *
 * @complexity    constant
 */
int nds_vector_is_empty(NdsVector *vector);


/**
 * Function that returns the current size of the NdsVector.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @return    size    the size of the NdsVector
 *              -1    the NdsVector is invalid
 *
 * @complexity    constant
 */
int nds_vector_size(NdsVector *vector);


/**
 * Function that resizes the NdsVector container so that it contains size
 * elements.
 *
 * @param     vector    pointer to a NdsVector structure
 * @param       size    new size of the NdsVector
 *
 * @return                     NDS_OK    resize was successful
 *            NDS_INVALID_PARAM_ERROR    invalid parameters for the function
 *
 * @complexity    linear
 */
NdsStatus nds_vector_resize(NdsVector *vector, size_t size);


/**
 * Function that returns the current capacity of the NdsVector.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @return    capacity    the capacity of the NdsVector
 *                  -1    the NdsVector is invalid
 *
 * @complexity    constant
 */
int nds_vector_capacity(NdsVector *vector);


/**
 * Function which requests that the given NdsVector will be able to fit
 * capacity elements.
 *
 * NOTE: A reallocation happens only if the new capacity is larger than the
 * current one. In all other cases, the capacity of the vector is not affected.
 *
 * @param       vector    pointer to a NdsVector structure
 * @param     capacity    new capacity for the NdsVector
 *
 * @return                     NDS_OK    no changes or the reallocation was successful
 *            NDS_INVALID_PARAM_ERROR    invalid parameters for the function
 *                NDS_MEM_ALLOC_ERROR    memory allocation error
 *
 * @complexity    if reallocation happens, linear
 */
NdsStatus nds_vector_reserve(NdsVector *vector, size_t capacity);


/**
 * Function which requests that the given NdsVector reduces its capacity in
 * order to be equal with its size.
 *
 * @param     vector      pointer to a NdsVector structure
 *
 * @return                     NDS_OK    shrink was successful
 *            NDS_INVALID_PARAM_ERROR    invalid parameters for the function
 *                NDS_MEM_ALLOC_ERROR    memory allocation error
 *
 * @complexity    linear on the size of the vector
 */
NdsStatus nds_vector_shrink_to_fit(NdsVector *vector);


#endif /* __NDS_VECTOR_H__ */
