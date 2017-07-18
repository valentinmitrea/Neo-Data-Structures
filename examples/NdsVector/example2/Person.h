#ifndef PERSON_H
#define PERSON_H


struct Person
{
	char name[30];
	int age;
};


void print_person(struct Person person);


#endif

