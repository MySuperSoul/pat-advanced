#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

string Add(string s1, string s2){
    string tmp = s2;
    
    for (int i = s1.size() - 1; i >= 1; i--){
        s1[i] += tmp[i] - '0';
        if (s1[i] > '9'){
            s1[i] -= 10;
            s1[i - 1] += 1;
        }
    }
    
    s1[0] += tmp[0] - '0';
    if (s1[0] > '9'){
        s1[0] -= 10;
        s1.insert(0, "1");
    }
    
    return s1;
}

bool is_valid(string& s){
    int l = 0, r = s.size() - 1;
    for (; l <= r; l++, r--){
        if (s[l] != s[r]) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    
    if (is_valid(s)){
        cout << s << " is a palindromic number.";
        return 0;
    }
    
    int cnt = 0;
    while (cnt != 10) {
        string tmp = s;
        string rev = tmp;
        reverse(rev.begin(), rev.end());
        s = Add(tmp, rev);
        cnt++;
        cout << tmp << " + " << rev << " = " << s << endl;
        if (is_valid(s)) {
            cout << s << " is a palindromic number.";
            return 0;
        }
    }
    cout << "Not found in 10 iterations.";
    return 0;
}
