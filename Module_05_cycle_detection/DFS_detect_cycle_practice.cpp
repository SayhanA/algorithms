#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool isV[N];
bool inCycle[N];
bool cycled;

void dfs(int par){
    cout << par << endl;
    isV[par] = true;
    inCycle[par] = true;
    for(int child:v[par]){
        if(inCycle[child]) {
            cout << "Cycle detected here\n" ;
            cycled=true;
        }
        if(!isV[child]){
            isV[child] = true;
            dfs(child);
        }
    }
    inCycle[par] = false;
}

int main(){
    int n, e, a, b;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> ";
        for(int child:v[i]){
            cout << child << " ";
        }
        cout << endl;
    }
    
    memset(isV, false, sizeof(isV));
    memset(inCycle, false, sizeof(inCycle));

    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }
    
    cycled ? cout << "Cycle Detected\n" : cout << "No Cycle Detected\n";
    
    return 0;
}