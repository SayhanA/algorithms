#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int level[N];

void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    if (arr[node] == -1)
        return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union_by_level(int node1, int node2)
{
    int leadA = dsu_find(node1);
    int leadB = dsu_find(node2);

    if (level[leadA] > level[leadB])
        arr[leadB] = leadA;
    else if (level[leadB] > level[leadA])
        arr[leadA] = leadB;
    else
    {
        arr[leadA] = leadB;
        level[leadB]++;
    }
}

int main()
{
    dsu_init(7);
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);

    cout << dsu_find(1) << endl;
    dsu_union_by_level(3, 4);
    cout << dsu_find(1) << endl;

    return 0;
}