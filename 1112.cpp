#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

string s;
int n;

int main()
{
    cin >> n;
    cin >> s;

    unordered_set<int> impossible;
    unordered_set<int> possible;

    for (int i = 0; i < s.size(); ){
        bool flag = true;

        if (i + n > s.size()){
            flag = false;
        }else {
            for (int index = i; index < i + n - 1; index++){
                if (s[index] != s[index + 1]){
                    flag = false;
                    break;
                }
            }
        }

        if (!flag) {
            impossible.insert(s[i]);
            if (possible.find(s[i]) != possible.end()) possible.erase(possible.find(s[i]));
            i++;
        }else {
            if (impossible.find(s[i]) == impossible.end()) possible.insert(s[i]);
            i += n;
        }
    }

    string result;
    vector<char> ans;

    for (int i = 0; i < s.size(); ){
        if (possible.find(s[i]) != possible.end()){
            result += s[i];
            ans.push_back(s[i]);
            i += n;
        }else {
            result += s[i];
            i++;
        }
    }

    unordered_set<int> sss;
    for (auto v : ans) {
        if (sss.find(v) != sss.end()) continue;
        else {
            cout << v;
            sss.insert(v);
        }
    }
    cout << endl;
    cout << result;
    return 0;
}
