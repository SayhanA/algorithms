#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 5;
int arr[Max];
int groupSize[Max];

void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (arr[node] == -1)
        return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union(int node1, int node2)
{
    int parA = dsu_find(node1);
    int parB = dsu_find(node2);

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
    int n, e, a, b, cycleEdge = 0;
    cin >> n >> e;
    dsu_init(n);

    while (e--)
    {
        cin >> a >> b;
        int parA = dsu_find(a);
        int parB = dsu_find(b);
        
        if(parA == parB){
            cycleEdge += 1;
        }else{
            dsu_union(a, b);
        }
    }

    cout << cycleEdge << endl;

    return 0;
}