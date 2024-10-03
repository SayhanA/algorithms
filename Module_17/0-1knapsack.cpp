#include <bits/stdc++.h>
using namespace std;
const int MaxV = 1000;
int val[MaxV][MaxV];

int knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
        return 0;
    if (val[n][W] != -1)
        return val[n][W];
    int op1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
    int op2 = knapsack(n - 1, weight, value, W);
    if (weight[n] <= W)
        return val[n][W] = max(op1, op2);
    return val[n][W] = op2;
}

int main()
{
    int n, w;
    cin >> n;

    int values[n], weights[n];

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cin >> w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            val[i][j] == -1;
        }
    }

    cout << knapsack(n - 1, values, weights, w);

    return 0;
}