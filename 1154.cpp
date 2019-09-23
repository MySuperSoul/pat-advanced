#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// dfs, bfs, dp, union-find, binary-search, heap, queue, priority_queue, tree
struct edge {
    int v1, v2;
};

vector<edge> edge_vec;
vector<int> vec;

int n, m;

int main()
{
    cin >> n >> m;
    vec.resize(n);
    
    for (int i = 0; i < m; i++){
        edge e;
        scanf("%d %d", &e.v1, &e.v2);
        edge_vec.push_back(e);
    }
    
    int num;
    cin >> num;
    
    set<int> s;
    for (int i = 0; i < num; i++){
        s.clear();
        bool flag = true;
        for (int index = 0; index < n; index++){
            scanf("%d", &vec[index]);
            s.insert(vec[index]);
        }
        
        for (auto e : edge_vec){
            if (vec[e.v1] == vec[e.v2]){
                flag = false;
                break;
            }
        }
        
        if (flag) printf("%d-coloring\n", s.size());
        else cout << "No" << endl;
    }
    return 0;
}
