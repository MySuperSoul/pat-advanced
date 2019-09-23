#include <bits/stdc++.h>
#include <cstdio>

#define maxn 1005

using namespace std;

int n, m;
vector<int> InDegree;
vector<int> Graph[maxn];

int main()
{
    cin >> n >> m;
    InDegree.resize(n + 1);
    
    for (int i = 0; i < m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        Graph[v1].push_back(v2);
        InDegree[v2]++;
    }
    
    int num;
    cin >> num;
    
    vector<int> tmp;
    vector<int> invalid;
    
    for (int i = 0; i < num; i++){
        vector<int> vec;
        for (int index = 0; index < n; index++){
            int v;
            scanf("%d", &v);
            vec.push_back(v);
        }
        
        tmp = InDegree;
        
        // to judge whether the indegree is 0 and update tmp
        for (int index = 0; index < vec.size(); index++){
            int nodeid = vec[index];
            if (tmp[nodeid] != 0){
                invalid.push_back(i);
                break;
            }
            
            for (int node = 0; node < Graph[nodeid].size(); node++){
                tmp[Graph[nodeid][node]]--;
            }
        }
    }
    
    for (int i = 0; i < invalid.size(); i++){
        if (i == 0) cout << invalid[i];
        else  cout << " " << invalid[i];
    }
    return 0;
}
