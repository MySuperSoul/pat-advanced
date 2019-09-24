#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

map<int, double> m;

int main()
{
    int k1;
    scanf("%d", &k1);
    
    for (int i = 0; i < k1; i++){
        int p;
        double e;
        scanf("%d %lf", &p, &e);
        m[p] += e;
    }
    
    scanf("%d", &k1);
    
    for (int i = 0; i < k1; i++){
        int p;
        double e;
        scanf("%d %lf", &p, &e);
        m[p] += e;
    }
    
    vector<pair<int, double>> vec;
    
    for (auto s : m){
        if (s.second != 0)  vec.push_back(make_pair(s.first, s.second));
    }
    
    cout << vec.size();
    sort(vec.begin(), vec.end(), [](pair<int, double>& a, pair<int, double>& b){
        return a.first > b.first;
    });
    
    for (auto i : vec){
        cout << " " << i.first << " ";
        printf("%.1f", i.second);
    }
    return 0;
}
