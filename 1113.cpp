#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
typedef long long ll;

int n;
int main()
{
    cin >> n;
    vector<int> ans;
    ans.resize(n);

    for (int i = 0; i < n; i++){
        scanf("%d", &ans[i]);
    }

    int nn;
    nn = n % 2;

    sort(ans.begin(), ans.end());

    ll result1 = 0;
    ll result2 = 0;
    int half = n / 2;

    for (int i = 0; i < ans.size(); i++){
        if (i < half){
            result1 += ans[i];
        }else {
            result2 += ans[i];
        }
    }

    ll result = result2 - result1;

    printf("%d %lld", nn, result);
    return 0;
}
