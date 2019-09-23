#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define maxn 10005
int S[maxn];

int n;

int Find(int root){
    if (S[root] < 0) return root;
    else return S[root] = Find(S[root]);
}

void Union(int r1, int r2){
    int real_r1 = Find(r1);
    int real_r2 = Find(r2);
    
    // r2 to r1
    S[real_r1] += S[real_r2];
    S[real_r2] = real_r1;
}

int main(){
    fill(S, S + maxn, -1);
    cin >> n;
    
    unordered_set<int> birds;
    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        vector<int> ans;
        ans.resize(num);
        
        for (int index = 0; index < num; index++) {
            scanf("%d", &ans[index]);
            birds.insert(ans[index]);
        }
        for (int index = 0; index < ans.size() - 1; index++) Union(ans[index], ans[index + 1]);
    }
    
    int trees = 0;
    for (auto v : birds){
        if (S[v] < 0) trees++;
    }
    
    printf("%d %d\n", trees, birds.size());
    
    // for query
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        if (Find(v1) == Find(v2)) printf("Yes\n");
        else cout << "No" << endl;
    }
    return 0;
}
