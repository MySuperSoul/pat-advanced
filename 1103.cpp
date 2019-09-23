#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

int table[100000];
int cnt = 1;

int n, k, p;

void GetTable()
{
    for (cnt = 1; ; cnt++){
        int tmp = 1;
        for (int i = 0; i < p; i++) tmp *= cnt;
        if (tmp > n) break;
        else table[cnt] = tmp;
    }
}

vector<vector<int>> result;
vector<int> ans;

void dfs(int tmpk, int tmpsum, int last){
    if (tmpsum > n) return;
    if (tmpsum == n && tmpk != k) return;
    if (tmpk == k){
        if (tmpsum != n) return;
        if (tmpsum == n) {
            result.push_back(ans);
            return;
        }
    }

    for (int i = last; i >= 1; i--){
        ans.push_back(i);
        dfs(tmpk + 1, tmpsum + table[i], i);
        ans.pop_back();
    }
}

int main()
{
    cin >> n >> k >> p;

    GetTable();
    dfs(0, 0, cnt - 1);

    sort(result.begin(), result.end(), [](vector<int>& a, vector<int>& b){
        int suma = accumulate(a.begin(), a.end(), 0);
        int sumb = accumulate(b.begin(), b.end(), 0);
        if (suma == sumb){
            for (int i = 0; i < a.size(); i++){
                if (a[i] != b[i]){
                    if (a[i] > b[i]) return true;
                    else return false;
                }
            }
        }else {
            return suma > sumb;
        }
    });

    if (result.empty()){
        cout << "Impossible";
    }else {
        auto v = result.front();
        printf("%d =", n);

        for (int i = 0; i < v.size(); i++){
            if (i == 0) printf(" %d^%d", v[i], p);
            else printf(" + %d^%d", v[i], p);
        }
    }
    return 0;
}
