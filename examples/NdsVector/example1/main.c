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

	if (nds_vector_is_empty(vector))
		printf("Vector is empty!\n");
	else
		printf("Vector is not empty!\n");

	printf("Size = %i\n", nds_vector_size(vector));
	printf("Capacity = %i\n", nds_vector_capacity(vector));

	/* cleanup */
	nds_vector_destroy(vector);

	return 0;
}

