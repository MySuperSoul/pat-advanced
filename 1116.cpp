#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct node {
    int rank = -1;
    bool checked = false;
} N[10005];

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int n;
int main(){
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int v;
        scanf("%d", &v);
        N[v].rank = i;
    }
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++){
        int q;
        scanf("%d", &q);
        
        if (N[q].rank == -1) printf("%04d: Are you kidding?\n", q);
        else if (N[q].checked) printf("%04d: Checked\n", q);
        else {
            if (N[q].rank == 1) printf("%04d: Mystery Award\n", q);
            else if (is_prime(N[q].rank)) printf("%04d: Minion\n", q);
            else printf("%04d: Chocolate\n", q);
            N[q].checked = true;
        }
    }
    return 0;
}
