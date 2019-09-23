#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;

int n;
int main()
{
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int len = s.size();
		len = len / 2;

		ll p = stoll(s.substr(0, len));
		ll l = stoll(s.substr(len));

		ll thi = stoll(s);
		if (p == 0 || l == 0) cout << "No" << endl;
		else if (thi % (p * l) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	//system("pause");
	return 0;
}