#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool isV[100];
int level[100];
int parent[100];

void bst_level(int src){
    queue<int> q;
    q.push(src);
    isV[src] = true;
    level[src] = 0;
    
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout <<  par << endl;

        for(int child:v[par]){
            if(isV[child] == false){
                q.push(child);
                level[child] = level[par] + 1;
                isV[child] = true;
                parent[child] = par;
            }
        }
    }
    
}

int main(){
    int n, e, a, b, src, des;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    cin >> src >> des;
    memset(isV, false, sizeof(isV));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bst_level(src);

    vector<int> path;
    while (des != -1)
    {   
        path.push_back(des);
        des = parent[des];
    }
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << " ";
    }

    
    return 0;
}