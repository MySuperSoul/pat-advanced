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

#define MAXN 61200
#define MINN 28800

typedef struct custom{
    int come;
    int serve;
} Custom;

int toSeconds(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<Custom> consumer;
    
    for(int i = 0; i < n; i++){
        int hh, mm, ss, time;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        scanf("%d", &time);
        
        int come = toSeconds(hh, mm, ss);
        if(come > MAXN) continue;
        
        Custom cons {come, time * 60};
        consumer.push_back(cons);
    }
    
    sort(consumer.begin(), consumer.end(), [](Custom& a, Custom& b){
        return a.come < b.come;
    });
    
    vector<int> window(k, MINN);
    int result = 0;
    
    for(int i = 0; i < consumer.size(); i++){
        Custom c = consumer[i];
        int minindex = 0, mintime = window[0];
        
        /*find the first serve window*/
        for(int j = 0; j < k; j++){
            if(window[j] < mintime){
                minindex = j;
                mintime = window[j];
            }
        }
        
        if(c.come >= mintime){
            // update the corresponding window time
            window[minindex] = c.come + c.serve;
        }else{
            result += (mintime - c.come);
            window[minindex] += c.serve;
        }
    }
    
    if(consumer.empty()) cout << "0.0" << endl;
    else{
        printf("%.1f", result * 1.0 / 60 / consumer.size());
    }
    
    return 0;
}
