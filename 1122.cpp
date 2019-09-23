#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 205
int graph[maxn][maxn];

int n, m;

int main(){
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++){
        int num;
        scanf("%d", &num);
        vector<int> ans;
        ans.resize(num);
        unordered_set<int> s;
        
        for (int i = 0; i < num; i++) {
            scanf("%d", &ans[i]);
            s.insert(ans[i]);
        }
        
        if (s.size() == n && num == n + 1){
            if (ans.front() == ans.back()){
                bool flag = true;
                
                for (int i = 0; i < ans.size() - 1; i++){
                    if (graph[ans[i]][ans[i + 1]] == 0){
                        flag = false;
                        break;
                    }
                }
                
                if (!flag) cout << "NO" << endl;
                else cout << "YES" << endl;
            }else cout << "NO" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}
