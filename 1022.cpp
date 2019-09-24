#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef struct book
{
	string id;
	string title;
	string name_author;
	string key_words;
	string publisher;
	string year;
	bool operator<(const book& rhs) const
	{
		return id < rhs.id;
	}
} Book;

map<string, vector<Book>> title_map;
map<string, vector<Book>> author_map;
map<string, vector<Book>> keyword_map;
map<string, vector<Book>> publisher_map;
map<string, vector<Book>> year_map;
vector<Book> book_vec;

void insert_into_keywords(int pos)
{
	Book b = book_vec[pos];
	string text = b.key_words;

	while (text.find(" ") != -1)
	{
		int space_pos = text.find(" ");
		string one_word = text.substr(0, space_pos);
		text = text.substr(space_pos + 1);
		keyword_map[one_word].push_back(b);
	}
	keyword_map[text].push_back(b);
}

void insert_into_all_maps()
{
	for (int i = 0; i < book_vec.size(); i++)
	{
		Book b = book_vec[i];
		title_map[b.title].push_back(b);
		author_map[b.name_author].push_back(b);
		publisher_map[b.publisher].push_back(b);
		year_map[b.year].push_back(b);
		insert_into_keywords(i);
	}
}

void solution(int type, string value)
{
	if (type == 1)
	{
		auto iter = title_map.find(value);
		if (iter == title_map.end())
			cout << "Not Found" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end());
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second[i].id << endl;
		}
	}
	else if (type == 2)
	{
		auto iter = author_map.find(value);
		if (iter == author_map.end())
			cout << "Not Found" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end());
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second[i].id << endl;
		}
	}
	else if (type == 3)
	{
		auto iter = keyword_map.find(value);
		if (iter == keyword_map.end())
			cout << "Not Found" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end());
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second[i].id << endl;
		}
	}
	else if (type == 4)
	{
		auto iter = publisher_map.find(value);
		if (iter == publisher_map.end())
			cout << "Not Found" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end());
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second[i].id << endl;
		}
	}
	else if (type == 5)
	{
		auto iter = year_map.find(value);
		if (iter == year_map.end())
			cout << "Not Found" << endl;
		else
		{
			sort(iter->second.begin(), iter->second.end());
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second[i].id << endl;
		}
	}
}

int main()
{
	int cases;
	cin >> cases;
	getchar();

	while (cases--)
	{
		Book this_book;
		getline(cin, this_book.id);
		getline(cin, this_book.title);
		getline(cin, this_book.name_author);
		getline(cin, this_book.key_words);
		getline(cin, this_book.publisher);
		getline(cin, this_book.year);
		book_vec.push_back(this_book);
	}
	insert_into_all_maps();

	int query_num;
	cin >> query_num;
	getchar();

	while (query_num--)
	{
		string command;
		getline(cin, command);
		int type = command.front() - '0';
		cout << command << endl;
		solution(type, command.substr(3));
	}

	//system("pause");
	return 0;
}