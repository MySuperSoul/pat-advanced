#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct student
{
	string id;
	int grade;
	int final_rank = 1;
	int location_number;
	int local_rank = 1;

	bool operator < (const student& rhs)
	{
		if (grade == rhs.grade)
			return id < rhs.id;
		else
			return grade > rhs.grade;
	}
}Student;

vector<Student> final_stu;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int K;
		vector<Student> stu_temp;
		cin >> K;
		
		while (K--)
		{
			Student s;
			cin >> s.id >> s.grade;
			s.location_number = i;
			stu_temp.push_back(s);
		}

		sort(stu_temp.begin(), stu_temp.end());

		for (int j = 1; j < stu_temp.size(); j++)
		{
			if (stu_temp[j].grade == stu_temp[j - 1].grade)
				stu_temp[j].local_rank = stu_temp[j - 1].local_rank;
			else
				stu_temp[j].local_rank = j + 1;
		}

		final_stu.insert(final_stu.end(), stu_temp.begin(), stu_temp.end());
	}

	sort(final_stu.begin(), final_stu.end());
	for (int j = 1; j < final_stu.size(); j++)
	{
		if (final_stu[j].grade == final_stu[j - 1].grade)
			final_stu[j].final_rank = final_stu[j - 1].final_rank;
		else
			final_stu[j].final_rank = j + 1;
	}

	cout << final_stu.size() << endl;
	for (int i = 0; i < final_stu.size(); i++)
	{
		cout << final_stu[i].id << " " << final_stu[i].final_rank << " " 
			<< final_stu[i].location_number << " " << final_stu[i].local_rank << endl;
	}
	//system("pause");
	return 0;
}