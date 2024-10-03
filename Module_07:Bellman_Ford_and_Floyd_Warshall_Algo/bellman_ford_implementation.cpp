#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    { // constructor function
        (*this).u = u;
        (*this).v = v;
        (*this).c = c;
    }
};

int main()
{
    int n, e, a, b, c;
    vector<Edge> EdgeList;
    int dis[100];

    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b >> c;
        EdgeList.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < 100; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge child : EdgeList)
        {
            // cout << child.u << " " << child.v << " " << child.c << endl;
            int x, y, z;
            x = child.u;
            y = child.v;
            z = child.c;

            if (dis[x] < INT_MAX && dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << dis[i] << endl;
    }
    

    return 0;
}


// input:
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// output:
// 0 --> 0
// 1 --> 7
// 2 --> 5
// 3 --> 10