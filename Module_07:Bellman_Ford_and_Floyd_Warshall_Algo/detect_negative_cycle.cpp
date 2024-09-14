#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n, e, a, b, c;
    vector<Edge> edgeList;
    int dis[100];
    bool cycle = false;

    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < 100; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge child : edgeList)
        {
            int x = child.u, y = child.v, z = child.c;
            if (dis[x] < INT_MAX && dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
            }
        }
    }

    for (Edge child : edgeList)
        {
            int x = child.u, y = child.v, z = child.c;
            if (dis[x] < INT_MAX && dis[x] + z < dis[y])
            {
                cycle = true;
            }
        }

    cycle ? cout << "Cycled\n" : cout << "Not Cycled\n";

    return 0;
}