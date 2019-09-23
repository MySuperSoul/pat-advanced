#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n, m;

map<string, unordered_set<string>> girls;
map<string, unordered_set<string>> boys;

vector<pair<string, string>> ans;
void Query(string& v1, string& v2){
    ans.clear();
    if (v1.front() != '-' && v2.front() == '-'){ // boy -> girl
        for (auto v : boys[v1]){ // all boy friends
            for (auto g : girls[v2]){ // all girl friends
                if (girls[v].find(g) != girls[v].end()){
                    ans.push_back(make_pair(v, g));
                }
            }
        }
    }else if (v1.front() == '-' && v2.front() != '-'){
        for (auto v : girls[v1]){ // all boy friends
            for (auto g : boys[v2]){ // all girl friends
                if (boys[v].find(g) != boys[v].end()){
                    ans.push_back(make_pair(v, g));
                }
            }
        }
    }else if (v1.front() == '-' && v2.front() == '-'){
        for (auto v : girls[v1]){ // all boy friends
            for (auto g : girls[v2]){ // all girl friends
                if (v != v2 && g != v1 && girls[v].find(g) != girls[v].end()){
                    ans.push_back(make_pair(v, g));
                }
            }
        }
    }else{
        for (auto v : boys[v1]){ // all boy friends
            for (auto g : boys[v2]){ // all girl friends
                if (v != v2 && g != v1 && boys[v].find(g) != boys[v].end()){
                    ans.push_back(make_pair(v, g));
                }
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end(), [](pair<string, string>& a, pair<string, string>& b){
        int a1 = stoi(a.first); int a2 = stoi(a.second); int b1 = stoi(b.first); int b2 = stoi(b.second);
        if (abs(a1) == abs(b1)){
            return abs(a2) < abs(b2);
        }else return abs(a1) <= abs(b1);
    });
    
    for (auto v : ans){
        printf("%04d %04d\n", abs(stoi(v.first)), abs(stoi(v.second)));
    }
}

int main(){
    cin >> n >> m;
    string s1, s2;
    for (int i = 0; i < m; i++){
        cin >> s1 >> s2;
        if (s1.front() == '-') girls[s2].insert(s1);
        else boys[s2].insert(s1);
        
        if (s2.front() == '-') girls[s1].insert(s2);
        else boys[s1].insert(s2);
    }
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++){
        cin >> s1 >> s2;
        Query(s1, s2);
    }
    return 0;
}
