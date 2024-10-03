#include <bits/stdc++.h>
using namespace std;
int r, c;
char arr[100][100];
pair<int, int> start, stop;
string path;
vector<pair<pair<int, int>, char>> dir = {{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};
bool isV[100][100];
int dis[100][100];
pair<pair<int, int>, char> parent[100][100];

bool bfs()
{
  queue<pair<int, int>> q;
  q.push(start);
  isV[start.first][start.second] = true;
  dis[start.first][start.second] = 0;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x == stop.first && y == stop.second)
    {
      while (make_pair(x, y) != start)
      {
        path += parent[x][y].second;
        tie(x, y) = parent[x][y].first;
      }
      reverse(path.begin(), path.end());
      return true;
    }
    for (auto child : dir)
    {
      int nx = x + child.first.first;
      int ny = y + child.first.second;
      if (nx >= 0 && ny >= 0 && nx < r && ny < c && !isV[nx][ny] && arr[nx][ny] != '#')
      {
        isV[nx][ny] = true;
        q.push({nx, ny});
        parent[nx][ny] = {{x, y}, child.second}; 
      }
    }
  }
  return false;
}
int main()
{
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr[i][j];
    //   cout << arr[i][j] << " ";
      if (arr[i][j] == 'A')
        start = {i, j};
      if (arr[i][j] == 'B')
        stop = {i, j};
    }
    // cout << endl;
  }
  memset(isV, false, sizeof(isV));
  memset(dis, -1, sizeof(dis));
  memset(parent, -1, sizeof(parent));

  if (bfs())
  {
    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";
  }
  else
  {
    cout << "NO\n";
  }
  return 0;
}