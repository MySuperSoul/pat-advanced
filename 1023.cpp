#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string Add(string& add_1, string& add_2)
{
	string add_result = add_1;
	for (int i = add_1.size() - 1; i >= 0; i--)
		add_result[i] += (add_2[i] - '0');

	for (int i = add_result.size() - 1; i >= 1; i--)
	{
		if (add_result[i] > '9')
		{
			add_result[i] -= 10;
			add_result[i - 1]++;
		}
	}

	if (add_result[0] > '9')
	{
		add_result[0] -= 10;
		add_result.insert(add_result.begin(), '1');
	}

	return add_result;
}

bool is_equal(string old_v, string new_v)
{
	sort(old_v.begin(), old_v.end());
	sort(new_v.begin(), new_v.end());

	return (old_v == new_v);
}

int main()
{
	string initial;
	cin >> initial;

	string double_initial = Add(initial, initial);
	if (is_equal(initial, double_initial))
	{
		cout << "Yes" << endl;
		cout << double_initial << endl;
	}
	else
	{
		cout << "No" << endl;
		cout << double_initial << endl;
	}

	//system("pause");
	return 0;
}