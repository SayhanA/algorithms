#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> v[100];
int dis[100];

void dijkstra(int src){
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int parVal = par.first;
        int parCost = par.second;

        for(pair<int,int> child:v[parVal]){
            int childVal = child.first;
            int childCost = child.second;

            if(parCost+childCost < dis[childVal]){
                dis[childVal] = parCost+childCost;
                q.push({childVal, dis[childVal]});
            }
        }
    }
    
}

int main(){
    int n, e, a, b, c;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < 100; i++)
    {
        dis[i] = INT_MAX;
    }
    
    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << dis[i] << endl;
    }
    
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " --> ";
    //     for(pair<int, int> child:v[i]){
    //         cout << '{' << child.first << ", " << child.second << '}' << " ";
    //     }
    //     cout << endl;
    // }
    
    
    return 0;
}