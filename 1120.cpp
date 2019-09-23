#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

set<int> s;

int main(){
    int n;
    cin >> n;
    
    string sp;
    while (n--) {
        cin >> sp;
        
        int result = 0;
        for (auto v : sp) result += v - '0';
        s.insert(result);
    }
    
    cout << s.size() << endl;
    for (auto iter  = s.begin(); iter != s.end(); iter++){
        if (iter == s.begin()) cout << (*iter);
        else cout << " " << *iter;
    }
    return 0;
}
