#include <bits/stdc++.h>
using namespace std;
int par[1005];
int groupSize[1005];
queue<pair<int,int>> removedRoad;
queue<pair<int,int>> newRoad[1005];

void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    return par[node] = dsu_find(par[node]);
}

void dsu_union(int node1, int node2)
{
    // cout << node1 << " " << node2 << endl;
    int parA = dsu_find(node1);
    int parB = dsu_find(node2);

    if (groupSize[parA] > groupSize[parB])
    {
        par[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }
    else
    {
        par[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main()
{
    int n, a, b;
    cin >> n;
    dsu_init(n);

    while (n--)
    {
        cin >> a >> b;
        int paA = dsu_find(a);
        int paB = dsu_find(b);
        if(paA == paB){
            removedRoad.push({a, b});
            continue;
        }else{
            dsu_union(a, b);
        }
    }

    cout << par[7] << endl;

    while (!removedRoad.empty())
    {
        cout << removedRoad.front().first << " " << removedRoad.front().second << endl;
        removedRoad.pop();
    }
    

    return 0;
}