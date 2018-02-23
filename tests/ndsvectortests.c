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
 * This file defines various unit tests for the functionality of the NdsVector
 * data structure from the NDS library.
 *
 * @author      Valentin Gabriel Mitrea <mitrea.valentin@gmail.com>
 * @created     14 July 2017
 * @modified    23 February 2018
 */

#include <nds/ndsvector.h>

#include <stdio.h>
#include <stdlib.h>


/**
 * Unit tests for the nds_vector_new() function.
 */

/**
 * Test 1 - sanity check for nds_vector_new()
 */
int test_1_nds_vector_new()
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
int test_2_nds_vector_new()
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
 * Unit tests for the nds_vector_new_with_capacity() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_new_with_capacity()
 */
int test_1_nds_vector_new_with_capacity()
{
	NdsVector *vector = nds_vector_new_with_capacity(0, 20);

	/* vector should be null, because we set the size of one element to 0 */
	if (vector != NULL)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_new_with_capacity()
 */
int test_2_nds_vector_new_with_capacity()
{
	NdsVector *vector = nds_vector_new_with_capacity(sizeof(int), 0);

	/* vector should be null, because we set the capacity of the array to 0 */
	if (vector != NULL)
		return 1;

	return 0;
}


/**
 * Test 3 - verify if nds_vector_new_with_capacity() correctly creates an array
 */
int test_3_nds_vector_new_with_capacity()
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
 * Unit tests for the nds_vector_destroy() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_destroy()
 */
int test_1_nds_vector_destroy()
{
	nds_vector_destroy(NULL);

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_destroy()
 */
int test_2_nds_vector_destroy()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	struct NdsVectorPrivate *private = vector->private;

	vector->private = NULL;
	nds_vector_destroy(vector);

	/* cleanup */
	free(private);

	return 0;
}


/**
 * Test 3 - test if nds_vector_destroy() frees the memory of the NdsVector
 */
int test_3_nds_vector_destroy()
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
 * Unit tests for the nds_vector_is_empty() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_is_empty()
 */
int test_1_nds_vector_is_empty()
{
	/* is_empty() should return -1 */
	if (nds_vector_is_empty(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_is_empty()
 */
int test_2_nds_vector_is_empty()
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
 * Test 3 - verify if NdsVector is empty after creation
 */
int test_3_nds_vector_is_empty()
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
 * Unit tests for the nds_vector_size() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_size()
 */
int test_1_nds_vector_size()
{
	/* size() should return -1 */
	if (nds_vector_size(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_size()
 */
int test_2_nds_vector_size()
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
 * Test 3 - verify if NdsVector has size 0 after creation
 */
int test_3_nds_vector_size()
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
 * Unit tests for the nds_vector_resize() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_resize()
 */
int test_1_nds_vector_resize()
{
	/* resize() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_resize(NULL, 0) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_resize()
 */
int test_2_nds_vector_resize()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* resize() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_resize(&vector, 0) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 3 - resize NdsVector with 0 size
 */
int test_3_nds_vector_resize()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* TODO - add some elements */

	/* vector should have size 0 after resize */
	nds_vector_resize(vector, 0);
	if (nds_vector_size(vector) != 0)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 4 - resize NdsVector with smaller size
 */
int test_4_nds_vector_resize()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* TODO - add some elements */

	/* vector should have size 2 after resize */
	nds_vector_resize(vector, 2);
	if (nds_vector_size(vector) != 2)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 5 - resize NdsVector with same size
 */
int test_5_nds_vector_resize()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0, size;

	/* TODO - add some elements */

	size = nds_vector_size(vector);

	/* vector should have same size after resize */
	nds_vector_resize(vector, size);
	if (nds_vector_size(vector) != size)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 6 - resize NdsVector with larger size
 */
int test_6_nds_vector_resize()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should have size 8 after resize */
	nds_vector_resize(vector, 8);
	if (nds_vector_size(vector) != 8)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 7 - resize NdsVector with size that is larger than capacity
 */
int test_7_nds_vector_resize()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* vector should have size 15 and capacity 30 after resize */
	nds_vector_resize(vector, 15);
	if (nds_vector_size(vector) != 15 || nds_vector_capacity(vector) != 30)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Unit tests for the nds_vector_capacity() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_capacity()
 */
int test_1_nds_vector_capacity()
{
	/* capacity() should return -1 */
	if (nds_vector_capacity(NULL) != -1)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_capacity()
 */
int test_2_nds_vector_capacity()
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
 * Test 3 - verify if NdsVector has capacity 10 after creation
 */
int test_3_nds_vector_capacity()
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


/**
 * Unit tests for the nds_vector_reserve() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_reserve()
 */
int test_1_nds_vector_reserve()
{
	/* reserve() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_reserve(NULL, 20) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_reserve()
 */
int test_2_nds_vector_reserve()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* reserve() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_reserve(&vector, 20) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 3 - sanity check 3 for nds_vector_reserve()
 */
int test_3_nds_vector_reserve()
{
	NdsVector vector;

	/* reserve() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_reserve(&vector, 0) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 4 - sanity check 4 for nds_vector_reserve()
 */
int test_4_nds_vector_reserve()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	/* reserve() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_reserve(vector, 10) != NDS_INVALID_PARAM_ERROR)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 5 - verify if nds_vector_reserve() extends the capacity
 */
int test_5_nds_vector_reserve()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	nds_vector_reserve(vector, 20);

	/* reserve() should have extended the capacity to 20 */
	if (nds_vector_capacity(vector) != 20)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Unit tests for the nds_vector_shrink_to_fit() function.
 */

/**
 * Test 1 - sanity check 1 for nds_vector_shrink_to_fit()
 */
int test_1_nds_vector_shrink_to_fit()
{
	/* shrink_to_fit() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_shrink_to_fit(NULL) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 2 - sanity check 2 for nds_vector_shrink_to_fit()
 */
int test_2_nds_vector_shrink_to_fit()
{
	NdsVector vector;

	/* invalidate the NdsVector */
	vector.private = NULL;

	/* shrink_to_fit() should return NDS_INVALID_PARAM_ERROR */
	if (nds_vector_shrink_to_fit(&vector) != NDS_INVALID_PARAM_ERROR)
		return 1;

	return 0;
}


/**
 * Test 3 - verify if nds_vector_shrink_to_fit() correctly changes the capacity when size is 0
 */
int test_3_nds_vector_shrink_to_fit()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	nds_vector_shrink_to_fit(vector);

	/* shrink_to_fit() should have reduced the capacity to 1 */
	if (nds_vector_capacity(vector) != 1)
		result = 1;

	/* cleanup */
	nds_vector_destroy(vector);

	return result;
}


/**
 * Test 4 - verify if nds_vector_shrink_to_fit() correctly changes the capacity
 */
int test_4_nds_vector_shrink_to_fit()
{
	NdsVector *vector = nds_vector_new(sizeof(int));
	int result = 0;

	nds_vector_resize(vector, 5);
	nds_vector_shrink_to_fit(vector);

	/* shrink_to_fit() should have reduced the capacity to 5 */
	if (nds_vector_capacity(vector) != 5)
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
			return test_1_nds_vector_new();

		case 2:
			return test_2_nds_vector_new();

		case 3:
			return test_1_nds_vector_new_with_capacity();

		case 4:
			return test_2_nds_vector_new_with_capacity();

		case 5:
			return test_3_nds_vector_new_with_capacity();

		case 6:
			return test_1_nds_vector_destroy();

		case 7:
			return test_2_nds_vector_destroy();

		case 8:
			return test_3_nds_vector_destroy();

		case 9:
			return test_1_nds_vector_is_empty();

		case 10:
			return test_2_nds_vector_is_empty();

		case 11:
			return test_3_nds_vector_is_empty();

		case 12:
			return test_1_nds_vector_size();

		case 13:
			return test_2_nds_vector_size();

		case 14:
			return test_3_nds_vector_size();

		case 15:
			return test_1_nds_vector_resize();

		case 16:
			return test_2_nds_vector_resize();

		case 17:
			return test_3_nds_vector_resize();

		case 18:
			return test_4_nds_vector_resize();

		case 19:
			return test_5_nds_vector_resize();

		case 20:
			return test_6_nds_vector_resize();

		case 21:
			return test_7_nds_vector_resize();

		case 22:
			return test_1_nds_vector_capacity();

		case 23:
			return test_2_nds_vector_capacity();

		case 24:
			return test_3_nds_vector_capacity();

		case 25:
			return test_1_nds_vector_reserve();

		case 26:
			return test_2_nds_vector_reserve();

		case 27:
			return test_3_nds_vector_reserve();

		case 28:
			return test_4_nds_vector_reserve();

		case 29:
			return test_5_nds_vector_reserve();

		case 30:
			return test_1_nds_vector_shrink_to_fit();

		case 31:
			return test_2_nds_vector_shrink_to_fit();

		case 32:
			return test_3_nds_vector_shrink_to_fit();

		case 33:
			return test_4_nds_vector_shrink_to_fit();

		default:
			printf("No tests were found with the given ID!\n");
			return 1;
	}
}
