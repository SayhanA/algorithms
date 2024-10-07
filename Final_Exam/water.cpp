// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> v;
//         int a[n];

//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             a[i] = x;
//             v.push_back(x);
//         }

//         sort(v.begin(), v.end(), greater<int>());

//         for (int i = 0; i < n; i++)
//         {
//             if (v[0] == a[i])
//                 cout << i << " ";
//             if (v[1] == a[i])
//                 cout << i << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

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
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> sorted_v = v;
        sort(sorted_v.begin(), sorted_v.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            if (sorted_v[0] == v[i])
                cout << i << " ";
            if (sorted_v[1] == v[i])
                cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}