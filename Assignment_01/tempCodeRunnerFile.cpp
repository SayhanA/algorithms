#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
char arr[N][N];
bool isVis[N][N];
vector<pair<int, int>> v={{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int r, c;
int cunt = 0;

void dsf(int x, int y){
    cunt++;
    isVis[x][y] = true;
    for(pair<int, int> child : v){
    int cx = x + child.first, cy = y + child.second;
    if(cx >= 0 && cy >= 0 && cx < r && cy < c && !isVis[cx][cy] && arr[cx][cy] != '#'){
        dsf(cx, cy);
    }
}

}

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    }
    
    memset(isVis, false, sizeof(isVis));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(arr[i][j] != '#' && !isVis[i][j]){
                cunt = 0;
                dsf(i, j);
                pq.push(cunt);
            }
        }
    }

    while (!pq.empty()  )
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    
    return 0;
}