#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coins;

int main()
{
	int total_coin_number, demand_price;
	cin >> total_coin_number >> demand_price;

	for (int i = 0; i < total_coin_number; i++)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	sort(coins.begin(), coins.end());

	int front = 0;
	int rear = coins.size() - 1;

	while (front != rear)
	{
		int this_sum = coins[front] + coins[rear];

		if (this_sum < demand_price)
			front++;
		else if (this_sum > demand_price)
			rear--;
		else
			break;
	}

	if (front == rear)
		cout << "No Solution" << endl;
	else
		cout << coins[front] << " " << coins[rear] << endl;

	//system("pause");
	return 0;
}