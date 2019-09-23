#include <iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

unordered_map<int, string> earth_map1 = {
    {0, "tret"}, {1, "jan"}, {2, "feb"}, {3, "mar"}, {4, "apr"}, {5, "may"}, {6, "jun"},
    {7, "jly"}, {8, "aug"}, {9, "sep"}, {10, "oct"}, {11, "nov"}, {12, "dec"},
};

unordered_map<int, string> earth_map2 = {
    {1, "tam"}, {2, "hel"}, {3, "maa"}, {4, "huh"}, {5, "tou"}, {6, "kes"},
    {7, "hei"}, {8, "elo"}, {9, "syy"}, {10, "lok"}, {11, "mer"}, {12, "jou"},
};

unordered_map<string, int> mars_map_1 = {
    {"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6},
    {"jly", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12},
};

unordered_map<string, int> mars_map_2 = {
    {"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6},
    {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12},
};

void Earth(string s){
    int num = stoi(s);
    int up = num / 13;
    int down = num % 13;

    if (up == 0){
        cout << earth_map1[down] << endl;
    }else {
        if (down != 0) cout << earth_map2[up] << " " << earth_map1[down] << endl;
        else cout << earth_map2[up] << endl;
    }
}

void Mars(string s){
    if (s.find(" ") == -1){
        int num = mars_map_1[s];
        if (num == 0){
            num = mars_map_2[s];
            num *= 13;
        }
        cout << num << endl;
    }else {
        int index = s.find(" ");
        int up = mars_map_2[s.substr(0, index)];
        int down = mars_map_1[s.substr(index + 1)];
        cout << up * 13 + down << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    getchar();

    string s;
    for (int i = 0; i < n; i++){
        getline(cin, s);

        if (isdigit(s[0])){
            Earth(s);
        }else {
            Mars(s);
        }
    }
    return 0;
}
