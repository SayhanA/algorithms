#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
vector<pair<int, int>> v = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
bool isV[100][100];
int dis[100][100];
int n, m;

void bsf(int k1, int k2)
{
    queue<pair<int, int>> q;
    q.push({k1, k2});
    isV[k1][k2] = true;
    dis[k1][k2] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int x = par.first;
        int y = par.second;
        for (pair<int, int> child : v)
        {
            int xc = x + child.first;
            int yc = y + child.second;
            if ((xc >= 0 && yc >= 0 && xc < n && yc < m) && !isV[xc][yc])
            {
                isV[xc][yc] = true;
                q.push({xc, yc});
                dis[xc][yc] = dis[x][y] + 1;
            }
        }
    }
}

int main()
{
    int t, k1, k2, q1, q2;

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k1 >> k2 >> q1 >> q2;
        memset(arr, '.', sizeof(arr));
        memset(isV, false, sizeof(isV));
        memset(dis, -1, sizeof(dis));

        bsf(k1, k2);
        cout << dis[q1][q2] << endl;
    }

    return 0;
}