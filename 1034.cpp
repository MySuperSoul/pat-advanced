#include <iostream>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;
const int MAXN = 2010;

map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;

int idNumber = 1, k;
int stoifunc(string& s){
    if(stringToInt[s] == 0){
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    }else{
        return stringToInt[s];
    }
}

int Graph[MAXN][MAXN]; // the graph for the phone call
int Weight[MAXN]; // weight for every string id
int visit[MAXN];

void dfs(int i, int& head, int& numberInGang, int& totalWeight){
    if(visit[i] == 1) return;
    visit[i] = 1;
    numberInGang++;
    
    head = (Weight[i] > Weight[head]) ? i : head;
    
    for(int j = 1; j < idNumber; j++){
        if(Graph[i][j] != 0){
            totalWeight += Graph[i][j];
            Graph[i][j] = Graph[j][i] = 0;
            dfs(j, head, numberInGang, totalWeight);
        }
    }
}

void dfsTravel()
{
    for(int i = 1; i < idNumber; i++){
        if(visit[i] == 0){
            int head = i, numberInGang = 0, totalWeight = 0;
            dfs(i, head, numberInGang, totalWeight);
            if(numberInGang > 2 && totalWeight > k) ans[intToString[head]] = numberInGang;
        }
    }
}

int main()
{
    int n;
    cin >> n >> k;
    
    string s1, s2;
    int w;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        Graph[id1][id2] += w;
        Graph[id2][id1] += w;
        Weight[id1] += w;
        Weight[id2] += w;
    }
    
    dfsTravel();
    
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }
    
    return 0;
}

/*
 8 59
 AAA BBB 10
 BBB AAA 20
 AAA CCC 40
 DDD EEE 5
 EEE DDD 70
 FFF GGG 30
 GGG HHH 20
 HHH FFF 10
 */

