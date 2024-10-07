#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][s] != -1)
        return dp[n][s];

    int op1 = subset_sum(n - 1, a, s - a[n - 1]);
    int op2 = subset_sum(n - 1, a, s);
    if (a[n - 1] <= s)
    {
        return dp[n][s] = op1 + op2;
    }
    else
    {
        return dp[n][s] = op2;
    }
}

int main()
{
    int n, dif;
    cin >> n;
    int a[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    } 
    cin >> dif;

    int s = (dif + sum) / 2;
    cout << s << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << subset_sum(n, a, s);

    return 0;
}