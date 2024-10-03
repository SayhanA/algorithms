#include <bits/stdc++.h>
using namespace std;
const int N = 20;
char arr[N][N];
bool isV[N][N];
int dis[N][N];
vector<pair<int, int>> p={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int  r, c;

// bool valid(int i, int j)
// {
//     if (i < 0 || i >= r || j < 0 || j >= c)
//         return false;
//     return true;
// }

void bsf(int x, int y){
    queue <pair<int, int>> q;
    q.push({x, y});
    isV[x][y] = true;
    dis[x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int px = par.first;
        int py = par.second; 

        // cout << px << " " << py << endl;

        for(pair<int, int> child:p){
            int ix = px+child.first;
            int iy = py+child.second;
            if(isV[ix][iy] == false && ix >= 0 && ix < r && iy >= 0 && iy < c ){
                q.push({ix, iy});
                isV[ix][iy] = true;
                dis[ix][iy] = dis[px][py] + 1;
            }
            // if (valid(ix, iy) == true && isV[ix][iy] == false)
            // {
            //     q.push({ix, iy});
            //     isV[ix][iy] = true;
            //     dis[ix][iy] = dis[px][py] + 1;
            // }
        }
    }
    
}

int main(){
    int x, y;
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
    cin >> x >> y;
    memset(isV, false, sizeof(isV));
    memset(dis, -1, sizeof(dis));
    bsf(x, y);

    cout << dis[2][3];
    
    return 0;
}

