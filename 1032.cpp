#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define maxn 100005

struct node {
    int s;
    char c;
    int n;
    bool flag = false;
};

vector<node> N;

int start1, start2, num;

int main()
{
    N.resize(maxn);
    
    cin >> start1 >> start2 >> num;
    
    int cnt = 0;
    for (int i = 0; i < num; i++){
        int s1, s2;
        char c; scanf("%d %c %d", &s1, &c, &s2);
        if (s2 == -1) cnt++;
        node& n = N[s1]; n.s = s1; n.c = c; n.n = s2;
    }
    
    
    while (start1 != -1) {
        N[start1].flag = true;
        start1 = N[start1].n;
    }
    
    while (start2 != -1) {
        if (N[start2].flag) {
            printf("%05d", start2);
            return 0;
        }
        start2 = N[start2].n;
    }
    
    cout << "-1";
    
    
    return 0;
}
