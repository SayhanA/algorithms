#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visited[1005];

void bsf(int root){
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << endl;

        for(int child:v[par]){
            if(visited[child] == false){
                q.push(child);
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

    bsf(root);

    return 0;
}