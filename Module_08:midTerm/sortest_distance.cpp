#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 5;
const ll INF = LLONG_MAX;
ll dis[N];

class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    ll n, e, a, b, w, q, s, d;
    vector<Edge> EdgeList;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }

    cin >> q;
    while (q--)
    {
        cin >> s >> d;
        for (int i = 0; i <= n; i++)
        {
            dis[i] = INF;
        }
        dis[s] = 0;
        for (int i = 1; i < n; i++)
        {
            for (Edge child : EdgeList)
            {
                ll u = child.u;
                ll v = child.v;
                ll w = child.w;

                if (dis[u] < INF && dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                }
            }
        }

        if(dis[d] < INF) {
            cout << dis[d] << endl;
        }else {
            cout << -1 << endl;
        }
    }

    return 0;
}