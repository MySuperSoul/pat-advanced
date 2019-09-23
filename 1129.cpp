#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;

#include<cstdio>

using namespace std;

struct node {
	int id;
	int times = 0;

	bool operator< (const node& a) const {
		if (times == a.times) return id < a.id;
		else return times > a.times;
	}
};

set<node> s;
int records[60000];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			node n;
			scanf("%d", &n.id);
			records[n.id] += 1;
			n.times = 1;
			s.insert(n);
		}
		else {
			node n;
			scanf("%d", &n.id);
			cout << n.id << ":";
			if (s.size() <= k) {
				for (auto v : s) cout << " " << v.id;
			}
			else {
				int cnt = 0;
				for (auto iter = s.begin(); iter != s.end(); iter++) {
					cnt++;
					cout << " " << (*iter).id;
					if (cnt == k) break;
				}
			}

			bool flag = false;

			auto iter = s.find(node{ n.id, records[n.id] });
			records[n.id] += 1;
			if (iter != s.end()) {
				flag = true;
				s.erase(iter);
				s.insert(node{ n.id, records[n.id] });
			}

			if (!flag) {
				n.times = 1;
				s.insert(n);
			}
			cout << endl;
		}
	}

	//system("pause");
	return 0;
}