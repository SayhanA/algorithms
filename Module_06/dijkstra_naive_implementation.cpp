// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// vector<pair<int, int>> v[N];
// int dis[N];

// void dijkstra(int src){
//     queue<pair<int, int>> q;
//     q.push({src, 0});
//     dis[src] = 0;

//     while (!q.empty())
//     {
//         pair<int, int> par = q.front();
//         q.pop();

//         int parVal = par.first;
//         int parCost = par.second;
//         // cout << parVal << " --> ";

//         for(pair<int, int> child:v[parVal]){
//             int childVal = child.first;
//             int childCost = child.second;
//             // cout << childVal << " ";

//             int totalCost = parCost + childCost;

//             if(totalCost < dis[childCost]){
//                 dis[childCost] =  totalCost;
//                 q.push({childCost, dis[childCost]});
//             }
//         }
//         // cout << endl;
//     }
    
// }

// int main(){
//     int n, e, a, b, c;
//     cin >> n >> e;
//     while (e--)
//     {
//         cin >> a >> b >> c;
//         v[a].push_back({b, c});
//         v[b].push_back({a, c});
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
    
    
//     dijkstra(0);
    
//     for (int i = 0; i < n; i++)
//     {
//         cout << i << " " << dis[i] << endl;
//     }
    
    
//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << i << " --> ";
//     //     for(pair<int, int> child:v[i]){
//     //         cout << child.first << " " << child.second << ", ";
//     //     }
//     //     cout << endl;
//     // }
    
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
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
        cout << i << "-> " << dis[i] << endl;
    }
    return 0;
}