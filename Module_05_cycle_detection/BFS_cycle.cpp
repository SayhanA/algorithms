#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool isV[N];
vector<int> adj[N];
int parentArr[N];
bool ans;

void bfs(int src){
    queue<int> q;
    q.push(src);
    isV[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << endl;

        for(int child: adj[par]){
            if(isV[child] && parentArr[par] != child){
                ans = true;
            }
            if(!isV[child]){
                isV[child] = true;
                parentArr[child] = par;
                q.push(child);
            }
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
            bfs(i);
        }
    }
    
    ans ? cout << "cycle detected\n" : cout << "cycle not detected\n";
    
    return 0;
}