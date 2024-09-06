#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
char arr[N][N];
bool isVis[N][N];
vector<pair<int,int>> v={{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int r, c;
int coun = 0;

void dsf(int x, int y)
{
    cout << x << " " << y << endl;
    if(arr[x][y] == 'B') coun++;
    isVis[x][y] = true;

    for(pair<int, int> child: v){
        int xc = child.first + x, yc = child.second + y;
        if(isVis[xc][yc] == false && xc >= 0 && xc < r && yc >= 0 && yc < c && arr[xc][yc] != '#'){
            dsf(xc, yc);
            isVis[xc][yc] = true;
        }
    }
}

int main()
{
    pair<int, int> A;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
                A = {i, j};
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    memset(isVis, false, sizeof(isVis));
    dsf(A.first, A.second);

    coun ? cout << "YES\n" : cout << "NO\n";

    return 0;
}