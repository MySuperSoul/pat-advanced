#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long ll;

const int Max = 100005;
const int max_amount = pow(10, 8) + 1;
ll dp[Max]; //calculate the sum
map<int, int> equal_map;
map<int, int> upper_map;
vector<int> amount_vec;

ll sequence_sum(int left_pos, int right_pos)
{
	ll sum = dp[right_pos] - dp[left_pos - 1];
	return sum;
}

int main()
{
	int diamands_num, amount;
	cin >> diamands_num >> amount;

	for (int i = 1; i <= diamands_num; i++)
	{
		int value;
		scanf("%d", &value);
		dp[i] = dp[i - 1] + value;
	}

	int min_amount = max_amount;
	int last_j = 1;
	for (int i = 1; i <= diamands_num; i++)
	{
		if (i > last_j) last_j = i;

		for (int j = last_j; j <= diamands_num; j++)
		{
			ll sum = sequence_sum(i, j);
			if (sum >= amount)
			{
				if (sum == amount)
				{
					equal_map[i] = j;
					min_amount = amount;
				}
				else
				{
					if (sum <= min_amount)
					{
						upper_map[i] = j;
						min_amount = sum;
					}
				}
				last_j = j;
				break;
			}
		}
	}

	if (min_amount == amount)
	{
		for (auto iter = equal_map.begin(); iter != equal_map.end(); iter++)
			cout << iter->first << "-" << iter->second << endl;
	}
	else
	{
		for (auto iter = upper_map.begin(); iter != upper_map.end(); iter++)
		{
			if(sequence_sum(iter->first, iter->second) == min_amount)
				cout << iter->first << "-" << iter->second << endl;
		}
	}

	//system("pause");
	return 0;
}