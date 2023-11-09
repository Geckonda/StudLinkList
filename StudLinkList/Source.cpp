#include "Struct.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(NULL));

	const int N = 5;
	const char* students[N * 2] =
	{
		"Ложкин", "Александр",
		"Шаймиев", "Адель",
		"Кондратьев", "Евгений",
		"Казанцев", "Владислав",
		"Новоселов", "Роман",
	};
	int atr[N][2] =
	{
		{2019, 191},
		{2023, 751},
		{2021, 32},
		{2022, 191},
		{2018, 101},
	};
	struct Stud* st;
	struct Stud* st1 = InitStud(students[0], students[1], atr[0]);
	st = st1;
	for (size_t i = 2; i < N * 2; i += 2)
	{
		struct Stud* st2 = InitStud(students[i], students[i + 1], atr[i / 2]);
		st->next = st2;
		st = st2;
	}
	PrintStud(st1);
	//st1 = DeleteStudUnit(st1, 1);
	DeleteStudUnit(st1, 2);
	//DeleteStudUnit(st1, 3);
	printf_s("\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
	PrintStud(st1);
	DeleteStudAll(st1);
	if (!st1)
	{
		printf_s("Я удалил все!");
	}
	else {
		printf_s("Что-то еще есть!");
	}
}