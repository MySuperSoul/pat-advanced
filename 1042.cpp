#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

typedef struct card
{
	string card_id;
	int real_pos;

	bool operator< (const card& rhs)
	{
		return real_pos < rhs.real_pos;
	}
} Card;

int position = 1;
vector<Card> card_vector;
vector<int> pos_vector;

string itos(int value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

void initial()
{
	for (int i = 1; i <= 13; i++)
	{
		Card c_tmp;
		c_tmp.card_id = "S" + itos(i);
		c_tmp.real_pos = position;
		card_vector.push_back(c_tmp);
		position++;
	}

	for (int i = 1; i <= 13; i++)
	{
		Card c_tmp;
		c_tmp.card_id = "H" + itos(i);
		c_tmp.real_pos = position;
		card_vector.push_back(c_tmp);
		position++;
	}

	for (int i = 1; i <= 13; i++)
	{
		Card c_tmp;
		c_tmp.card_id = "C" + itos(i);
		c_tmp.real_pos = position;
		card_vector.push_back(c_tmp);
		position++;
	}

	for (int i = 1; i <= 13; i++)
	{
		Card c_tmp;
		c_tmp.card_id = "D" + itos(i);
		c_tmp.real_pos = position;
		card_vector.push_back(c_tmp);
		position++;
	}

	for (int i = 1; i <= 2; i++)
	{
		Card c_tmp;
		c_tmp.card_id = "J" + itos(i);
		c_tmp.real_pos = position;
		card_vector.push_back(c_tmp);
		position++;
	}
}

void shuffle()
{
	for (int i = 0; i < pos_vector.size(); i++)
	{
		card_vector[i].real_pos = pos_vector[i];
	}

	sort(card_vector.begin(), card_vector.end());
}

int main()
{
	int shuffle_time;
	cin >> shuffle_time;
	initial();

	for (int i = 0; i < 54; i++)
	{
		int pos;
		cin >> pos;
		pos_vector.push_back(pos);
	}
	
	for (int i = 0; i < shuffle_time; i++)
	{
		shuffle();
	}

	for (int i = 0; i < card_vector.size(); i++)
	{
		if (i == 0)
			cout << card_vector[i].card_id;
		else
			cout << " " + card_vector[i].card_id;
	}

	//system("pause");
	return 0;
}
