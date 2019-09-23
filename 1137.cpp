#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct node {
    string id;
    int online_score = -1;
    int mid_score = -1;
    int final_score = -1;
    int real_score;
    
    void GetScore(){
        if (mid_score > final_score){
            real_score = int(round(0.4 * mid_score + 0.6 * final_score));
        }else{
            real_score = final_score;
        }
    }
    
    bool operator< (const node& a) const{
        if (real_score == a.real_score){
            return id < a.id;
        }else{
            return real_score > a.real_score;
        }
    }
};

map<string, node> node_map;

int p, m, n;
int main(){
    cin >> p >> m >> n;
    string s;
    for (int i = 0; i < p; i++){
        int grades;
        cin >> s;
        scanf("%d", &grades);
        node_map[s].id = s;
        node_map[s].online_score = grades;
    }
    
    for (int i = 0; i < m; i++){
        cin >> s;
        int v;
        scanf("%d", &v);
        node_map[s].id = s;
        node_map[s].mid_score = v;
    }
    
    for (int i = 0; i < n; i++){
        cin >> s;
        int v;
        scanf("%d", &v);
        node_map[s].id = s;
        node_map[s].final_score = v;
    }
    
    vector<node> vec;
    for (auto v : node_map){
        if (v.second.online_score >= 200 && v.second.online_score <= 900){
            v.second.GetScore();
            if (v.second.real_score >= 60) vec.push_back(v.second);
        }
    }
    
    sort(vec.begin(), vec.end());
    for (auto v : vec){
        printf("%s %d %d %d %d\n", v.id.c_str(), v.online_score, v.mid_score, v.final_score, v.real_score);
    }
    return 0;
}
