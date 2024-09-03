#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visited[1005];
int level[1005];

void bsf(int root){
    queue<int> q;
    q.push(root);
    visited[root] = true;
    level[root] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << endl;

        for(int child:v[par]){
            if(visited[child] == false){
                q.push(child);
                visited[child] = true;
                level[child] = level[par]+1;
            }
        }
        
    }
    
}

int main(){
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int root;
    cin >> root;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    bsf(root);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    
    
    return 0;
}