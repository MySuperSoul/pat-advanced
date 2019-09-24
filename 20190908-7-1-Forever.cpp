#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n;

int gcd(int m, int n){
    return n == 0 ? m : gcd(n, m % n);
}

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> findfactor(int n){
    vector<int> v;
    
    for (int i = 1; i < n; i++){
        int common = gcd(i, n);
        if (is_prime(common) && common != 2 && (n - i + 1) % 9 == 0){
            v.push_back(i);
        }
    }
    return v;
}

vector<int> ans;
vector<vector<int>> result;

void dfs(int tempk, int tempsum, int k, int sum){
    if (tempsum > sum) return;
    if (tempk == k){
        if (tempsum != sum) return;
        else if (ans.back() == 9) return;
        else result.push_back(ans);
        return;
    }
    
    for (int i = 0; i <= 9; i++){
        ans.push_back(i);
        dfs(tempk + 1, tempsum + i, k, sum);
        ans.pop_back();
    }
}

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int k, m;
        scanf("%d %d", &k, &m);
        vector<int> factor = findfactor(m);
        
        cout << "Case " << i << endl;
        if (factor.empty()) cout << "No Solution\n";
        else if (k * 9 < m) cout << "No Solution\n";
        else{
            for (auto value : factor){
                result.clear(); ans.clear();
                int numofnine = (m - value + 1) / 9;
                int sum = m - numofnine * 9;
                int frontk = k - numofnine;
                
                int tempk = 0, tempsum = 0;
                for (int i = 1; i <= 9; i++){
                    tempk += 1;
                    tempsum += i;
                    ans.push_back(i);
                    
                    dfs(tempk, tempsum, frontk, sum);
                    
                    ans.pop_back();
                    tempsum -= i;
                    tempk -= 1;
                }
                
                for (auto vec : result){
                    cout << value << " ";
                    for (auto t : vec) cout << t;
                    for (int t = 0; t < numofnine; t++) cout << "9";
                    cout << endl;
                }
            }
        }
    }
    return 0;
}