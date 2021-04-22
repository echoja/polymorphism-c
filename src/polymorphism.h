#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

#include <stddef.h>
typedef int t_bool;
#define TRUE 1
#define FALSE 0

t_bool m(void *target, size_t size);

typedef struct s_bag
{
	void **arr;
	int len;
	int max;
} t_bag;

typedef struct s_vtables
{
	t_bag walkables;
} t_vtables;

typedef struct s_walkable
{
	void (*walk)(void *raw_self);
	void *object;
} t_walkable;

typedef struct s_person
{
	char *name;
	int age;
	char *company;
	char *address;
} t_person;

typedef struct s_dog
{
	char *name;
	int age;
	char *owner_name;
} t_dog;

t_bag create_bag();
void bag_add(t_bag *bag, void *item);
void bag_foreach(t_bag *bag, void (*func)(void *));

t_vtables *get_vtables();

void create_person(t_person def);
void walk_person(void *raw_self);
void create_dog(t_dog def);
void walk_dog(void *raw_self);

void all_walk();

#endif
