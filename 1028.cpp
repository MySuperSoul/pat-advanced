#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cstdio>
using namespace std;

typedef struct person
{
	char ID[20];
	char name[20];
	int grade;
}Student;

vector<Student> Result;

bool cmp1(Student s1, Student s2);
bool cmp2(Student s1, Student s2);
bool cmp3(Student s1, Student s2);
void Output();

int main()
{
	int N, C;
	cin >> N >> C;

	while (N--)
	{
		Student s;
		scanf("%s%s%d", s.ID, s.name, &s.grade);
		Result.push_back(s);
	}

	/*To choose the cmp function*/
	switch (C)
	{
	case 1:
		sort(Result.begin(), Result.end(), cmp1);
		break;
	case 2:
		sort(Result.begin(), Result.end(), cmp2);
		break;
	case 3:
		sort(Result.begin(), Result.end(), cmp3);
		break;
	default:
		break;
	}

	Output();
	//system("pause");
	return 0;
}

/*sort by ID --- C == 1*/
bool cmp1(Student s1, Student s2)
{
	if (strcmp(s1.ID, s2.ID) < 0)
		return true;
	else
		return false;
}

/*sort by name --- C == 2*/
bool cmp2(Student s1, Student s2)
{
	if (strcmp(s1.name, s2.name) == 0)
		return cmp1(s1, s2);
	else
		return (strcmp(s1.name, s2.name) < 0);
}

/*sort by grade --- C == 3*/
bool cmp3(Student s1, Student s2)
{
	if (s1.grade == s2.grade)
		return cmp1(s1, s2);
	else
		return s1.grade < s2.grade;
}

/*To do output*/
void Output()
{
	for (int i = 0; i < Result.size(); i++)
	{
		printf("%s %s %d\n", Result[i].ID, Result[i].name, Result[i].grade);
	}
}
