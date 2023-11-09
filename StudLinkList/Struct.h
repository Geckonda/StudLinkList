#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <iostream>
struct Stud
{
	char surname[40];
	char name[40];
	int year;
	int group;
	Stud* next;
};
Stud* InitStud(const char* surname, const char* name, int* atr) {
	Stud* st = (Stud*)malloc(sizeof(Stud));
	strcpy_s(st->surname, 40, surname);
	strcpy_s(st->name, 40, name);
	st->year = atr[0];
	st->group = atr[1];
	st->next = NULL;
	return st;
}
void PrintStud(Stud* student)
{
	while (student)
	{
		printf_s("Студент: %s %s\nГруппа/год: %d/%d\n", student->name, student->surname, student->group, student->year);
		printf_s("\n-----------------------------------------------\n");
		student = student->next;
	}
}
void DeleteStudUnit(Stud* &student, int index)
{
	if (index == 1)
	{
		Stud* temp = student;
		student = student->next;
		free(temp);
	}
	else
	{
		Stud* temp1 = student;
		Stud* temp2 = temp1;
		while (index-- > 1)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = temp1->next;
		free(temp1);
	}
}
void DeleteStudAll(Stud* &student)
{
	while (student)
	{
		Stud* del = student;
		student = student->next;
		free(del);
	}
}