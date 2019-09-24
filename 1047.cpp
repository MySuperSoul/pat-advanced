#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

map<int, vector<char*>> course_lists;
char name[50001][6];

bool cmp(char* a, char* b)
{
	return strcmp(a, b) < 0;
}

int main()
{
	int student_num, course_num;
	cin >> student_num >> course_num;

	for (int i = 0; i < student_num; i++)
	{
		int num;

		scanf("%s %d", name[i], &num);
		for (int j = 0; j < num; j++)
		{
			int id;
			scanf("%d", &id);
			course_lists[id].push_back(name[i]);
		}
	}

	for (int i = 1; i <= course_num; i++)
	{
		auto iter = course_lists.find(i);
		if (iter == course_lists.end())
			cout << i << " 0" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end(), cmp);
			cout << i << " " << iter->second.size() << endl;
			for (int j = 0; j < iter->second.size(); j++)
				printf("%s\n", iter->second[j]);
		}
	}
	//system("pause");
	return 0;
}