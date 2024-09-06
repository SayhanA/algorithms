#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
char arr[N][N];
bool isVis[N][N];
vector<pair<int, int>> v={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int r, c;

void dsf(int x, int y){
    // cout << x << " " << y << endl;
    isVis[x][y] = true;
    for(pair<int, int> child:v){
        int cx = x + child.first, cy = y + child.second;
        if(isVis[cx][cy] == false && cx >= 0 && cy >= 0 && cx < r && cy < c && arr[cx][cy] != '#'){
            dsf(cx, cy);
            isVis[cx][cy] = true;
        }
    }
}

int main(){
    int cun = 0;
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
    
    memset(isVis, false, sizeof(isVis));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(arr[i][j] != '#' && !isVis[i][j]){
                dsf(i, j);
                cun++;
            }
        }
        // cout << endl;
    }

    cout << cun << endl;
    
    return 0;
}