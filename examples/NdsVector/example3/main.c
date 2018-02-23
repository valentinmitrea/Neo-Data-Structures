#include <stdio.h>
#include <stdlib.h>

#include <nds/ndsvector.h>


int main()
{
	NdsVector *vector;

	/* create a new NdsVector of integers */
	vector = nds_vector_new(sizeof(int));
	if (!vector)
	{
		printf("Error during NdsVector creation!\n");
		return -1;
	}

	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n\n", nds_vector_capacity(vector));

	/* reserve capacity for 20 integers */
	nds_vector_reserve(vector, 20);

	printf("Reserve space for 20 elements\n");
	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n\n", nds_vector_capacity(vector));

	/* shrink capacity to fit size */
	nds_vector_shrink_to_fit(vector);

	printf("Shrink to fit\n");
	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n\n", nds_vector_capacity(vector));

	/* resize to 5 integers */
	nds_vector_resize(vector, 5);

	printf("Resize to 5 elements\n");
	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n\n", nds_vector_capacity(vector));

	/* shrink capacity to fit size */
	nds_vector_shrink_to_fit(vector);

	printf("Shrink to fit\n");
	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n", nds_vector_capacity(vector));

	/* cleanup */
	nds_vector_destroy(vector);

	return 0;
}

