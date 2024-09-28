#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5;

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[Max];
int group_size[Max];
void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
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

    if (group_size[parA] > group_size[parB])
    {
        parent[parB] = parA;
        group_size[parA] += group_size[parB];
    }
    else
    {
        parent[parA] = parB;
        group_size[parB] += group_size[parA];
    }
}

int main()
{
    int n, e, u, v, w, totalCost;
    cin >> n >> e;
    vector<Edge> EdgeList;

    while (e--)
    {
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }

    dsu_init(n);

    sort(EdgeList.begin(), EdgeList.end(), cmp);

    totalCost = 0;

    for (Edge child : EdgeList)
    {
        int parA = dsu_find(child.u);
        int parB = dsu_find(child.v);
        if(parA == parB){ 
            continue;
        }else{
            dsu_union(child.u, child.v);
            totalCost += child.w;
        }
    }

    // for (Edge child : EdgeList)
    // {
    //     cout << child.u << " " << child.v << " " << child.w << endl;
    // }
    // cout << endl;
    cout << totalCost << endl;

    return 0;
}