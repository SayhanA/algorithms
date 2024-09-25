#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; 
int parent[N]; 
bool visited[N];

bool bfs(int n) {
    queue<int> q;
    q.push(1);  
    visited[1] = true;
    parent[1] = -1;  

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << endl;

        if (node == n) return true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;  
                q.push(neighbor);
            }
        }
    }

    return false;  
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    if (bfs(n)) {
        bfs(n);
        // vector<int> path;
        // for (int v = n; v != -1; v = parent[v]) {
        //     path.push_back(v);
        // }

        // reverse(path.begin(), path.end()); 

        // cout << path.size() << endl;
        // for (int node : path) {
        //     cout << node << " ";
        // }
        // cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
