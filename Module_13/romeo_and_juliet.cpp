// https://www.hackerrank.com/contests/phitron-monthly-programming-contest-a-batch-04-a-feb-2024/challenges/romeo-and-juliet-2
#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5+5;
vector<int> v[Max];
bool isVisited[Max];
int dis[Max];

void bfs(int src){
    queue<int> q;
    q.push(src);
    isVisited[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(int child:v[parent]){
            if(!isVisited[child]){
                q.push(child);
                isVisited[child] = true;
                dis[child] = dis[parent]+1;
            }
        }
    }
    
}

int main(){
    int n, e, a, b, x, y, k;
    cin >> n >> e;
    
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(dis, -1, sizeof(dis));

    cin >> x >> y >> k;
    bfs(x);

    if( dis[y] != -1 && dis[y] <= k*2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
    return 0;
}