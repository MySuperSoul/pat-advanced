#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct user
{
	string user_id;
	string user_password;
} User;

vector<User> user_vector;
bool is_change = false;

string change_pass(string password)
{
	string old_password = password;
	for (int i = 0; i < old_password.length(); i++)
	{
		if (old_password[i] == '1')
			old_password[i] = '@';
		else if(old_password[i] == '0')
			old_password[i] = '%';
		else if(old_password[i] == 'l')
			old_password[i] = 'L';
		else if(old_password[i] == 'O')
			old_password[i] = 'o';
	}

	return old_password;
}

int main()
{
	int total;
	cin >> total;

	for (int i = 0; i < total; i++)
	{
		User t;
		cin >> t.user_id >> t.user_password;

		string new_password = change_pass(t.user_password);
		if (t.user_password != new_password)
		{
			t.user_password = new_password;
			user_vector.push_back(t);
			is_change = true;
		}
	}

	if (is_change == false && total == 1)
		cout << "There is 1 account and no account is modified" << endl;
	else if (is_change == false && total > 1)
		cout << "There are " << total << " accounts and no account is modified" << endl;
	else if (is_change == true)
	{
		cout << user_vector.size() << endl;
		for (int i = 0; i < user_vector.size(); i++)
		{
			cout << user_vector[i].user_id << " " << user_vector[i].user_password << endl;
		}
	}

	//system("pause");
	return 0;
}
