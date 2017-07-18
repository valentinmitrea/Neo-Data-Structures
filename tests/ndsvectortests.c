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
 * This file defines various unit tests for the functionality of the NdsVector
 * data structure from the NDS library.
 *
 * @author      Valentin Gabriel Mitrea <mitrea.valentin@gmail.com>
 * @created     14 July 2017
 * @modified    18 July 2017
 */

#include <nds/ndsvector.h>

#include <stdio.h>
#include <stdlib.h>


/**
 * Test 1 - sanity check for nds_vector_new()
 */
int test_nds_vector_new_is_null()
{
	NdsVector *vector = nds_vector_new(0);

	/* vector should be null, because we set the size of one element to 0 */
	if (vector != NULL)
		return 1;

	return 0;
}


/**
 * Test 2 - verify if nds_vector_new() correctly creates an array
 */
int test_nds_vector_new_is_ok()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should not be null */
	if (vector == NULL)
		return 1;

	/* vector should have size 0 and capacity 10 */
	if (nds_vector_size(vector) != 0 || nds_vector_capacity(vector) != 10)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 3 - sanity check 1 for nds_vector_new_with_capacity()
 */
int test_nds_vector_new_with_capacity_is_null_1()
{
	NdsVector *vector = nds_vector_new_with_capacity(0, 20);

	/* vector should be null, because we set the size of one element to 0 */
	if (vector != NULL)
		return 1;

	return 0;
}


/**
 * Test 4 - sanity check 2 for nds_vector_new_with_capacity()
 */
int test_nds_vector_new_with_capacity_is_null_2()
{
	NdsVector *vector = nds_vector_new_with_capacity(sizeof(int), 0);

	/* vector should be null, because we set the capacity of the array to 0 */
	if (vector != NULL)
		return 1;

	return 0;
}


/**
 * Test 5 - verify if nds_vector_new_with_capacity() correctly creates an array
 */
int test_nds_vector_new_with_capacity_is_ok()
{
	NdsVector *vector = nds_vector_new_with_capacity(sizeof(int), 20);
	int result = 0;

	/* vector should not be null */
	if (vector == NULL)
		return 1;

	/* vector should have size 0 and capacity 20 */
	if (nds_vector_size(vector) != 0 || nds_vector_capacity(vector) != 20)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 6 - test if nds_vector_destroy() frees the memory of the NdsVector
 */
int test_nds_vector_destroy_frees_memory()
{
	NdsVector *vector = nds_vector_new(sizeof(int));

	/* cleanup */
	nds_vector_destroy(vector);

	/* the private part of the vector should be NULL */
	if (vector->private != NULL)
		return 1;

	return 0;
}


/**
 * Test 7 - sanity check 1 for nds_vector_is_empty()
 */
int test_nds_vector_is_empty_invalid_1()
{
	/* is_empty() should return -1 */
	if (nds_vector_is_empty(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 8 - sanity check 2 for nds_vector_is_empty()
 */
int test_nds_vector_is_empty_invalid_2()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* is_empty() should return -1 */
	if (nds_vector_is_empty(&vector) != -1)
		return 1;

	return 0;
}


/**
 * Test 9 - verify if NdsVector is empty after creation
 */
int test_nds_vector_is_empty_initial()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should be empty */
	if (!nds_vector_is_empty(vector))
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 10 - sanity check 1 for nds_vector_size()
 */
int test_nds_vector_size_is_invalid_1()
{
	/* size() should return -1 */
	if (nds_vector_size(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 11 - sanity check 2 for nds_vector_size()
 */
int test_nds_vector_size_is_invalid_2()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* size() should return -1 */
	if (nds_vector_size(&vector) != -1)
		return 1;

	return 0;
}


/**
 * Test 12 - verify if NdsVector has size 0 after creation
 */
int test_nds_vector_size_initial()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should have size 0 */
	if (nds_vector_size(vector) != 0)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 13 - sanity check 1 for nds_vector_capacity()
 */
int test_nds_vector_capacity_is_invalid_1()
{
	/* capacity() should return -1 */
	if (nds_vector_capacity(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 14 - sanity check 2 for nds_vector_capacity()
 */
int test_nds_vector_capacity_is_invalid_2()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* capacity() should return -1 */
	if (nds_vector_capacity(&vector) != -1)
		return 1;

	return 0;
}


/**
 * Test 15 - verify if NdsVector has capacity 10 after creation
 */
int test_nds_vector_capacity_initial()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should have capacity 10 */
	if (nds_vector_capacity(vector) != 10)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


int main(int argc, char **argv)
{
	/* sanity check */
	if (argc != 2)
	{
		printf("Usage: ./ndsvectortests test_id\n");
		return 1;
	}

	/* we run the test that was passed as command line argument */
	switch (atoi(argv[1]))
	{
		case 1:
			return test_nds_vector_new_is_null();

		case 2:
			return test_nds_vector_new_is_ok();

		case 3:
			return test_nds_vector_new_with_capacity_is_null_1();

		case 4:
			return test_nds_vector_new_with_capacity_is_null_2();

		case 5:
			return test_nds_vector_new_with_capacity_is_ok();

		case 6:
			return test_nds_vector_destroy_frees_memory();

		case 7:
			return test_nds_vector_is_empty_invalid_1();

		case 8:
			return test_nds_vector_is_empty_invalid_2();

		case 9:
			return test_nds_vector_is_empty_initial();

		case 10:
			return test_nds_vector_size_is_invalid_1();

		case 11:
			return test_nds_vector_size_is_invalid_2();

		case 12:
			return test_nds_vector_size_initial();

		case 13:
			return test_nds_vector_capacity_is_invalid_1();

		case 14:
			return test_nds_vector_capacity_is_invalid_2();

		case 15:
			return test_nds_vector_capacity_initial();

		default:
			printf("No tests were found with the given ID!\n");
			return 1;
	}
}

