#include <bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<pair<int, int>> v[100];
int dis[100];

void dijkstra(int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int node = par.first;
        int cost = par.second;
        
        for(pair<int,int> child:v[node]){
            int childNode = child.first;
            int childCost = child.second;

            if(cost+childCost < dis[childNode]){
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int n, e, a, b, c;
    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << dis[i] << endl;
    }
    

    return 0;
}