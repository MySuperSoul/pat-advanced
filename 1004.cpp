#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct node {
    vector<string> childs;
    bool has_child = false;
    int level = 0;
};

node N[200];
map<int, int> level_node_map;
int max_level = -1;

int n, m;

void mark(string root){
    node& n = N[stoi(root)];
    if (n.has_child == false) level_node_map[n.level] += 1;
    
    max_level = max(max_level, n.level);
    for (int i = 0; i < n.childs.size(); i++){
        N[stoi(n.childs[i])].level = n.level + 1;
        mark(n.childs[i]);
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        string root, s;
        int num;
        cin >> root >> num;
        int root_pos = stoi(root);
        N[root_pos].has_child = true;
        for (int j = 0; j < num; j++){
            cin >> s;
            N[root_pos].childs.push_back(s);
        }
    }
    
    mark("01");
    
    for (int i = 0; i <= max_level; i++){
        if (i == 0) cout << level_node_map[i];
        else cout << " " << level_node_map[i];
    }
    return 0;
}
