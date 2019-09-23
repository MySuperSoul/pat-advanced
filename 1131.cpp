#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 10002
#define maxinf 1000000

int Graph[maxn][maxn];
struct node {
    int id, cost = 0;
    vector<int> prev;
    
    bool operator< (const node& a) const{
        return cost > a.cost;
    }
} N[maxn];

struct edge {
    int to, c = 1;
};

vector<edge> G[maxn];
int visit[maxn];
int dis[maxn];

void djfunc(int start_pos)
{
    priority_queue<node> node_queue;
    node_queue.push(N[start_pos]);
    
    while (!node_queue.empty()) {
        node n = node_queue.top(); node_queue.pop();
        if (visit[n.id]) continue;
        
        visit[n.id] = 1;
        
        for (int i = 0; i < G[n.id].size(); i++){
            edge e = G[n.id][i];
            int to  = e.to;
            node& adj = N[to];
            node& thi = N[n.id];
            
            if (dis[thi.id] + 1 < dis[adj.id]){
                dis[adj.id] = dis[thi.id] + 1;
                adj.cost = dis[adj.id];
                adj.prev.clear();
                adj.prev.push_back(thi.id);
                node_queue.push(adj);
            }else if (dis[thi.id] + 1 == dis[adj.id]){
                adj.prev.push_back(thi.id);
                node_queue.push(adj);
            }
        }
    }
}

vector<vector<int>> result;
vector<int> ans;

void dfs(int position, int start_p){
    if (position == start_p){
        ans.push_back(start_p);
        result.push_back(ans);
        ans.pop_back();
        return;
    }
    
    ans.push_back(position);
    for (int i = 0; i < N[position].prev.size(); i++){
        dfs(N[position].prev[i], start_p);
    }
    ans.pop_back();
}

int main(){
    int n;
    cin >> n;
    
    // i is line i
    for (int i = 1; i <= n; i++){
        int num;
        scanf("%d", &num);
        vector<int> vec;
        vec.resize(num);
        
        for (int index = 0; index < num; index++) {
            scanf("%d", &vec[index]);
            N[vec[index]].id = vec[index];
        }
        // assign to graph and edges
        
        for (int index = 0; index < vec.size() - 1; index++){
            Graph[vec[index]][vec[index + 1]] = i;
            Graph[vec[index + 1]][vec[index]] = i;
            G[vec[index]].push_back(edge{vec[index + 1], 1});
            G[vec[index + 1]].push_back(edge{vec[index], 1});
        }
    }
    
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        fill(dis, dis + maxn, maxinf);
        dis[v1] = 0;
        N[v1].cost = 0;
        fill(visit, visit + maxn, 0);
        
        djfunc(v1);
        
        result.clear();
        ans.clear();
        
        dfs(v2, v1);
        
        int mintransfer = maxinf;
        vector<int> f_result;
        
        for (auto v : result){
            int cnt = 0; int current_line = Graph[v[0]][v[1]];
            for (int i = 0; i < v.size() - 1; i++){
                int line = Graph[v[i]][v[i + 1]];
                if (line != current_line){
                    current_line = line;
                    cnt++;
                }
            }
            
            if (cnt < mintransfer){
                mintransfer = cnt;
                f_result = v;
            }
        }
        
        cout << N[v2].cost << endl;
        
        reverse(f_result.begin(), f_result.end());
        int current_line = Graph[f_result[0]][f_result[1]];
        int transfer_site = f_result[0];
        
        for (int i = 0; i < f_result.size() - 1; i++){
            int line = Graph[f_result[i]][f_result[i + 1]];
            if (line != current_line){
                printf("Take Line#%d from %04d to %04d.\n", current_line, transfer_site, f_result[i]);
                current_line = line;
                transfer_site = f_result[i];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", current_line, transfer_site, f_result.back());
    }
    return 0;
}
