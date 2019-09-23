#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n;
int couple[100005];

int main(){
    cin >> n;
    
    fill(couple, couple + 100005, -1);
    for (int i = 0; i < n; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        couple[v1] = v2;
        couple[v2] = v1;
    }
    
    int q;
    cin >> q;
    
    unordered_set<int> s;
    
    for (int i = 0; i < q; i++){
        int query;
        scanf("%d", &query);
        s.insert(query);
    }
    
    set<int> ans;
    
    for (auto v : s){
        if (couple[v] == -1) ans.insert(v);
        else {
            if (s.find(couple[v]) == s.end()) ans.insert(v);
        }
    }
    
    cout << ans.size() << endl;
    for (auto iter = ans.begin(); iter != ans.end(); iter++){
        if (iter == ans.begin()) printf("%05d", (*iter));
        else printf(" %05d", (*iter));
    }
    return 0;
}
