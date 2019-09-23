#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

#define maxn 1005

int n;

struct node{
    vector<int> hobbies;
} N[maxn];

int S[maxn] = {-1};

int Find(int r){
    if (S[r] < 0) return r;
    else return S[r] = Find(S[r]);
}

void Union(int root1, int root2){
    int real_r1, real_r2;
    real_r1 = Find(root1);
    real_r2 = Find(root2);

    if (real_r1 == real_r2) return;

    // union to root1
    S[real_r1] += S[real_r2];
    S[real_r2] = real_r1;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d:", &num);

        for (int index = 0; index < num; index++){
            int v;
            scanf("%d", &v);
            N[i].hobbies.push_back(v);
        }
    }

    fill(S, S + maxn, -1);
    for (int i = 0; i < n; i++){
        node n = N[i];
        if (n.hobbies.size() != 1){
            for (int index = 0; index < n.hobbies.size() - 1; index++){
                Union(n.hobbies[index], n.hobbies[index + 1]);
            }
        }
    }

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++){
        node n = N[i];
        m[Find(n.hobbies.front())] += 1;
    }

    vector<int> vec;
    for (auto v : m) vec.push_back(v.second);

    sort(vec.begin(), vec.end(), [](int& a, int& b){
        return a > b;
    });

    cout << vec.size() <<endl;

    for (int i = 0; i < vec.size(); i++){
        if (i == 0) cout <<vec[i];
        else cout << " " << vec[i];
    }
    return 0;
}
