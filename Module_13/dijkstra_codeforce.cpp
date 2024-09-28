// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Max = 1e5 + 5;
vector<pair<int, int>> V[Max];
ll dis[Max];
ll par[Max];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
};

void dijkstra(ll src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        q.pop();
        ll node = parent.first;
        ll cost = parent.second;
        for (pair<int, int> child : V[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                par[childNode] = node;
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    ll n, e, u, v, w;
    cin >> n >> e;

    while (e--)
    {
        cin >> u >> v >> w;
        V[u].push_back({v, w});
        V[v].push_back({u, w});
    }

    memset(par, -1, sizeof(par));

    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }

    dijkstra(1);
    int x = n;

    if (par[n] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> path;

    while (x != -1)
    {
        path.push_back(x);
        x = par[x];
    }

    reverse(path.begin(), path.end());

    for (int child : path)
    {
        cout << child << " ";
    }

    return 0;
}