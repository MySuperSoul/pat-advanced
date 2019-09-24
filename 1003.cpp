#include <iostream>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

const int Max = 1000000;
const int maxn = 505;

struct node {
    int id, cost = 0, weight = 0, num = 1;
    bool operator< (const node& n) const{
        return cost > n.cost;
    }
};

struct edge {
    int to, c;
};

node N[maxn];
int visit[maxn];
int dis[maxn];
int weight[maxn];
vector<edge> Graph[maxn];
int n, m, c1, c2;

void djfunc(){
    priority_queue<node> node_queue;
    node_queue.push(N[c1]);
    
    while (!node_queue.empty()) {
        node n = node_queue.top(); node_queue.pop();
        if (visit[n.id]) continue;
        
        visit[n.id] = 1;
        
        for (int i = 0; i < Graph[n.id].size(); i++){
            node& adj = N[Graph[n.id][i].to];
            edge e = Graph[n.id][i];
            
            if (dis[n.id] + e.c < dis[e.to]){
                dis[e.to] = dis[n.id] + e.c;
                adj.cost = dis[e.to];
                adj.weight = N[n.id].weight + weight[adj.id];
                adj.num = N[n.id].num;
                node_queue.push(adj);
            }else if (dis[n.id] + e.c == dis[e.to]){
                adj.num += N[n.id].num;
                if (N[n.id].weight + weight[adj.id] > adj.weight){
                    adj.weight = N[n.id].weight + weight[adj.id];
                }
                node_queue.push(adj);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> c1 >> c2;
    
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    for (int i = 0; i < m; i++){
        int v1, v2, l;
        scanf("%d %d %d", &v1, &v2, &l);
        Graph[v1].push_back(edge{v2, l});
        N[v1].id = v1;
        Graph[v2].push_back(edge{v1, l});
        N[v2].id = v2;
    }
    
    // initial state
    std::fill(dis, dis + maxn, Max);
    dis[c1] = 0;
    N[c1].weight = weight[c1];
    
    djfunc();
    
    cout << N[c2].num<< " " << N[c2].weight;
    return 0;
}
