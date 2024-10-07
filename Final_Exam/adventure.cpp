#include <bits/stdc++.h>
using namespace std;
const int Max = 1e3 + 5;
int dp[Max][Max];

int knapsack(int n, int weight[], int value[], int s)
{
    if (n == 0 || s == 0)
        return 0;

    if (dp[n][s] != -1)
        return dp[n][s];

    int op2 = knapsack(n - 1, weight, value, s);

    if (weight[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, weight, value, s - weight[n - 1]) + value[n - 1];
        return dp[n][s] = max(op1, op2);
    }
    else
        return dp[n][s] = op2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int weight[n], value[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << knapsack(n, weight, value, s) << endl;
    }

    return 0;
}