#include <bits/stdc++.h>
using namespace std;
const int Max = 1e3 + 5;
char arr[Max][Max];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isVis[Max][Max];
pair<int, int> parentOf[Max][Max];
int dis[Max][Max];
int r, c;

bool isTrue(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    isVis[startX][startY] = true;
    dis[startX][startY] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int x = parent.first, y = parent.second;

        for (pair<int, int> child : v)
        {
            int cx = x + child.first, cy = y + child.second;

            // Path marking with 'X'
            if (isTrue(cx, cy) && arr[cx][cy] == 'D')
            {
                while (arr[x][y] != 'R')
                {
                    arr[x][y] = 'X';
                    int px = parentOf[x][y].first;
                    int py = parentOf[x][y].second;
                    x = px;
                    y = py;
                }
                return true;
            }

            if (isTrue(cx, cy) && !isVis[cx][cy] && arr[cx][cy] == '.')
            {
                q.push({cx, cy});
                isVis[cx][cy] = true;
                parentOf[cx][cy] = {x, y};
                dis[cx][cy] = dis[x][y] + 1;
            }
        }
    }
    return false;
}

int main()
{
    cin >> r >> c;
    int startX, startY;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
        }
    }

    memset(isVis, false, sizeof(isVis));
    memset(parentOf, -1, sizeof(parentOf));
    memset(dis, -1, sizeof(dis));

    bfs(startX, startY);

    if (bfs(startX, startY))
    {

        arr[startX][startY] = 'R';
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}