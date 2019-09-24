#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

struct node {
    string id;
    string birth;
    bool operator< (const node& a) const{
        return birth > a.birth;
    }
    
    void getbirth(){
        birth = id.substr(6, 8);
    }
}N[100005];

priority_queue<node> node_queue;
map<string, int> m;
string result;

int main()
{
    int n;
    string s;
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> N[i].id;
        N[i].getbirth();
        m[N[i].id] = i;
    }
    
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> s;
        int id = m[s];
        if (id != 0){
            node_queue.push(N[id]);
            cnt++;
        }
        
        if (cnt == 0){
            if (i == 0){
                result = s;
            }else{
                if (s.substr(6, 8) < result.substr(6, 8)){
                    result = s;
                }
            }
        }
    }
    
    cout << cnt << endl;
    if (cnt > 0){
        cout << node_queue.top().id;
    }else{
        cout << result;
    }
    return 0;
}