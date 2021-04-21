#include <stdio.h>
#include "polymorphism.h"

t_vtables *get_vtables()
{
	static t_vtables t;

	if (!t.printables.arr)
		t.printables = create_bag();
	return &t;
}

void do_walk(void *ptr) {
	t_walkable *walkable;

	walkable = (t_walkable *)ptr;
	walkable->walk(walkable->object);
}

void all_walk() {
	bag_foreach(&get_vtables()->printables, do_walk);
};

t_walkable *create_walkable(void *obj, void (*walk_handler)(void *)) {
	t_walkable *walkable;

	m(&walkable, sizeof(t_walkable));
	walkable->object = obj;
	walkable->walk = walk_handler;
	bag_add(&get_vtables()->printables, walkable);
	return walkable;
}

void create_person(t_person def) {
	t_person *person;

	m(&person, sizeof(t_person));
	person->address = def.address;
	person->age = def.age;
	person->company = def.company;
	person->name = def.name;
	create_walkable(person, walk_person);
}

void walk_person(void *raw_self) {
	t_person *self;

	self = (t_person *)raw_self;
	printf("%s 은 자신의 집인 %s에서 출발해 %s로 터벅터벅 걸어간다...\n", self->name, self->address, self->company);
}

void create_dog(t_dog def) {
	t_dog *dog;

	m(&dog, sizeof(t_dog));
	dog->age = def.age;
	dog->name = def.name;
	dog->owner_name = def.owner_name;
	create_walkable(dog, walk_dog);
}

void walk_dog(void *raw_self) {
	t_dog *self;

	self = (t_dog *)raw_self;
	printf("%s 은 주인인 %s와 함께 산책한다...\n", self->name, self->owner_name);
}

// void walk_person(t_person *self) {
// 	printf("%s 은 자신의 집인 %s에서 출발해 %s로 터벅터벅 걸어간다...\n", self->name, self->address, self->company);
// }

// void walk_dog(t_dog *self) {
// 	printf("%s 은 주인인 %s와 함께 산책한다...\n", self->name, self->owner_name);
// }

// int main(void) {
// 	t_person person;
// 	person.address = "사당동 8번출구";
// 	person.age = 26;
// 	person.company = "이노베이션아카데미";
// 	person.name = "김철수";

// 	t_dog dog;
// 	dog.age = 5;
// 	dog.name = "뭉치";
// 	dog.owner_name = "김철수";

// 	t_dog another_dog;
// 	another_dog.age = 3;
// 	another_dog.name = "삐삐";
// 	another_dog.owner_name = "김영희";

// 	void *walkable_things[3];
// 	walkable_things[0] = &person;
// 	walkable_things[1] = &dog;
// 	walkable_things[2] = &another_dog;

// 	for (int i = 0; i < 3; i++)
// 		walk_??(walkable_things[i]);
// }
