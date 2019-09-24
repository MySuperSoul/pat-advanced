#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int findnext(int n){
    for (int i = n + 1; ; i++){
        if (is_prime(i)){
            if (is_prime(i - 6) || is_prime(i + 6)){
                return i;
            }
        }else {
            continue;
        }
    }
}

int main()
{
    int num;
    cin >> num;
    
    if (is_prime(num)){
        if (is_prime(num - 6)){
            cout << "Yes\n" << num - 6;
        }else if (is_prime(num + 6)){
            cout << "Yes\n" << num + 6;
        }else{
            cout << "No" << endl;
            cout << findnext(num);
        }
    }else{
        cout << "No" << endl;
        cout << findnext(num);
    }
    return 0;
}