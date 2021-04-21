#include <stdio.h>
#include "polymorphism.h"

void test_all_walk()
{
	t_person person_def;
	person_def.address = "사당동 8번출구";
	person_def.age = 26;
	person_def.company = "이노베이션아카데미";
	person_def.name = "김철수";

	t_dog dog_def;
	dog_def.age = 5;
	dog_def.name = "뭉치";
	dog_def.owner_name = "김철수";

	create_person(person_def);
	create_dog(dog_def);
	all_walk();
}

int main(void)
{
	test_all_walk();
}
