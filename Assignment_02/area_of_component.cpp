#include <bits/stdc++.h>
using namespace std;

const int Max = 1e3 + 5;
char arr[Max][Max];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int isVis[Max][Max];
int r, c, cunt;

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    isVis[x][y] = true;
    cunt = 1;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int px = parent.first;
        int py = parent.second;

        for (pair<int, int> child : directions)
        {
            int cx = px + child.first;
            int cy = py + child.second;
            
            if (cx >= 0 && cy >= 0 && cx < r && cy < c && arr[cx][cy] == '.' && !isVis[cx][cy])
            {
                q.push({cx, cy});
                isVis[cx][cy] = true;
                cunt += 1;
            }
        }
    }
    return cunt;
}

int main()
{
    
    cin >> r >> c;

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    
    memset(isVis, 0, sizeof(isVis));

    int connectedComponents = 0;
    int Smallest = INT_MAX;

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
            if (arr[i][j] == '.' && !isVis[i][j])
            {
                Smallest = min(bfs(i, j), Smallest);
                connectedComponents++;  
            }
        }
    }

    
    if(connectedComponents) cout << Smallest << endl;
    else cout << -1 << endl;

    return 0;
}
