#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct bet
{
	int bet_num;
	int id;
	bool is_unique = true;

	bool operator< (const bet& rhs)
	{
		return id < rhs.id;
	}
} Bet;

map<int, Bet> bet_map;
map<int, Bet>::iterator iter;
vector<Bet> bet_vector;
int pos = 1;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		if (bet_map.empty())
		{
			Bet b_tmp;
			cin >> b_tmp.bet_num;
			b_tmp.id = pos++;
			bet_map.insert(pair<int, Bet>(b_tmp.bet_num, b_tmp));
		}
		else
		{
			int random_num;
			cin >> random_num;

			iter = bet_map.find(random_num);
			if (iter != bet_map.end())
				iter->second.is_unique = false;
			else
			{
				Bet b_tmp;
				b_tmp.bet_num = random_num;
				b_tmp.id = pos++;
				bet_map.insert(pair<int, Bet>(b_tmp.bet_num, b_tmp));
			}
		}
	}

	for (iter = bet_map.begin(); iter != bet_map.end(); iter++)
	{
		if (iter->second.is_unique == true)
			bet_vector.push_back(iter->second);
	}

	if (bet_vector.empty())
		cout << "None" << endl;
	else 
	{
		vector<Bet>::iterator bet_iter = min_element(bet_vector.begin(), bet_vector.end());
		cout << bet_iter->bet_num << endl;
	}

	//system("pause");
	return 0;
}