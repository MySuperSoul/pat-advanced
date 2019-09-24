#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int hour_minute = 60;
const int day_minute = 1440;

typedef struct person
{
	string name;
	string time;
	bool is_on_line;

	bool operator<(const person& rhs) const
	{
		return (name == rhs.name) ? (time < rhs.time) : (name < rhs.name);
	}
} Person;

typedef struct record
{
	string start_time;
	string end_time;
	int total_time;
	string month;
	double price = 0;
} Record;

vector<double> rate;
vector<Person> person_vec;
map<string, vector<Record>> record_map;

double get_one_day_price()
{
	double result = 0;
	for (int i = 0; i < rate.size(); i++)
		result += hour_minute * rate[i];
	return result;
}

void Process(int pos)
{
	int last_day, last_hour, last_minute, cur_day, cur_hour, cur_minute;
	Record this_record;
	this_record.month = person_vec[pos].time.substr(0, 2);
	this_record.start_time = person_vec[pos].time.substr(3);
	this_record.end_time = person_vec[pos + 1].time.substr(3);
	last_day = stoi(person_vec[pos].time.substr(3, 2)); last_hour = stoi(person_vec[pos].time.substr(6, 2)); last_minute = stoi(person_vec[pos].time.substr(9, 2));
	cur_day = stoi(person_vec[pos + 1].time.substr(3, 2)); cur_hour = stoi(person_vec[pos + 1].time.substr(6, 2)); cur_minute = stoi(person_vec[pos + 1].time.substr(9, 2));

	/*to calculate the minutes last*/
	int day_diff = cur_day - last_day;
	int minutes_diff = day_diff * day_minute + (cur_hour * hour_minute + cur_minute) - (last_hour * hour_minute + last_minute);
	this_record.total_time = minutes_diff;

	/*to calculate one day total price*/
	if (day_diff == 0)
	{
		if (cur_hour == last_hour)
			this_record.price = (cur_minute - last_minute) * rate[cur_hour];
		else
		{
			int last = hour_minute - last_minute;
			this_record.price += last * rate[last_hour];

			for (int i = last_hour + 1; i < cur_hour; i++)
				this_record.price += hour_minute * rate[i];

			this_record.price += cur_minute * rate[cur_hour];
		}
	}
	else/*if exists day diff, then add in*/
	{
		/*last day*/
		int last = hour_minute - last_minute;
		this_record.price += last * rate[last_hour];

		for (int i = last_hour + 1; i < 24; i++)
			this_record.price += hour_minute * rate[i];

		/*current day*/
		for (int i = 0; i < cur_hour; i++)
			this_record.price += hour_minute * rate[i];
		this_record.price += cur_minute * rate[cur_hour];

		/*the whole days here*/
		this_record.price += (day_diff - 1) * get_one_day_price();
	}
	record_map[person_vec[pos].name].push_back(this_record);
}

int main()
{
	for (int i = 0; i < 24; i++)
	{
		int this_rate;
		scanf("%d", &this_rate);
		rate.push_back((double)this_rate / 100);
	}

	int record_num;
	cin >> record_num;

	for (int i = 0; i < record_num; i++)
	{
		Person p;
		string text;
		cin >> p.name >> p.time >> text;
		if (text == "on-line") p.is_on_line = true;
		else p.is_on_line = false;
		person_vec.push_back(p);
	}

	sort(person_vec.begin(), person_vec.end());
	for (int i = 0; i < person_vec.size() - 1; )
	{
		if (person_vec[i].name != person_vec[i + 1].name)
			i++;
		else
		{
			if (person_vec[i].is_on_line && !person_vec[i + 1].is_on_line)
			{
				Process(i);
				i += 2;
			}
			else i++;
		}
	}

	for (auto iter = record_map.begin(); iter != record_map.end(); iter++)
	{
		double total_price = 0;
		cout << iter->first + " " << iter->second.front().month << endl;

		for (int i = 0; i < iter->second.size(); i++)
		{
			cout << iter->second[i].start_time + " " + iter->second[i].end_time + " " << iter->second[i].total_time << " $";
			printf("%.2f\n", iter->second[i].price);
			total_price += iter->second[i].price;
		}
		cout << "Total amount: $";
		printf("%.2f\n", total_price);
	}
	return 0;
}