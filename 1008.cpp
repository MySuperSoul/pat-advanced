#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int sum_up = 0, sum_down = 0;

int main()
{
    int n;
    cin >> n;
    
    vector<int> ans;
    
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        ans.push_back(v);
    }
    
    sum_up += ans.front();
    
    for (int i = 1; i < ans.size(); i++){
        if (ans[i] > ans[i - 1]) sum_up += ans[i] - ans[i - 1];
        else sum_down += ans[i - 1] - ans[i];
    }
    
    int result = sum_up * 6 + sum_down * 4 + n * 5;
    cout << result;
    return 0;
}
