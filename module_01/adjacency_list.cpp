#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    vector<int> main[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        main[a].push_back(b);
        main[b].push_back(a);
    }
    
    for(int x:main[0]){
        cout << x << " ";
    }
    
    return 0;
}