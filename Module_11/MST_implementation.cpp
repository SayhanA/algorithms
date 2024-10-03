#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}


// Disjoin Set Union
void dsu_init(int n, int *arr, int *groupSize)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node, int *arr)
{
    if (arr[node] == -1)
        return node;
    return arr[node] = dsu_find(arr[node], arr);
}

void dsu_union(int node1, int node2, int *arr, int *groupSize)
{
    int parA = dsu_find(node1, arr);
    int parB = dsu_find(node2, arr);

    if (groupSize[parA] > groupSize[parB])
    {
        arr[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }else{
        arr[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main()
{
    int n, e, u, v, w;
    int totalCost = 0;
    cin >> n >> e;
    int arr[n];
    int groupSize[n];

    dsu_init(n, arr, groupSize);

    vector<Edge> EdgeList;

    while (e--)
    {
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }

    sort(EdgeList.begin(), EdgeList.end(), cmp);

    for (Edge child : EdgeList)
    {
        if (dsu_find(child.u, arr) == dsu_find(child.v, arr))
        {
            continue;
        }
        else
        {
            dsu_union(child.u, child.v, arr, groupSize);
            totalCost += child.w;
        }
    }

    cout << totalCost << endl;

    return 0;
}