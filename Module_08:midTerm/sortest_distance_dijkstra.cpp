#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
const long long int INF = LLONG_MAX;
vector<pair<int, int>> v[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<long long int, int> a, pair<long long int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, cmp> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();

        long long int cost = par.first;
        int val = par.second;

        if (cost > dis[val])
            continue;

        for (pair<int, int> child : v[val])
        {
            int childVal = child.first;
            long long int childCost = child.second;

            if (cost + childCost < dis[childVal])
            {
                dis[childVal] = cost + childCost;
                pq.push({dis[childVal], childVal});
            }
        }
    }
}

int main()
{
    long long int n, e, a, b, c, q, s, t;
    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    cin >> q;
    while (q--)
    {
        cin >> s >> t;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = INF;
        }

        dijkstra(s);
        if (dis[t] < INF)
        {
            cout << dis[t] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
