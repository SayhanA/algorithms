// #include <bits/stdc++.h>
// using namespace std;
// char a[20][20];
// bool isV[20][20];
// vector<pair<int, int>> p = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

// int r, c;

// void dsf(int x, int y)
// {
//     cout << x << " " << y << endl;
//     isV[x][y] = true;

//     for (pair<int, int> cord : p)
//     {
//         int ix = x + cord.first;
//         int iy = y + cord.second;

//         if (ix < 0 || iy < 0 || ix >= r || iy >= c)
//         {
//             return;
//         }
//         else
//         {
//             if (isV[ix][iy] == false)
//             {
//                 dsf(ix, iy);
//             }
//         }
//     }
// }

// int main()
// {
//     int x, y;
//     cin >> r >> c;

//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             cin >> a[i][j];
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cin >> x >> y;
//     memset(isV, false, sizeof(isV));
//     dsf(x, y);

//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             cin >> isV[i][j];
//             cout << isV[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char a[20][20];
bool isV[20][20];
vector<pair<int, int>> p = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int r, c;

void dfs(int x, int y)
{
    cout << x << " " << y << endl;
    isV[x][y] = true;

    for (pair<int, int> cord : p)
    {
        int ix = x + cord.first;
        int iy = y + cord.second;

        if (ix < 0 || iy < 0 || ix >= r || iy >= c)
        {
            continue; 
        }

        if (!isV[ix][iy])
        {
            dfs(ix, iy);
        }
    }
}

int main()
{
    int x, y;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cin >> x >> y;
    memset(isV, false, sizeof(isV));

    dfs(x, y);

    return 0;
}
