#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define maxn 505

int cmax, n, sp, m;

int bikes[maxn];

struct node {
    int id, cost = 0;
    vector<int> prev;
    bool operator< (const node& a) const{
        return cost > a.cost;
    }
};

struct edge {
    int to, c;
};

vector<edge> G[maxn];
node N[maxn];
int visit[maxn];
int dis[maxn];

void djfunc()
{
    priority_queue<node> node_queue;
    node_queue.push(N[0]);
    
    while (!node_queue.empty()) {
        node n = node_queue.top(); node_queue.pop();
        if (visit[n.id]) continue;
        visit[n.id] = 1;
        
        for (int i = 0; i < G[n.id].size(); i++){
            edge e = G[n.id][i];
            int to = e.to;
            node& adj = N[to];
            node& thi = N[n.id];
            
            if (dis[thi.id] + e.c < dis[adj.id]){
                dis[adj.id] = dis[thi.id] + e.c;
                adj.cost = dis[adj.id];
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
int minneed = 1000000, minback = 1000000;

void dfs(int root){
    if (root == 0){
        ans.push_back(root);
        int need = 0, back = 0;
        
        for (int i = ans.size() - 2; i >= 0; i--){
            int id = ans[i];
            int tmp = bikes[id] - (cmax / 2);
            if (tmp > 0){
                back += tmp; // 不能往回送
            } else{
                tmp = abs(tmp);
                if (back > tmp){
                    back -= tmp;
                }else{
                    need += (tmp - back);
                    back = 0;
                }
            }
        }
        if (need < minneed){
            minneed = need;
            minback = back;
            result = ans;
        }else if (need == minneed && back < minback){
            minback = back;
            result = ans;
        }
        ans.pop_back();
        return;
    }else{
        ans.push_back(root);
        for (int i = 0; i < N[root].prev.size(); i++){
            dfs(N[root].prev[i]);
        }
        ans.pop_back();
    }
}

int main()
{
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &bikes[i]);
    for (int i = 0; i < m; i++){
        int v1, v2, c;
        scanf("%d %d %d", &v1, &v2, &c);
        N[v1].id = v1; N[v2].id = v2;
        G[v1].push_back(edge{v2, c}); G[v2].push_back(edge{v1, c});
    }
    
    fill(dis, dis + maxn, 1000000);
    dis[0] = 0;
    
    djfunc();
    
    dfs(sp);
    
    cout << minneed << " ";
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++){
        if (i == 0) cout << result[i];
        else cout << "->" << result[i];
    }
    cout << " " << minback;
    return 0;
}
