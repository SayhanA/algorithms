// https://lightoj.com/problem/guilty-prince
#include <bits/stdc++.h>
using namespace std;
char arr[20][20];
bool isVis[20][20];
vector<pair<int, int>> v = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int r, c, counts;

void bfs(int n, int m)
{
    queue<pair<int, int>> q;
    q.push({n, m});
    isVis[n][m] = true;
    counts = 1;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for (pair<int, int> child : v)
        {
            int cx = child.first + x;
            int cy = child.second + y;

            if (cx >= 0 && cy >= 0 && cx < r && cy < c && arr[cx][cy] != '#' && !isVis[cx][cy])
            {
                q.push({cx, cy});
                isVis[cx][cy] = true;
                counts++;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int startX, startY;
        cin >> c >> r;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                {
                    startX = i;
                    startY = j;
                }
            }
        }

        memset(isVis, false, sizeof(isVis));
        counts = 0;

        bfs(startX, startY);

        cout << "Case " << i << ": " << counts << endl;
    }

    return 0;
}
