#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

map<int, string> m = {
    {0, "zero"}, {1, "one"}, {2, "two"},
    {3, "three"}, {4, "four"}, {5, "five"},
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
};

int main()
{
    string num;
    cin >> num;
    
    int result = 0;
    for (auto s : num){
        result += s - '0';
    }
    
    vector<int> ans;
    if (result == 0) ans.push_back(0);
    else{
    while (result != 0) {
        ans.push_back(result % 10);
        result /= 10;
    }
    }
    
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        if (i == 0) cout << m[ans[i]];
        else cout << " " << m[ans[i]];
    }
    return 0;
}
