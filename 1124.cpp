#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int m, n, sp;

int main(){
    cin >> m >> n >> sp;
    
    string s;
    vector<string> vec;
    for (int i = 0; i < m; i++){
        cin >> s;
        vec.push_back(s);
    }
    
    if (sp >= vec.size()) cout << "Keep going...";
    else{
        int start_p = sp - 1;
        unordered_set<string> winner;
        vector<string> ans;
        
        int i;
        for (i = start_p; i < vec.size();){
            if (winner.find(vec[i]) != winner.end()){
                i++;
            }else{
                winner.insert(vec[i]);
                ans.push_back(vec[i]);
                i += n;
            }
        }
        
        for (auto v : ans) cout << v << endl;
    }
    return 0;
}
