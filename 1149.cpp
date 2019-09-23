#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 100005
map<int, vector<int>> Goods;

int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        Goods[v1].push_back(v2);
        Goods[v2].push_back(v1);
    }
    
    for (int i = 0; i < m; i++){
        int num;
        scanf("%d", &num);
        
        unordered_set<int> s;
        bool flag = true;
        for (int index = 0; index < num; index++){
            int temp;
            scanf("%d", &temp);
            s.insert(temp);
        }
        
        for (auto v : s){
            if (Goods[v].empty()) continue;
            for (auto t : Goods[v]){
                if (s.find(t) != s.end()){
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
