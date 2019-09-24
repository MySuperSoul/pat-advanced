#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

typedef long long ll;
bool is_Palindromic(string value_str)
{
	string reverse_value_str = value_str;
	reverse(reverse_value_str.begin(), reverse_value_str.end());

	if (value_str == reverse_value_str)
		return true;
	else
		return false;
}

string add(string& add_1, string& add_2)
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

string next_n(string old)
{
	string rev = old;
	reverse(rev.begin(), rev.end());
	return add(old, rev);
}

int main()
{
	ll K, i;
	string N;
	cin >> N >> K;

	for (i = 0; i < K; i++)
	{
		if (is_Palindromic(N))
			break;
		else
			N = next_n(N);
	}

	cout << N << endl;
	cout << i << endl;

	//system("pause");
	return 0;
}