#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];

bool isConnected(int x, int y)
{
    if (x == y)
        return true;

    for (int child : v[x])
    {
        if (child == y)
            return true;
    }
    // cout << endl;
    return false;
}

int main()
{
    int n, e, a, b, q, x, y;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        // v[b].push_back(a);
    }

    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        isConnected(x, y) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}