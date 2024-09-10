#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool isV[N];
vector<int> adj[N];
int parentArr[N];
bool ans;

void dfs(int src){
    isV[src] = true;
    for (int child : adj[src])
    {
        if (isV[child] == true && child != parentArr[src])
        {
            ans = true;
        }
        if (isV[child] == false)
        {
            parentArr[child] = src;
            dfs(child);
        }
    }
}

int main(){
    int n, e, a, b;
    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(isV, false, sizeof(isV));
    memset(parentArr, -1, sizeof(parentArr));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if(!isV[i]){
            dfs(i);
        }
    }
    
    ans ? cout << "cycle detected\n" : cout << "cycle not detected\n";
    
    return 0;
}