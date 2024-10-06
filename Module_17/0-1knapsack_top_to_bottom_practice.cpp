#include <bits/stdc++.h>
using namespace std;
int memo[100][100];

int knapsack(int n, int value[], int weight[], int w)
{
    if (n == 0 || w == 0)
        return 0;
    if (memo[n][w] != -1)
        return memo[n][w];
    int op1 = knapsack(n - 1, value, weight, w - weight[n - 1]) + value[n - 1];
    int op2 = knapsack(n - 1, value, weight, w);
    if (weight[n - 1] <= w)
        return memo[n][w] = max(op1, op2);
    return memo[n][w] = op2;
}

int main()
{
    int n, w;
    cin >> n;

    int value[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cin >> w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            memo[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, value, weight, w);

    return 0;
}