#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool isVisited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    isVisited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (!isVisited[child])
            {
                q.push(child);
                isVisited[child] = true;
                parent[child] = par;
                level[child] = level[par] + 1;
            }
        }
    }
}

int main()
{
    int n, e, a, b;
    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(1);
    bool isPossible = false;

    vector<int> path;
    int x = n;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
        if (x == 1)
        {
            isPossible = true;
        }
    }

    if (isPossible)
    {
        cout << path.size() << endl;

        reverse(path.begin(), path.end());

        for (int val : path)
        {
            cout << val << " ";
        }
    }

    isPossible || cout << "IMPOSSIBLE\n";

    return 0;
}