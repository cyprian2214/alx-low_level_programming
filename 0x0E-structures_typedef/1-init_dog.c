#include <stdio.h>

/**
 * struct dog - Defines a dog with name, age, and owner.
 * @name: The name of the dog (char pointer).
 * @age: The age of the dog (float).
 * @owner: The owner of the dog (char pointer).
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: Pointer to a struct dog variable.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}
