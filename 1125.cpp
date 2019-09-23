#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

priority_queue<double, vector<double>, greater<double> > q;

int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int v;
        scanf("%d", &v);
        q.push(v);
    }
    
    while (q.size() != 1) {
        double v1 = q.top(); q.pop();
        double v2 = q.top(); q.pop();
        q.push((v1 + v2) / 2);
    }
    
    cout << int(floor(q.top()));
    return 0;
}
