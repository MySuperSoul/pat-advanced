#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

#define maxn 100005

int n;
double price;
double rate;

struct node{
    int id;
    int level = 0;
    bool leaf = false;
    vector<int> childs;
}N[maxn];

vector<int> leafs;

void mark_level(){
    queue<int> ans;
    ans.push(0);

    while(!ans.empty()){
        int current_root = ans.front(); ans.pop();
        for (int i = 0; i < N[current_root].childs.size(); i++){
            int child = N[current_root].childs[i];
            N[child].level = N[current_root].level + 1;
            ans.push(child);
        }
    }
}

int main()
{
    cin >> n >> price >> rate;

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        N[i].id = i;
        if (num == 0) {
            N[i].leaf = true;
            leafs.push_back(i);
        }

        for (int index = 0; index < num; index++){
            int v;
            scanf("%d", &v);
            N[i].childs.push_back(v);
        }
    }

    mark_level();

    vector<int> levels;
    for (auto v : leafs) levels.push_back(N[v].level);

    auto iter = min_element(levels.begin(), levels.end());
    int minlevel = *iter;

    int count_num = count(levels.begin(), levels.end(), minlevel);

    double result = price * pow(1 + rate / 100, minlevel);

    printf("%.4f %d", result, count_num);

    return 0;
}
