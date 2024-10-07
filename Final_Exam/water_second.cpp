#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        int idx = -1, idx2 = -1, max = INT_MIN, max2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (max < a[i])
            {
                max2 = max;
                idx2 = idx;

                max = a[i];
                idx = i;
            }
            if (max2 < a[i] && a[i] != max)
            {
                max2 = a[i];
                idx2 = i;
            }
        }

        cout << idx << " " << idx2 << endl;
    }

    return 0;
}