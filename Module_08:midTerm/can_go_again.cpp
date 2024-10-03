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
    ll n, e, a, b, w, s, t, d;
    vector<Edge> EdgeList;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
    }

    cin >> s;
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

    bool isCycled = false;
    for (Edge child : EdgeList)
    {
        ll u = child.u;
        ll v = child.v;
        ll w = child.w;

        if (dis[u] < INF && dis[u] + w < dis[v])
        {
            isCycled = true;
            break;
        }
    }

    if (isCycled)
    {
        cout << "Negative Cycle Detected\n";
    }
    else
    {
        // Process the test cases
        cin >> t;
        while (t--)
        {
            cin >> d;
            if (dis[d] < INF)
            {
                cout << dis[d] << endl;
            }
            else
            {
                cout << "Not Possible\n";
            }
        }
    }

    return 0;
}