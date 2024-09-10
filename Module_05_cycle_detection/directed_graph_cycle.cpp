#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool isV[N];
bool isPath[N];
bool ans;

void dfs(int par){
    cout << par << endl;
    isV[par] = true;
    isPath[par] = true;
    for(int child:v[par]){
        if(isPath[child]) ans=true;
        if(!isV[child]){
            isV[child] = true;
            dfs(child);
        }
    }
    isPath[par] = false;
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
    cout << endl;

    memset(isV, false, sizeof(isV));
    memset(isPath, false, sizeof(isPath));
    ans = false;

    for (int i = 0; i < n; i++)
    {
       if(!isV[i]) dfs(i);
    }
    
    ans ? cout << "cycle detected\n" : cout << "cycle not detected\n";
    
    return 0;
}