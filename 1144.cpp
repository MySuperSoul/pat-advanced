#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n;
vector<int> vec;

int main()
{
    cin >> n;
    vec.resize(n + 5);
    fill(vec.begin(), vec.end(), 0);
    
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        if (v <= 0 || v > n + 1) continue;
        else vec[v] = 1;
    }
    
    for (int i = 1; i < vec.size(); i++){
        if (vec[i] == 0){
            cout << i;
            break;
        }
    }
    return 0;
}
