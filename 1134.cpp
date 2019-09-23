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

#define maxn 10005

struct edge {
	int v1, v2;
}E[maxn];

int n, m;
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &E[i].v1, &E[i].v2);
	}

	int cases;
	cin >> cases;

	while (cases--)
	{
		int tmp;
		scanf("%d", &tmp);

		unordered_set<int> s;

		int v;
		for (int i = 0; i < tmp; i++) {
			scanf("%d", &v);
			s.insert(v);
		}

		// then loop all the edges

		bool flag = true;
		for (int i = 0; i < m; i++) {
			edge e = E[i];
			if (s.find(e.v1) == s.end() && s.find(e.v2) == s.end()) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "Yes" << endl;
		else
		{
			cout << "No" << endl;
		}
	}

	//system("pause");
	return 0;
}