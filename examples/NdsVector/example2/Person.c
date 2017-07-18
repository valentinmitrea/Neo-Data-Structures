#include "Person.h"

#include <stdio.h>


void print_person(struct Person person)
{
	printf("Name - %s | Age - %i\n", person.name, person.age);
}

