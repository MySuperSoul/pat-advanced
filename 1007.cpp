#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n;
int maxn = -100000, maxinvec = -100000;
int pos;

void findmax(vector<int>& ans){
    int temp_sum = 0;
    
    for (int i = 0; i < ans.size(); i++){
        temp_sum += ans[i];
        if (ans[i] > maxinvec) maxinvec = ans[i];
        
        if (temp_sum > maxn){
            maxn = temp_sum;
            pos = i;
        }
        
        if (temp_sum < 0) temp_sum = 0;
    }
}

int main()
{
    cin >> n;
    
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        vec.push_back(v);
    }
    
    findmax(vec);
    
    auto iter = max_element(vec.begin(), vec.end());
    if (*iter < 0){
        cout << "0 " << vec.front() << " " << vec.back();
    }else{
        int start_pos, r = 0;
        for (start_pos = pos; start_pos >= 0; start_pos--){
            r += vec[start_pos];
            if (r == maxn) break;
        }
        
        cout << maxn << " " << vec[start_pos] << " " << vec[pos];
    }
    return 0;
}
