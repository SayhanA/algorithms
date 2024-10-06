#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll mat[10][10];

ll fun(ll i, ll j)
{
    if (i == n - 1 && j == m - 1)
    {
        return mat[i][j];
    }
    ll op1 = LLONG_MIN, op2 = LLONG_MIN;
    if (i + 1 < n)
    {
        op1 = fun(i + 1, j);
    }
    if (j + 1 < m)
    {
        op2 = fun(i, j + 1);
    }

    return mat[i][j] + max(op1, op2);
}

int main()
{
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << fun(0, 0);

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

// Finding the max number from a matrix
// ll fun(ll i, ll j)
// {
//     ll total = mat[i][j];
//     if (i + 1 < n && j + 1 < m)
//         return total = max(fun(i + 1, j), fun(i, j + 1));
//     return total;
// }