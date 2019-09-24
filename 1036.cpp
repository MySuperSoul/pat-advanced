#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct student
{
	string name;
	string gender;
	string id;
	int grade;
} Student;

bool cmp(Student& s1, Student& s2)
{
	return s1.grade < s2.grade;
}

vector<Student> student_male;
vector<Student> student_female;

bool is_lack = false; //judge whether male or female lack

int main()
{
	int N;
	cin >> N;

	/*read in the information*/
	while (N--)
	{
		Student s_temp;
		cin >> s_temp.name >> s_temp.gender >> s_temp.id >> s_temp.grade;

		if (s_temp.gender == "M")
			student_male.push_back(s_temp);
		else
			student_female.push_back(s_temp);
	}

	/*to do sort*/
	sort(student_male.begin(), student_male.end(), cmp);
	sort(student_female.begin(), student_female.end(), cmp);

	/*To output information ---female*/
	if (student_female.size() == 0)
	{
		cout << "Absent" << endl;
		is_lack = true;
	}
	else
	{
		cout << student_female.back().name << " " << student_female.back().id << endl;
	}

	/*To output information --- male*/
	if (student_male.size() == 0)
	{
		cout << "Absent" << endl;
		is_lack = true;
	}
	else
	{
		cout << student_male[0].name << " " << student_male[0].id << endl;
	}

	/*To output difference*/
	if (is_lack)
		cout << "NA" << endl;
	else
		cout << abs(student_female.back().grade - student_male.begin()->grade);

	//system("pause");
	return 0;
}