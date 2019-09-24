#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> coupon_positive, coupon_negative;
vector<int> product_positive, product_negative;

bool cmp(int& a, int& b)
{
	return a > b;
}

int main()
{
	int coupons_num;
	cin >> coupons_num;

	for (int i = 0; i < coupons_num; i++)
	{
		int value;
		scanf("%d", &value);
		if (value >= 0) coupon_positive.push_back(value);
		else coupon_negative.push_back(value);
	}

	int product_num;
	cin >> product_num;

	for (int i = 0; i < product_num; i++)
	{
		int value;
		scanf("%d", &value);
		if (value >= 0) product_positive.push_back(value);
		else product_negative.push_back(value);
	}

	if (!coupon_positive.empty()) sort(coupon_positive.begin(), coupon_positive.end(), cmp);
	if (!coupon_negative.empty()) sort(coupon_negative.begin(), coupon_negative.end());
	if (!product_positive.empty()) sort(product_positive.begin(), product_positive.end(), cmp);
	if (!product_negative.empty()) sort(product_negative.begin(), product_negative.end());

	long long result = 0;
	for (int i = 0; i < coupon_positive.size() && i < product_positive.size(); i++)
		result += coupon_positive[i] * product_positive[i];
	for (int i = 0; i < coupon_negative.size() && i < product_negative.size(); i++)
		result += coupon_negative[i] * product_negative[i];

	cout << result << endl;
	//system("pause");
	return 0;
}