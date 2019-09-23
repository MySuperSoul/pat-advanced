#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> ans;
    ans.resize(n);
    
    for (int i = 0; i < n; i++) scanf("%d", &ans[i]);
    
    sort(ans.begin(), ans.end(), [](int& a, int& b){
        return a > b;
    });
    
    int result;
    int i;
    for (i = 0; i < ans.size(); i++){
        if (ans[i] <= i + 1){
            result = i;
            break;
        }
        
        if (i == ans.size() - 1) result = i + 1;
    }
    
    cout << result;
    return 0;
}
