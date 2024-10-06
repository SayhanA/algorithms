#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    bool dp[n + 1][s + 1];
    dp[0][0] = true;

    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            int op1 = dp[i - 1][j - a[i - 1]];
            int op2 = dp[i - 1][j];
            if (a[i - 1] <= j)
            {
                dp[i][j] = op1 || op2;
            }
            else
                dp[i][j] = op2;
        }
    }

    dp[n][s] ? cout << "YES\n" : cout << "NO\n";

    return 0;
}