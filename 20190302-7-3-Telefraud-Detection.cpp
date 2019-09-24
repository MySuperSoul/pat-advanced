#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
#define maxn 1005

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

struct node {
    int to, total = 0;
    bool valid = true;
    
    void judge(){
        if (total > 5){
            valid = false;
        }
    }
};

int k, n, m;

map<int, node> callmap[maxn];
int hascall[maxn][maxn];
int callback[maxn][maxn];

vector<int> ans;
void findsuspects(){
    for (int i = 1; i <= n; i++){
        int tmp = 0, back = 0;
        for (auto v : callmap[i]){
            if (v.second.valid){
                tmp++;
                if (callback[v.second.to][i] == 1) back++;
            }
        }
        
        if (tmp <= k) continue;
        if (back * 1.0 / tmp > 0.2) continue;
        
        ans.push_back(i);
    }
}

int S[maxn];

int Find(int root){
    if (S[root] <= -1) return root;
    else return S[root] = Find(S[root]);
}

void Union(int root1, int root2){
    int realroot1, realroot2;
    realroot1 = Find(root1);
    realroot2 = Find(root2);
    
    if (realroot1 == realroot2) return;
    if (realroot1 < realroot2) // union to root1
    {
        S[realroot1] += S[realroot2];
        S[realroot2] = realroot1;
    }else{
        Union(root2, root1);
    }
}

void findgang()
{
    for (int i = 0; i < ans.size(); i++){
        for (int j = i + 1; j < ans.size(); j++){
            if (hascall[ans[i]][ans[j]] == 1 && hascall[ans[j]][ans[i]] == 1) Union(ans[i], ans[j]);
        }
    }
}

int main()
{
    cin >> k >> n >> m;
    
    for (int i = 0; i < m; i++){
        int v1, v2, time;
        scanf("%d %d %d", &v1, &v2, &time);
        if (time > 1440) continue;
        callmap[v1][v2].to = v2;
        callmap[v1][v2].total += time;
        callmap[v1][v2].judge();
        hascall[v1][v2] = 1;
        callback[v1][v2] = 1;
    }
    
    findsuspects();
    
    if (ans.empty()) {
        cout << "None";
        return 0;
    }
    
    fill(S, S + n + 1, -1);
    
    findgang();
    
    vector<int> result[n + 1];
    
    for (auto v : ans){
        result[Find(v)].push_back(v);
    }
    
    for (int i = 1; i <= n; i++){
        if (!result[i].empty()){
            sort(result[i].begin(), result[i].end());
            for (int j = 0; j < result[i].size(); j++){
                if (j == 0) cout << result[i][j];
                else cout << " " << result[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}