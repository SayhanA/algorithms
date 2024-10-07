#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2 != 0)
            cout << "NO\n";
        else
        {
            bool dp[n + 1][sum + 1];
            dp[0][0] = true;
            for (int i = 1; i <= sum; i++)
            {
                dp[0][i] = false;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= sum; j++)
                {
                    if (a[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }

            dp[n][sum / 2] ? cout << "YES\n" : cout << "NO\n";
        }
    }

    return 0;
}