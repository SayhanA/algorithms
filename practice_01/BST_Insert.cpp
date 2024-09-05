#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];

int main(){
    int n, e, a, b, src;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}