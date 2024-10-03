#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N], groupSize[N];

void dsu_init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;  
        groupSize[i] = 1; 
    }
}

int dsu_find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int a, int b) {
    int rootA = dsu_find(a);
    int rootB = dsu_find(b);

    if (rootA != rootB) {
        if (groupSize[rootA] < groupSize[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootB] = rootA; 
        groupSize[rootA] += groupSize[rootB];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dsu_init(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (dsu_find(i) == i) {
            components.push_back(i); 
        }
    }

    int k = components.size() - 1; 
    cout << k << endl;

    for (int i = 1; i < components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}
