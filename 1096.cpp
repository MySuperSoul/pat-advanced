#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

typedef long long ll;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

void OutputForVector(vector<int>& ans){
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
}

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 0; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

set<ll> ans;

ll n;

void FindFactors(){
    for (ll i = 2; i <= sqrt(n); i++){
        if (n % i == 0) {
            ans.insert(i);
            ans.insert(n / i);
        }
    }
}

int main()
{
    cin >> n;

    int maxn = -1;
    int start = 0, e = 0;
    for (int i = 2; i <= sqrt(n); i++){
        ll result = i;
        for (int j = i; j <= sqrt(n); ){
            if (n % result != 0) break;
            if (n % result == 0 && j - i + 1 > maxn){
                maxn = j - i + 1;
                start = i;
                e = j;
            }
            j++;
            result *= j;
        }
    }

    if (maxn == -1) cout << 1 << endl << n;
    else{
    cout << maxn << endl;
    for (int i = start; i <= e; i++){
        if (i == start) cout << i;
        else cout << "*" <<i;
    }
    }
    return 0;
}
