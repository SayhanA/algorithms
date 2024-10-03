#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char arr[N][N];
vector<pair<int, int>> v = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isVisited[N][N];
int dis[N][N];
int n;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    isVisited[x][y] = true;
    dis[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        int r = parent.first;
        int c = parent.second;

        for (pair<int, int> child : v)
        {
            int cr = child.first + r;
            int cc = child.second + c;

            if (cr >= 0 && cc >= 0 && cr < n && cc < n && arr[cr][cc] != 'T' && !isVisited[cr][cc])
            {
                q.push({cr, cc});
                isVisited[cr][cc] = true;
                dis[cr][cc] = dis[r][c] + 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(dis, -1, sizeof(dis));

    int startX = -1, startY = -1, endX = -1, endY = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
            if (arr[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            if(arr[i][j] == 'E'){
                endX = i;
                endY = j;
            }
        }
        cout << endl;
    }

    if (startX != -1 && startY != -1)
    {
        bfs(startX, startY);
    }
    else
    {
        cout << "'E' not found in the grid!" << endl;
        return 0;
    }

    cout << dis[endX][endY] << endl;

    return 0;
}
