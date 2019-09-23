#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

struct people {
    string id;
    int height;
    
    bool operator< (const people& a) const{
        if (height == a.height) return id < a.id;
        else return height > a.height;
    }
} N[10005];

int n, k;

vector<deque<people>> Rows;

int main()
{
    cin >> n >> k;
    
    int row_num = n / k;
    int last_row_num = n - (k - 1) * row_num;
    
    for (int i = 0; i < n; i++){
        cin >> N[i].id >> N[i].height;
    }
    
    sort(N, N + n);
    
    // first for the last line
    deque<people> d;
    for (int i = 0; i < last_row_num; i++){
        if (d.empty()) d.push_back(N[i]);
        else {
            if (i % 2 == 1) d.push_front(N[i]);
            else d.push_back(N[i]);
        }
    }
    Rows.push_back(d);
    
    // for the last rows
    int tmp = last_row_num;
    for (int row = 0; row < k - 1; row++){
        deque<people> dd;
        int cnt = 0;
        
        for (; tmp < n; tmp++){
            if (cnt == row_num) break;
            if (dd.empty()){
                dd.push_front(N[tmp]);
                cnt++;
            }else {
                if (cnt % 2 == 1) dd.push_front(N[tmp]);
                else dd.push_back(N[tmp]);
                cnt++;
            }
        }
        
        Rows.push_back(dd);
    }
    
    for (auto v : Rows){
        for (auto iter = v.begin(); iter != v.end(); iter++){
            if (iter == v.begin()) cout << (*iter).id;
            else cout << " " << (*iter).id;
        }
        cout << endl;
    }
    return 0;
}
