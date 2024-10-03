#include <bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool isVis[100];
int level[100];

void sortest_path(int src){
    queue<int> q;
    q.push(src);
    isVis[src] = true;
    level[src] = 0;
    
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        
        for(int child:v[par]){
            if(isVis[par] == false){
                q.push(child);
                isVis[child] = true;
                level[child] = level[par]+1;
            }
        }
    }
    
}

int main(){
    int n, e, a, b, x, src, dsc;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> x;
    memset(isVis, false, sizeof(isVis));
    memset(level, -1, sizeof(level));
    cout << x << endl;

    sortest_path(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    

    // while (x--)
    // {
    //     cin >> src >> dsc;
    //     // cout << src << " " << dsc << endl;
    // }
    
    
    return 0;
}