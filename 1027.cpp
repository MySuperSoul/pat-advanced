#include<iostream>
#include<vector>
using namespace std;

vector<char> final_result = { '#' };
char int2char(int value)
{
	if (value >= 0 && value <= 9)
		return ('0' + value);
	else
		return ('A' + value - 10);
}

void push_in(int earth_color)
{
	int high = earth_color / 13;
	int low = earth_color % 13;

	char high_digit = int2char(high);
	char low_digit = int2char(low);

	final_result.push_back(high_digit);
	final_result.push_back(low_digit);
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int earth_color;
		cin >> earth_color;
		push_in(earth_color);
	}

	for (int i = 0; i < final_result.size(); i++)
	{
		cout << final_result[i];
	}
	return 0;
}