#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

#define maxn 505
#define maxinf 100000

struct node {
    int id, cost = 0, time = 0;
    vector<int> pre_cost;
    vector<int> pre_time;
} N[maxn];

struct cmp1 {
    bool operator() (node& a, node& b){
        return a.cost > b.cost;
    }
};

struct cmp2 {
    bool operator() (node& a, node& b){
        return a.time > b.time;
    }
};

struct edge {
    int to, c, t;
};

vector<edge> G[maxn];
int graph[maxn][maxn];
int dis[maxn];
int Time[maxn];
int visit[maxn];

int n, m;

void djfunc1(int q1){
    priority_queue<node, vector<node>, cmp1> node_queue;
    node_queue.push(N[q1]);
    
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
                adj.pre_cost.clear();
                adj.pre_cost.push_back(thi.id);
                node_queue.push(adj);
            }else if (dis[thi.id] + e.c == dis[adj.id]){
                adj.pre_cost.push_back(thi.id);
                node_queue.push(adj);
            }
        }
    }
}

void djfunc2(int q1){
    priority_queue<node, vector<node>, cmp2> node_queue;
    node_queue.push(N[q1]);
    
    while (!node_queue.empty()) {
        node n = node_queue.top(); node_queue.pop();
        if (visit[n.id]) continue;
        
        visit[n.id] = 1;
        for (int i = 0; i < G[n.id].size(); i++){
            edge e = G[n.id][i];
            int to = e.to;
            
            node& adj = N[to];
            node& thi = N[n.id];
            
            if (Time[thi.id] + e.t < Time[adj.id]){
                Time[adj.id] = Time[thi.id] + e.t;
                adj.time = Time[adj.id];
                adj.pre_time.clear();
                adj.pre_time.push_back(thi.id);
                node_queue.push(adj);
            }else if (Time[thi.id] + e.t == Time[adj.id]){
                adj.pre_time.push_back(thi.id);
                node_queue.push(adj);
            }
        }
    }
}

vector<vector<int>> result1;
vector<int> ans;
vector<int> root1;

void dfs1(int q2, int q1){
    if (q2 == q1){
        ans.push_back(q2);
        result1.push_back(ans);
        ans.pop_back();
        return;
    }
    
    ans.push_back(q2);
    for (int i = 0; i < N[q2].pre_cost.size(); i++){
        dfs1(N[q2].pre_cost[i], q1);
    }
    ans.pop_back();
}

void select1(){
    int mintime = maxinf;
    for (auto v : result1){
        reverse(v.begin(), v.end());
        int this_time = 0;
        for (int i = 0; i < v.size() - 1; i++){
            this_time += graph[v[i]][v[i + 1]];
        }
        if (this_time < mintime){
            mintime = this_time;
            root1 = v;
        }
    }
}

vector<vector<int>> result2;
vector<int> ans2;
vector<int> root2;

void dfs2(int q2, int q1){
    if (q2 == q1){
        ans2.push_back(q2);
        result2.push_back(ans2);
        ans2.pop_back();
        return;
    }
    
    ans2.push_back(q2);
    for (int i = 0; i < N[q2].pre_time.size(); i++){
        dfs2(N[q2].pre_time[i], q1);
    }
    ans2.pop_back();
}

void select2(){
    int minsize = maxinf;
    for (auto v : result2){
        if (v.size() < minsize){
            minsize = v.size();
            reverse(v.begin(), v.end());
            root2 = v;
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int v1, v2, type, l, t;
        scanf("%d %d %d %d %d", &v1, &v2, &type, &l, &t);
        
        N[v1].id = v1;
        N[v2].id = v2;
        
        if (type == 0){ // double
            graph[v1][v2] = graph[v2][v1] = t;
            G[v1].push_back(edge{v2, l, t});
            G[v2].push_back(edge{v1, l, t});
        }else{ // single
            graph[v1][v2] = t;
            G[v1].push_back(edge{v2, l, t});
        }
    }
    
    int q1, q2;
    cin >> q1 >> q2;
    
    fill(visit, visit + maxn, 0);
    fill(dis, dis + maxn, maxinf);
    fill(Time, Time + maxn, maxinf);
    
    dis[q1] = 0;
    Time[q1] = 0;
    
    djfunc1(q1);
    fill(visit, visit + maxn, 0);
    djfunc2(q1);
    
    dfs1(q2, q1);
    select1();
    dfs2(q2, q1);
    select2();
    
    if (root1 == root2){
        printf("Distance = %d; Time = %d: ", N[q2].cost, N[q2].time);
        for (int i = 0; i < root1.size(); i++){
            if (i == 0) cout << root1[i];
            else printf(" -> %d", root1[i]);
        }
    }else{
        printf("Distance = %d: ", N[q2].cost);
        for (int i = 0; i < root1.size(); i++){
            if (i == 0) cout << root1[i];
            else printf(" -> %d", root1[i]);
        }
        cout << endl;
        printf("Time = %d: ", N[q2].time);
        for (int i = 0; i < root2.size(); i++){
            if (i == 0) cout << root2[i];
            else printf(" -> %d", root2[i]);
        }
    }
    return 0;
}
