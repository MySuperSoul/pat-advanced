#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string get_space(int space_num)
{
	string result = "";
	for (int i = 0; i < space_num; i++) result += " ";
	return result;
}

string ctos(char value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

int main()
{
	int col_num, row_num;
	string text;
	cin >> text;

	int length = text.length() + 2;
	if (length % 3 == 0)
		col_num = row_num = length / 3;
	else if (length % 3 == 1)
	{
		row_num = length / 3;
		col_num = row_num + 1;
	}
	else
	{
		row_num = length / 3;
		col_num = row_num + 2;
	}

	int i, j, count;
	for (i = 0, j = text.length() - 1, count = 0; count < row_num - 1; i++, j--, count++)
	{
		string this_line = ctos(text[i]) + get_space(col_num - 2) + ctos(text[j]);
		cout << this_line << endl;
	}
	cout << text.substr(row_num - 1, col_num) << endl;
	//system("pause");
	return 0;
}