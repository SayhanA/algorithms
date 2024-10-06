 for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (dp[i][j] == 0)
            {
                cout << dp[i][j] << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }