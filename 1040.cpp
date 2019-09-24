#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool is_found = false;
bool is_symmetric(string rhs)
{
	int i, j;
	for (i = 0, j = rhs.length() - 1; i <= j; i++, j--)
	{
		if (rhs[i] != rhs[j])
			return false;
	}
	return true;
}

int main()
{
	string text;
	getline(cin, text);

	int length;
	for (length = text.length(); length > 0; length--)
	{
		for (int pos = 0; pos <= text.length() - length; pos++)
		{
			if (is_symmetric(text.substr(pos, length)))
			{
				is_found = true;
				cout << length << endl;
				break;
			}
		}

		if (is_found)
			break;
	}

	return 0;
}