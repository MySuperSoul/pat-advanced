#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

map<int, double> m;
struct node {
    int p;
    double e;
};

vector<node> v1, v2;

int main()
{
    int num;
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++){
        node n;
        scanf("%d %lf", &n.p, &n.e);
        v1.push_back(n);
    }
    
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++){
        node n;
        scanf("%d %lf", &n.p, &n.e);
        v2.push_back(n);
    }
    
    for (auto s1 : v1){
        for (auto s2 : v2){
            m[s1.p + s2.p] += s1.e * s2.e;
        }
    }
    
    vector<node> result;
    for (auto iter : m){
        if (iter.second != 0.0){
            result.push_back(node{iter.first, iter.second});
        }
    }
    
    sort(result.begin(), result.end(), [](node& a, node& b){
        return a.p > b.p;
    });
    
    cout << result.size();
    
    for (auto v : result){
        cout << " " << v.p << " ";
        printf("%.1f", v.e);
    }
    return 0;
}
