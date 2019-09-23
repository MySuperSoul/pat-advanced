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

#define maxn 100005

struct node
{
	int address;
	int value;
	int next = -1;
}N[maxn];

int start_p, n, k;
vector<node> node_vec;

int main()
{
	cin >> start_p >> n >> k;

	for (int i = 0; i < n; i++) {
		int p, v, n;
		scanf("%d %d %d", &p, &v, &n);
		N[p].address = p;
		N[p].value = v;
		N[p].next = n;
	}

	while (start_p != -1)
	{
		node_vec.push_back(N[start_p]);
		start_p = N[start_p].next;
	}

	vector<node> ans;
	for (auto v : node_vec) {
		if (v.value < 0) ans.push_back(v);
	}

	for (auto v : node_vec) {
		if (v.value >= 0 && v.value <= k) ans.push_back(v);
	}

	for (auto v : node_vec) {
		if (v.value > k) ans.push_back(v);
	}

	if (ans.size() == 1) {
		node n = ans.front();
		printf("%05d %d -1", n.address, n.value);
	}
	else
	{
		for (int i = 0; i < ans.size() - 1; i++) {
			node n = ans[i];
			printf("%05d %d %05d\n", n.address, n.value, ans[i + 1].address);
		}

		printf("%05d %d -1", ans.back().address, ans.back().value);
	}
	//system("pause");
	return 0;
}