#include "Person.h"

#include <stdio.h>
#include <string.h>

#include <nds/ndsvector.h>


void initialize_person(struct Person *person, char *name, int age)
{
	strcpy(person->name, name);
	person->age = age;
}


int main()
{
	struct Person person1, person2;
	NdsVector *vector;

	initialize_person(&person1, "Person1", 24);
	initialize_person(&person2, "Person2", 27);

	/* create a new NdsVector of Person structures */
	vector = nds_vector_new(sizeof(struct Person));
	if (!vector)
	{
		printf("Error during NdsVector creation!\n");
		return -1;
	}

	/* cleanup */
	nds_vector_destroy(vector);

	return 0;
}

