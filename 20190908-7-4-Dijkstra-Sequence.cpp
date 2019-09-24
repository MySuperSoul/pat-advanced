#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;
typedef long long ll;
#define maxn 1000000

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a % b);
}

int v, e;
int visit[1005];
int dis[1005];
int graph[1005][1005];

bool djfunc(vector<int>& s){
    int source = s.front();
    int index = 1;
    dis[source] = 0;

    for (int i = 1; i <= v; i++){
        if (graph[i][source] != 0){
            dis[i] = dis[source] + graph[i][source];
        }
    }
    visit[source] = 1;
    int start = source;
    for (; ;){
        if (index == s.size()) break;
        int next = s[index++];

        // find next not visit and not maxn
        if (visit[next] == 1) return false;
        else {
            int minn = maxn;
            for (int i = 1; i <= v; i++){
                if (visit[i] == 0 && dis[i] != maxn){
                    if (dis[i] < minn) minn = dis[i];
                }
            }

            if (dis[next] != minn) return false;
            else {
                // do update
                visit[next] = 1;
                for (int i = 1; i <= v; i++){
                    if (visit[i] == 0 && graph[next][i] != 0 && dis[next] + graph[next][i] < dis[i]){
                        dis[i] = dis[next] + graph[next][i];
                    }
                }
            }
        }
    }

    return true;
}
int main()
{
    cin >> v >> e;

    for (int i = 0; i < e; i++){
        int v1, v2, c;
        scanf("%d %d %d", &v1, &v2, &c);
        graph[v1][v2] = graph[v2][v1] = c;
    }

    int k;

    cin >> k;

    for (int i = 0; i < k; i++){
        std::fill(visit, visit + v + 2, 0);
        std::fill(dis, dis + v + 2, maxn);
        vector<int> s;
        for (int j = 0;j < v; j++){
            int v1;
            scanf("%d", &v1);
            s.push_back(v1);
        }

        bool flag = djfunc(s);
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
	return 0;
}
