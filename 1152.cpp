#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// dfs, bfs, dp, union-find, binary-search, heap, queue, priority_queue, tree

int l, k;
bool flag = false;

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> l >> k;
    
    string s;
    cin >> s;
    
    for (int i = 0; i <= l - k; i++){
        int temp = stoi(s.substr(i, k));
        if (is_prime(temp)){
            cout << s.substr(i, k);
            flag = true;
            break;
        }
    }
    
    if (!flag) cout << "404";
    return 0;
}
