#include <bits/stdc++.h>

using namespace std;

int a, b;

string itos(int n){
    stringstream ss;
    ss << n;
    return ss.str();
}

void Output(string s){
    reverse(s.begin(), s.end());
    
    int cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (cnt++ == 3){
            cnt = 0;
            s.insert(i, ",");
        }
    }
    
    reverse(s.begin(), s.end());
    cout << s;
}

int main()
{
    cin >> a >> b;
    int result = a + b;
    
    if (result < 0){
        cout << "-";
        Output(itos(abs(result)));
    }else{
        Output(itos(result));
    }
    return 0;
}
