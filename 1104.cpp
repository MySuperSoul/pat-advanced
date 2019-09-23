#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

typedef long long ll;
ll n;
vector<double> ans;

int main()
{
    scanf("%lld", &n);

    double result = 0.0;
    for (ll i = 1; i <= n; i++){
        double v;
        scanf("%lf", &v);
        result += i * (n - i + 1) * v;
    }

    printf("%.2f", result);
    return 0;
}
