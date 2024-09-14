#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
char arr[N][N];
bool isV[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int r, c;

void dfs(int p, int q)
{
    // cout << p << " " << q << endl;
    isV[p][q] = true;
    for (pair<int, int> child : d)
    {
        int x = p + child.first;
        int y = q + child.second;
        if ((x > 0 || y > 0 || x <= r || y <= c) && isV[x][y] == false && arr[x][y] == '.')
        {
            dfs(x, y);
        }
    }
}

int main()
{
    int p, q, s, d;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }

    memset(isV, false, sizeof(isV));

    cin >> p >> q >> s >> d;
    if (arr[p][q] == '.' && arr[s][d] == '.') {
        dfs(p, q);
    } else {
        cout << "NO\n";
        return 0;
    }


    if (isV[s][d])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
