/*3160104367 黄亦非 ZJU*/
#include<iostream>
#include<algorithm>
#include<vector>

#define MaxN 201
#define MaxL 10001

using namespace std;

vector<int> sequence1, sequence2; //vector to store the sequence
vector<int> temp;
int dp[MaxN][MaxL]; //dp array
int N, M, L;

int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int number;
		cin >> number;
		sequence1.push_back(number);
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int number;
		cin >> number;
		sequence2.push_back(number);
	}

	int index_x, index_y; //遍历整个所有的情况
	for (index_x = 0; index_x <= M; index_x++)
	{
		for (index_y = 0; index_y <= L; index_y++)
		{
			if (index_x == 0 || index_y == 0)
				dp[index_x][index_y] = 0;
			else
			{
				temp.push_back(dp[index_x - 1][index_y]); temp.push_back(dp[index_x][index_y - 1]); 
				temp.push_back(dp[index_x - 1][index_y - 1]);
				sort(temp.begin(), temp.end());
				int cur = temp.back();
				dp[index_x][index_y] = cur + (sequence1[index_x - 1] == sequence2[index_y - 1] ? 1 : 0);
				temp.clear();
			}
		}
	}

	cout << dp[M][L] << endl;
	return 0;
}