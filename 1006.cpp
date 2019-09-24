#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct node {
    string id;
    int signin, signout;
};

bool cmp1(node& a, node& b){
    return a.signin < b.signin;
}

bool cmp2(node& a, node& b){
    return a.signout > b.signout;
}

int tosecond(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

int main()
{
    int n;
    cin >> n;
    
    vector<node> vec;
    for (int i = 0; i < n; i++){
        node n;
        int hh1, mm1, ss1, hh2, mm2, ss2;
        cin >> n.id;
        scanf("%d:%d:%d %d:%d:%d", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
        n.signin = tosecond(hh1, mm1, ss1);
        n.signout = tosecond(hh2, mm2, ss2);
        vec.push_back(n);
    }
    
    sort(vec.begin(), vec.end(), cmp1);
    cout << vec.front().id << " ";
    sort(vec.begin(), vec.end(), cmp2);
    cout << vec.front().id;
    return 0;
}
