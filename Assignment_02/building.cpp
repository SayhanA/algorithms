#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll arr[N];
ll groupSize[N];

class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

void dsu_init(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

ll dsu_find(ll node)
{
    if (arr[node] == -1)
        return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union(ll node1, ll node2)
{
    ll parA = dsu_find(node1);
    ll parB = dsu_find(node2);

    if (groupSize[parA] > groupSize[parB])
    {
        arr[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }
    else
    {
        arr[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main()
{
    ll n, e, a, b, w, totalCost = 0;
    cin >> n >> e;
    vector<Edge> edgeList;

    dsu_init(n);

    while (e--)
    {
        cin >> a >> b >> w;
        edgeList.push_back(Edge(a, b, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    for(Edge child:edgeList){
        // cout << child.v << " " << child.u << " " << child.c << endl;

        int parA = dsu_find(child.v);
        int parB = dsu_find(child.u);

        if(parA != parB){
            dsu_union(child.v, child.u);
            totalCost += child.c;
        }else{
            // cout << -1;
        }
    }    

    bool isConectable = true;

    for (int i = 1; i <= n; i++)
    {
        if(dsu_find(1) != dsu_find(i)) isConectable = false;
    }
    
    isConectable ? cout << totalCost << endl : cout << -1 << endl;

    return 0;
}