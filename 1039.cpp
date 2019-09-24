#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;

map<string, set<int>> course_lists;

int main()
{
	int id_num, course_num;
	cin >> id_num >> course_num;

	for (int i = 0; i < course_num; i++)
	{
		int course_id, student_num;
		string student_name;
		scanf("%d %d", &course_id, &student_num);
		for (int j = 0; j < student_num; j++)
		{
			cin >> student_name;
			course_lists[student_name].insert(course_id);
		}
	}

	for (int i = 0; i < id_num; i++)
	{
		string id;
		cin >> id;
		auto iter = course_lists.find(id);
		if (iter == course_lists.end() || iter->second.empty())
			cout << id + " 0" << endl;
		else
		{
			cout << id + " " << iter->second.size() << " ";
			for (auto set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++)
			{
				if (set_iter == iter->second.begin())
					cout << *set_iter;
				else
					cout << " " << *set_iter;
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}