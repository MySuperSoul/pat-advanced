#include <bits/stdc++.h>
#include <cstdio>

#define maxn 20000

using namespace std;

bool is_prime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int find_next_prime(int n){
    if (is_prime(n)) return n;
    
    for (int i = n; ;i++){
        if (is_prime(i)) return i;
    }
}

int msize, n, m;
int Table[maxn];

int main()
{
    cin >> msize >> n >> m;
    msize = find_next_prime(msize);
    
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        
        int position = v % msize;
        bool flag = false;
        for (int index = 0; index <= msize; index++){
            int real_pos = (position + static_cast<int>(pow(index, 2))) % msize;
            if (Table[real_pos] == 0){
                Table[real_pos] = v;
                flag = true;
                break;
            }
        }
        
        if (!flag) printf("%d cannot be inserted.\n", v);
    }
    
    int cnt = 0;
    for (int i = 0; i < m; i++){
        int q;
        scanf("%d", &q);
        
        int position = q % msize;
        for (int index = 0; index <= msize; index++){
            int real_pos = (position + static_cast<int>(pow(index, 2))) % msize;
            if (Table[real_pos] == q){
                cnt++;
                break;
            }else if (Table[real_pos] == 0){
                cnt++;
                break;
            }else cnt++;
        }
    }
    
    printf("%.1f", (double)(cnt * 1.0 / m));
    return 0;
}
