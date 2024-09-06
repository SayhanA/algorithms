#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool isV[N];

void dsf(int src){
    cout << src << endl;
    isV[src] = true;
    for(int child:v[src]){
        if(isV[child] == false){
            dsf(child);
        }
    }
}

int main(){
    int n, e, a, b;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isV, false, sizeof(isV));

    dsf(0);
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " --> ";
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
    return 0;
}