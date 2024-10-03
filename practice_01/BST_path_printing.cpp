#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool isV[100];
int level[100];

void bst_level(int src)
{
    queue<int> q;
    q.push(src);
    isV[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout <<  par << endl;

        for (int child : v[par])
        {
            if (isV[child] == false)
            {
                q.push(child);
                level[child] = level[par] + 1;
                isV[child] = true;
            }
        }
    }
}

int main()
{
    int n, e, a, b, x, src, des;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> x;
    while (x--)
    {
        cin >> src >> des;
        // cout << src << " " << des << endl;
        memset(isV, false, sizeof(isV));
        memset(level, -1, sizeof(level));

        bst_level(src);

        cout << level[des] << endl;
    }

    return 0;
}