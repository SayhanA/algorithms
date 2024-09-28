#include <bits/stdc++.h>
using namespace std;

const int Max = 1e3 + 5;
char arr[Max][Max];                
pair<int, int> parent[Max][Max];   
bool isVis[Max][Max];               
int n, m;


vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    isVis[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        
        for (auto direction : directions) {
            int nx = x + direction.first;
            int ny = y + direction.second;

            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 'D') {
                
                while (!(x == startX && y == startY)) {
                    arr[x][y] = 'X';  
                    int px = parent[x][y].first; 
                    int py = parent[x][y].second; 
                    x = px; 
                    y = py; 
                }
                return true; 
            }

            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == '.' && !isVis[nx][ny]) {
                q.push({nx, ny});
                isVis[nx][ny] = true;
                parent[nx][ny] = {x, y}; 
            }
        }
    }

    return false; 
}

int main() {
    cin >> n >> m;
    int startX, startY;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                startX = i;
                startY = j;
            }
        }
    }

    memset(isVis, false, sizeof(isVis)); 
    
    if (bfs(startX, startY)) {
        
        arr[startX][startY] = 'R';
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
