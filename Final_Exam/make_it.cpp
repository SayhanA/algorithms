#include <bits/stdc++.h>
using namespace std;
int dp[100000 + 5];

bool find(int n, int cur)
{
    if (n == cur)
        return true;

    if (n < cur)
        return false;

    if (dp[cur] != -1)
        return dp[cur];

    return dp[cur] = find(n, cur + 3) || find(n, cur * 2);

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cur = 1;
        memset(dp, -1, sizeof(dp));

        find(n, cur) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}