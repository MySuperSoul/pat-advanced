#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define maxn 505

struct node {
    int id, distance = 0;
    vector<int> prev;
    
    bool operator< (const node& a) const{
        return distance > a.distance;
    }
};

struct edge {
    int to, c;
};

vector<edge> G[maxn];
node N[maxn];
int dis[maxn];
int visit[maxn];
int cost[maxn][maxn];

int n, m, s, d;
int mincost = 10000000;

void djfunc()
{
    priority_queue<node> node_queue;
    node_queue.push(N[s]);
    
    while (!node_queue.empty()) {
        node n = node_queue.top(); node_queue.pop();
        if (visit[n.id] == 1) continue;
        visit[n.id] = 1;
        
        for (int i = 0; i < G[n.id].size(); i++){
            edge e = G[n.id][i];
            int to = e.to;
            node& adj = N[to];
            node& thi = N[n.id];
            
            if (dis[thi.id] + e.c < dis[adj.id]){
                dis[adj.id] = dis[thi.id] + e.c;
                adj.distance = dis[adj.id];
                adj.prev.clear();
                adj.prev.push_back(thi.id);
                node_queue.push(adj);
            }else if (dis[thi.id] + e.c == dis[adj.id]){
                adj.prev.push_back(thi.id);
                node_queue.push(adj);
            }
        }
    }
}

vector<int> result, ans;
void dfs(int root){
    ans.push_back(root);
    
    if (root == s){
        int totalc = 0;
        for (int i = 1; i < ans.size(); i++){
            totalc += cost[ans[i]][ans[i - 1]];
        }
        if (totalc < mincost){
            mincost = totalc;
            result = ans;
        }
        ans.pop_back();
        return;
    }else{
        for (int i = 0; i < N[root].prev.size(); i++){
            dfs(N[root].prev[i]);
        }
    }
    ans.pop_back();
}

int main()
{
    cin >> n >> m >> s >> d;
    
    for (int i = 0; i < m; i++){
        int v1, v2, di, c;
        scanf("%d %d %d %d", &v1, &v2, &di, &c);
        N[v1].id = v1; N[v2].id = v2;
        cost[v1][v2] = cost[v2][v1] = c;
        G[v1].push_back(edge{v2, di}); G[v2].push_back(edge{v1, di});
    }
    
    fill(dis, dis + n + 3, 1000000);
    dis[s] = 0;
    
    djfunc();
    
    dfs(d);
    
    reverse(result.begin(), result.end());
    
    for (auto v : result) cout << v << " ";
    cout << dis[d] << " " << mincost;
    return 0;
}
