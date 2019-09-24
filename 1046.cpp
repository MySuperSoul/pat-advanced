#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cstdio>
using namespace std;

const int Max = 100005;
vector<int> exits;
int dp[Max];
int sum_distance;

void find_shortest(int exit1, int exit2, int exits_num)
{
	if (exit1 > exit2)
		swap(exit1, exit2);
	int sum = dp[exit2 - 1] - dp[exit1 - 1];
	cout << min(sum, sum_distance - sum) << endl;
}

int main()
{
	int exits_num;
	cin >> exits_num;

	for (int i = 0; i < exits_num; i++)
	{
		int exit;
		scanf("%d", &exit);
		sum_distance += exit;
		dp[i + 1] = dp[i] + exit;
		exits.push_back(exit);
	}

	int pairs;
	cin >> pairs;

	for (int i = 0; i < pairs; i++)
	{
		int query_1, query_2;
		scanf("%d%d", &query_1, &query_2);
		find_shortest(query_1, query_2, exits_num);
	}

	return 0;
}