#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdio>
using namespace std;

double result = 1;
vector<double> final_result;

/*To do output*/
void Output(int cur_index)
{
	switch (cur_index)
	{
	case 0:
		cout << "W ";
		break;
	case 1:
		cout << "T ";
		break;
	case 2:
		cout << "L ";
		break;
	default:
		break;
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		/*initial state*/
		double max = -100;
		int index = 0;

		for (int j = 0; j < 3; j++)
		{
			double temp;
			
			cin >> temp;
			if (temp > max)
			{
				max = temp;
				index = j;
			}
		}

		Output(index);
		final_result.push_back(max);
	}

	for (int i = 0; i < final_result.size(); i++)
	{
		result *= final_result[i];
	}

	result = (result * 0.65 - 1) * 2;
	printf("%.2f", result);
	//system("pause");
	return 0;
}