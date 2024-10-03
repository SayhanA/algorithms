#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    // pair<int, int> a[e];
    vector<pair<int, int>> v;
    
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // v.push_back(make_pair(a, b));
        v.push_back({a, b});
    }
    
    // for(auto it:v){
    //     cout << it.first << " " << it.second << endl;
    // }

     for(pair<int, int> it:v){
        cout << it.first << " " << it.second << endl;
    }
    
    return 0;
}