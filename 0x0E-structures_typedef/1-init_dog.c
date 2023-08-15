#include <stdlib.h>
#include "dog.h"

/**
 * struct dog - Defines a dog with name, age, and owner.
 * @name: The name of the dog (char pointer).
 * @age: The age of the dog (float).
 * @owner: The owner of the dog (char pointer).
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
