#include<iostream>
#include<string>
using namespace std;

const int Max = 10000;
int visit[Max];

int main()
{
	string s1, s2, result;
	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i < s2.length(); i++)
		visit[s2[i]] = 1;

	for (int i = 0; i < s1.length(); i++)
	{
		if (visit[s1[i]] == 0)
			result += s1[i];
	}

	cout << result << endl;
	return 0;
}