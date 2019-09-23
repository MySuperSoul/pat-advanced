#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

int main()
{
    int n;
    cin >> n;

    vector<int> ans;
    ans.resize(n);

    for (int i = 0; i < n; i++) scanf("%d", &ans[i]);

    vector<int> tmp = ans;
    sort(tmp.begin(), tmp.end());

    vector<int> possible;
    int maxvalue = -1;

    for (int i = 0; i < tmp.size(); i++){
        if (ans[i] == tmp[i] && ans[i] > maxvalue){
            possible.push_back(ans[i]);
        }

        maxvalue = max(maxvalue, ans[i]);
    }

    sort(possible.begin(), possible.end());

    cout << possible.size() << endl;
    for (int i = 0; i < possible.size(); i++){
        if (i == 0) cout << possible[i];
        else cout << " " << possible[i];
    }
    cout << endl;

    return 0;
}
