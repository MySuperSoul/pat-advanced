#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// dfs, bfs, dp, union-find, binary-search, heap, queue, priority_queue, tree

struct node {
    char id_card[20];
    int score;
    int test_site;
    int date;
    
    void GetTestSite(){
        test_site =  (id_card[1] - '0') * 100 + (id_card[2] - '0') * 10 + (id_card[3] - '0');
    }
    
    void GetDate(){
        int result = 0;
        for (int i = 4; i <= 9; i++){
            result += (id_card[i] - '0') * pow(10, 9 - i);
        }
        date = result;
    }
};

struct node_3 {
    int id, times = 0;
};

// for query 1
map<char, vector<node>> query_1_map;

// for query 2
map<int, pair<int, int>> query_2_map;

// for query 3
map<int, map<int, int>> query_3_map_init;
map<int, vector<node_3>> query_3_map;

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        node n;
        scanf("%s %d", n.id_card, &n.score);
        n.GetTestSite(); n.GetDate();
        query_1_map[n.id_card[0]].push_back(n);
        query_2_map[n.test_site].first += 1;
        query_2_map[n.test_site].second += n.score;
        
        query_3_map_init[n.date][n.test_site] += 1;
    }
     // processing query 1
    for (auto iter = query_1_map.begin(); iter != query_1_map.end(); iter++){
        sort((*iter).second.begin(), (*iter).second.end(), [](node& a, node& b){
            if (a.score == b.score) return strcmp(a.id_card, b.id_card) < 0;
            else return a.score > b.score;
        });
    }
    
    // processing query 3
    for (auto iter = query_3_map_init.begin(); iter != query_3_map_init.end(); iter++){
        int date = iter->first;
        for (auto v : iter->second){
            node_3 n;
            n.id = v.first;
            n.times = v.second;
            query_3_map[date].push_back(n);
        }
    }
    
    for (auto iter = query_3_map.begin(); iter != query_3_map.end(); iter++){
        sort(iter->second.begin(), iter->second.end(), [](node_3& a, node_3& b){
            if (a.times == b.times) return a.id < b.id;
            else return a.times > b.times;
        });
    }
    
    string tmp;
    for (int i = 1; i <= m; i++){
        int type;
        cin >> type >> tmp;
        
        if (type == 1){
            char c = tmp[0];
            printf("Case %d: %d %s\n", i, type, tmp.c_str());
            if (query_1_map[c].size() == 0) cout << "NA" << endl;
            else {
                for (auto v : query_1_map[c]) cout << v.id_card << " " << v.score << endl;
            }
        }else if (type == 2){
            int site = stoi(tmp);
            printf("Case %d: %d %s\n", i, type, tmp.c_str());
            
            if (query_2_map[site].first == 0) cout << "NA" << endl;
            else {
                cout << query_2_map[site].first << " ";
                cout << query_2_map[site].second << endl;
            }
        }else if (type == 3){
            int date = stoi(tmp);
            printf("Case %d: %d %s\n", i, type, tmp.c_str());
            
            if (query_3_map[date].size() == 0) cout << "NA" << endl;
            else{
                for (auto v : query_3_map[date]) cout << v.id << " " << v.times << endl;
            }
        }else {
            cout << "Case " << i << ": " << type << " " << tmp << endl;
            cout << "NA" << endl;
        }
    }
    return 0;
}