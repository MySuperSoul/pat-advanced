#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define maxn 10005

int visit[maxn];
int graph[maxn][maxn];
int level[maxn];

int maxlevel = -1;
int num;

void dfs(int root){
    visit[root] = 1;
    
    for (int i = 1; i <= num; i++){
        if (visit[i] == 0 && graph[i][root] == 1) dfs(i);
    }
}

void dfffs(int root){
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int id = q.front(); q.pop();
        if (visit[id] == 1) continue;
        visit[id] = 1;
        maxlevel = max(maxlevel, level[id]);
        
        for (int i = 1; i <= num; i++){
            if (visit[i] == 0 && graph[i][id] != 0){
                level[i] = level[id] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> num;
    for (int i = 0; i < num - 1; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    
    int cnt = 0;
    for (int i = 1; i <= num; i++){
        if (visit[i] == 0){
            cnt++;
            dfs(i);
        }
    }
    
    if (cnt > 1) {
        printf("Error: %d components", cnt);
    }else{
        int reallevel = -1;
        vector<int> ans;
        for (int i = 1; i <= num; i++){
            fill(visit, visit + num + 3, 0);
            fill(level, level + num + 3, 0);
            maxlevel = -1;
            level[i] = 0;
            dfffs(i);
            
            if (maxlevel > reallevel){
                ans.clear();
                reallevel = maxlevel;
                ans.push_back(i);
            }else if (maxlevel == reallevel){
                ans.push_back(i);
            }
        }
        
        for (auto v : ans) cout << v << endl;
    }
    return 0;
}
