#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
vector<pair<int, int>> v = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool isV[100][100];
int r, c;
int ans;

void dfs(int x, int y)
{
    isV[x][y] = true;
    for (pair<int, int> child : v)
    {
        int cx = x + child.first;
        int cy = y + child.second;
        if (cx >= 0 && cy >= 0 && cx < r && cy < c && !isV[cx][cy] && arr[cx][cy]) dfs(cx, cy);
        if(!isV[cx][cy]){
            ans++;
        }
    }
}

int main()
{
    cin >> r >> c;
    memset(isV, false, sizeof(isV));
    ans = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(!isV[i][j] && arr[i][j] == 1){
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}