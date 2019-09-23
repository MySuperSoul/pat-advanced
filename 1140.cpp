#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int d, n;

int main()
{
    cin >> d >> n;
    
    string s = to_string(d);
    string result;
    for (int i = 0; i < n - 1; i++){
        int cnt = 0;
        char now = s.front();
        for (int index = 0; index < s.size(); index++){
            if (now == s[index]){
                cnt++;
            }else{
                result.push_back(now);
                result += to_string(cnt);
                cnt = 1;
                now = s[index];
            }
        }
        result.push_back(now);
        result += to_string(cnt);
        
        s = result;
        result = "";
    }
    
    cout << s;
    return 0;
}
