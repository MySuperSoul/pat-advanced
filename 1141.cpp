#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct people {
    string id;
    int grades;
};

struct school {
    string school_id;
    int tws;
    int ns;
    int rank = 1;
    vector<people> students;
    
    void GetTWS(){
        double result = 0;
        for (auto v : students){
            if (v.id.front() == 'T') result += 1.5 * v.grades;
            else if (v.id.front() == 'A') result += v.grades;
            else result += v.grades / 1.5;
        }
        tws = (int)(result);
        ns = students.size();
    }
    
    bool operator< (const school& a) const{
        if (tws == a.tws){
            if (ns == a.ns){
                return school_id < a.school_id;
            }else return ns < a.ns;
        }else return tws > a.tws;
    }
};

map<string, school> school_map;

int n;
int main()
{
    cin >> n;
    
    string s;
    for (int i = 0; i < n; i++){
        people p;
        cin >> p.id >> p.grades >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        school_map[s].students.push_back(p);
    }
    
    vector<school> vec;
    for (auto v : school_map){
        v.second.GetTWS();
        v.second.school_id = v.first;
        vec.push_back(v.second);
    }
    
    sort(vec.begin(), vec.end());
    
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++){
        if (i != 0 && vec[i].tws == vec[i - 1].tws) vec[i].rank = vec[i - 1].rank;
        else vec[i].rank = i + 1;
        
        printf("%d %s %d %d\n", vec[i].rank, vec[i].school_id.c_str(), vec[i].tws, vec[i].ns);
    }
    return 0;
}
