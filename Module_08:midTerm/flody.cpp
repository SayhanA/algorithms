#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long INF = 1e18;
const int N = 105;
int main()
{
    ll n, e, a, b, c, q, x, y;
    cin >> n >> e;
    ll adj[N][N];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++) i == j ? adj[i][j] = 0 : adj[i][j] = INF;
    }
    
    while (e--)
    {
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
            }
            
        }
        
    }
    
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        adj[x][y] == INF ? cout << -1 << endl : cout << adj[x][y] << endl;
    }
    

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         adj[i][j] == INF ? cout << "INF " : cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}