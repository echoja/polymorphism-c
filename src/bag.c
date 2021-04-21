#include "polymorphism.h"
#include <stdlib.h>

void bag_add(t_bag *bag, void *item)
{
	void **new_arr;

	bag->arr[bag->len] = (void *)item;
	bag->len += 1;
	if (bag->len > bag->max / 2)
	{
		bag->max *= 2;
		m(&new_arr, sizeof(void *) * bag->max);
		for (int i = 0; i < bag->len; i++)
			new_arr[i] = bag->arr[i];
		free(bag->arr);
		bag->arr = new_arr;
	}
}

t_bag create_bag()
{
	t_bag bag;

	bag.len = 0;
	bag.max = 10;
	if (!m(&bag.arr, sizeof(void *) * 10))
		exit(0);
	return (bag);
}

void bag_foreach(t_bag *bag, void (*func)(void *))
{
	for (int i = 0; i < bag->len; i++)
		func(bag->arr[i]);
}
