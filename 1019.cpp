#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    int a1, a2;
    cin >> a1 >> a2;
    
    vector<int> ans;
    
    while (a1 != 0) {
        ans.push_back(a1 % a2);
        a1 /= a2;
    }
    
    int i, j;
    bool flag = true;
    for (i = 0, j = ans.size() - 1; i <= j; i++, j--){
        if (ans[i] != ans[j]) {
            flag = false;
            break;
        }
    }
    
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    reverse(ans.begin(), ans.end());
    
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return 0;
}
