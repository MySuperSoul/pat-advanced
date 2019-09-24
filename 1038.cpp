#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

vector<string> str_vec;
bool cmp(string& s1, string& s2)
{
	string s = s1 + s2;
	string t = s2 + s1;
	return (stoll(s) < stoll(t));
}

int main()
{
	int num;
	cin >> num;

	while (num--)
	{
		string s;
		cin >> s;
		str_vec.push_back(s);
	}

	sort(str_vec.begin(), str_vec.end(), cmp);
	if (stoi(str_vec.back()) == 0) cout << "0";
	else
	{
		for (int i = 0; i < str_vec.size(); i++)
		{
			if (i == 0) cout << stoi(str_vec[i]);
			else cout << str_vec[i];
		}
	}
	//system("pause");
	return 0;
}