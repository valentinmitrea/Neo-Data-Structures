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

#ifndef __NDS_VECTOR_H__
#define __NDS_VECTOR_H__

#include <stddef.h>


typedef struct NdsVector NdsVector;
typedef struct NdsVectorPrivate NdsVectorPrivate;


struct NdsVector
{
	NdsVectorPrivate *private;
};


/**
 * Function that creates a new NdsVector.
 *
 * CAUTION: Do not forget to call nds_vector_destroy() before exiting the scope
 * of the current NdsVector in order to avoid memory leaks!
 *
 * @param     sizeof_element    size of one element in the vector
 *
 * @return    pointer to a new NdsVector structure or NULL if failure
 *
 * @complexity    depends on the complexity of the malloc() function
 */
extern NdsVector* nds_vector_new(size_t sizeof_element);


/**
 * Function that creates a new NdsVector with a given initial capacity.
 *
 * CAUTION: Do not forget to call nds_vector_destroy() before exiting the scope
 * of the current NdsVector in order to avoid memory leaks!
 *
 * @param     sizeof_element    size of one element in the vector
 * @param     capacity          the initial capacity of the vector
 *
 * @return    pointer to a new NdsVector structure or NULL if failure
 *
 * @complexity    depends on the complexity of the malloc() function
 */
extern NdsVector* nds_vector_new_with_capacity(size_t sizeof_element, size_t capacity);


/**
 * Function that frees the memory occupied by the given NdsVector.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @complexity    depends on the complexity of the free() function
 */
extern void nds_vector_destroy(NdsVector *vector);


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
extern int nds_vector_is_empty(NdsVector *vector);


/**
 * Function that returns the current size of the given NdsVector.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @return    the size of the NdsVector or -1 if the parameter is invalid
 *
 * @complexity    constant
 */
extern int nds_vector_size(NdsVector *vector);


/**
 * Function that returns the current capacity of the given NdsVector.
 *
 * @param     vector    pointer to a NdsVector structure
 *
 * @return    the capacity of the NdsVector or -1 if the parameter is invalid
 *
 * @complexity    constant
 */
extern int nds_vector_capacity(NdsVector *vector);


#endif /* __NDS_VECTOR_H__ */

