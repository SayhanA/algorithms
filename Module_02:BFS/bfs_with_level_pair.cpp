#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visited[1005];

void bsf(int root, int destination){
    queue<pair<int, int>> q;
    q.push({root, 0});
    visited[root] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        // cout << par << endl;
        if(par == destination) cout << level << endl;

        for(int child:v[par]){
            if(visited[child] == false){
                q.push({child, level+1});
                visited[child] = true;
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

    bsf(root, 6);
    
    return 0;
}