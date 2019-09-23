#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define DebugSTL(x) for (auto v : x) cout << v << endl;

vector<double> ans;
int n;

int main()
{
    cin >> n;
    char a[50], b[50];
    
    for (int i = 0; i < n; i++){
        double tmp;
        scanf("%s", a);
        sscanf(a, "%lf", &tmp);
        sprintf(b, "%.2f", tmp);
        
        bool flag = true;
        if (strlen(a) > strlen(b)) flag = false;
        else{
            for (int index = 0; index < strlen(a); index++){
                if (a[index] != b[index]){
                    flag = false;
                    break;
                }
            }
            if (tmp < -1000 || tmp > 1000) flag = false;
        }
        
        if (!flag) printf("ERROR: %s is not a legal number\n", a);
        else ans.push_back(tmp);
    }
    
    if (ans.empty()){
        printf("The average of 0 numbers is Undefined");
    }else if (ans.size() == 1){
        printf("The average of 1 number is %.2f", ans.front());
    }else {
        printf("The average of %d numbers is %.2f", ans.size(), accumulate(ans.begin(), ans.end(), 0.0) * 1.0 / ans.size());
    }
    return 0;
}
