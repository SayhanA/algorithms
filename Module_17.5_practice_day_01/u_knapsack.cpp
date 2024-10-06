#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int value[], int weight[], int w)
{
    if (n <= 0 || w == 0)
        return 0;
    int op1 = knapsack(n - 1, value, weight, w - weight[n - 1]) + value[n - 1];
    int op2 = knapsack(n - 1, value, weight, w);
    if (weight[n - 1] <= w)
        return max(op1, op2);
    return op2;
}

int main()
{
    int n, w;
    cin >> n >> w;
    int value[n], weight[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << knapsack(n, value, weight, w);

    return 0;
}