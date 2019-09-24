#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define maxn 1005
int n, m, k;

int visit[maxn];
int graph[maxn][maxn];

void dfs(int root){
    visit[root] = 1;
    for (int i = 1; i <= n; i++){
        if (!visit[i] && graph[i][root] != 0) dfs(i);
    }
}

int main()
{
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    
    for (int i = 0; i < k; i++){
        int q;
        scanf("%d", &q);
        
        fill(visit, visit + maxn, 0);
        visit[q] = 1;
        
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!visit[i]){
                cnt++;
                dfs(i);
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}
