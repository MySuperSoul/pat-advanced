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

#define maxn 100005
struct node{
    int addr;
    int value;
    int next = -1;
} N[maxn];

int start_addr, n;

void OutputList(vector<node>& ans){
    if (ans.empty()) return;
    if (ans.size() == 1){
        printf("%05d %d -1\n", ans.front().addr, ans.front().value);
    }else {
        for (int i = 0; i < ans.size() - 1; i++){
            printf("%05d %d %05d\n", ans[i].addr, ans[i].value, ans[i + 1].addr);
        }
        printf("%05d %d -1\n", ans.back().addr, ans.back().value);
    }
}

int main()
{
    cin >> start_addr >> n;

    for (int i = 0; i < n; i++){
        int s, v, e;
        scanf("%d %d %d", &s, &v, &e);
        node& n = N[s];
        n.addr = s;
        n.value = v;
        n.next = e;
    }

    int tmp = start_addr;
    vector<node> node_vec;

    while(tmp != -1) {
        node_vec.push_back(N[tmp]);
        tmp = N[tmp].next;
    }

    vector<node> goods;
    vector<node> bads;
    unordered_set<int> s;

    for (auto v : node_vec){
        int absvalue = abs(v.value);
        if (s.find(absvalue) != s.end()) bads.push_back(v);
        else {
            goods.push_back(v);
            s.insert(absvalue);
        }
    }

    OutputList(goods);
    OutputList(bads);
    return 0;
}
