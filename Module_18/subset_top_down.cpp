#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[n][s] == -1)
        return dp[n][s];

    int op1 = subset_sum(n - 1, a, s - a[n - 1]);
    int op2 = subset_sum(n - 1, a, s);

    if (a[n - 1] <= s)
    {
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = op2;
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int s;
    cin >> s;

    subset_sum(n, a, s) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}