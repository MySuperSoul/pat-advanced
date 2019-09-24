#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;

vector<ll> v1, v2;

int main()
{
    int num;
    cin >> num;
    
    v1.resize(num);
    for (int i = 0; i < num; i++) scanf("%lld", &v1[i]);
    
    cin >> num;
    v2.resize(num);
    for (int i = 0; i < num; i++) scanf("%lld", &v2[i]);
    
    int pos1 = 0, pos2 = 0;
    ll pos;
    int total = v1.size() + v2.size();
    int median;
    if (total % 2 == 1) median = (total + 1) / 2;
    else median = total / 2;
    
    int cnt = 0;
    while (true) {
        for (; v1[pos1] <= v2[pos2] && pos1 < v1.size(); pos1++){
            cnt++;
            if (cnt == median){
                pos = v1[pos1];
                break;
            }
        }
        
        if (cnt == median) break;
        
        if (pos1 == v1.size()){
            pos = pos2 + (median - cnt - 1);
            pos = v2[pos];
            break;
        }else{
            for (; v2[pos2] <= v1[pos1] && pos2 < v2.size(); pos2++){
                cnt++;
                if (cnt == median){
                    pos = pos2;
                    pos = v2[pos2];
                    break;
                }
            }
            
            if (cnt == median) break;
            
            if (pos2 == v2.size()){
                pos = pos1 + (median - cnt - 1);
                pos = v1[pos];
                break;
            }
        }
    }
    
    cout << pos;
    return 0;
}
