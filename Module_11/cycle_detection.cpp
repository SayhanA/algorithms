#include <bits/stdc++.h>
using namespace std;
int parent[100];
int groupSize[100];

void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int node1, int node2)
{
    int parA = dsu_find(node1);
    int parB = dsu_find(node2);

    if (groupSize[parA] > groupSize[parB])
    {
        parent[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }
    else
    {
        parent[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main()
{
    int n, e, a, b;
    cin >> n >> e;
    dsu_init(n);
    bool isCycled = false;
    while (e--)
    {
        cin >> a >> b;
        if (dsu_find(a) == dsu_find(b))
        {
            isCycled = true;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    isCycled ? cout << "cycled\n" : cout << "not cycled\n";

    return 0;
}