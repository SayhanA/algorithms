// #include <bits/stdc++.h>
// using namespace std;
// int par[1005];
// int groupSize[1005];
// queue<pair<int, int>> removedRoad;
// queue<pair<int, int>> newRoad;

// void dsu_init(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         par[i] = -1;
//         groupSize[i] = 1;
//     }
// }

// int dsu_find(int node)
// {
//     if (par[node] == -1)
//         return node;
//     return par[node] = dsu_find(par[node]);
// }

// void dsu_union(int node1, int node2)
// {
//     // cout << node1 << " " << node2 << endl;
//     int parA = dsu_find(node1);
//     int parB = dsu_find(node2);

//     if (groupSize[parA] > groupSize[parB])
//     {
//         par[parB] = parA;
//         groupSize[parA] += groupSize[parB];
//     }
//     else
//     {
//         par[parA] = parB;
//         groupSize[parB] += groupSize[parA];
//     }
// }

// int main()
// {
//     int n, a, b;
//     cin >> n;
//     dsu_init(n);

//     for (int i = 1; i < n; i++)
//     {
//         cin >> a >> b;
//         int paA = dsu_find(a);
//         int paB = dsu_find(b);
//         if (paA == paB)
//         {
//             removedRoad.push({a, b});
//             continue;
//         }
//         else
//         {
//             dsu_union(a, b);
//         }
//     }



//     for (int i = 1; i <= n; i++)
//     {
//         if (dsu_find(1) != dsu_find(i))
//         {
//             dsu_union(1, i);
//             newRoad.push({1, i});
//         }
//     }
//     cout << newRoad.size() << endl;

//     while (!removedRoad.empty())
//     {
//         cout << removedRoad.front().first << " " << removedRoad.front().second << " ";
//         removedRoad.pop();
//     }
//     while (!newRoad.empty())
//     {
//         cout << newRoad.front().first << " " << newRoad.front().second << endl;
//         newRoad.pop();
//     }

//     return 0;
// }






#include <bits/stdc++.h>
using namespace std;

int par[1005];
int groupSize[1005];
queue<pair<int, int>> removedRoad;
queue<pair<int, int>> newRoad;

void dsu_init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = -1;        
        groupSize[i] = 1;   
    }
}

int dsu_find(int node) {
    if (par[node] == -1) return node;
    return par[node] = dsu_find(par[node]); 
}

void dsu_union(int node1, int node2) {
    int parA = dsu_find(node1);
    int parB = dsu_find(node2);

    if (parA != parB) {
        
        if (groupSize[parA] > groupSize[parB]) {
            par[parB] = parA;
            groupSize[parA] += groupSize[parB];
        } else {
            par[parA] = parB;
            groupSize[parB] += groupSize[parA];
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;

    dsu_init(n);  

    
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        int parA = dsu_find(a);
        int parB = dsu_find(b);

        if (parA == parB) {
            removedRoad.push({a, b});  
        } else {
            dsu_union(a, b);  
        }
    }

    
    for (int i = 2; i <= n; i++) {
        if (dsu_find(1) != dsu_find(i)) {
            dsu_union(1, i);
            newRoad.push({1, i});  
        }
    }

    
    int t = newRoad.size();
    cout << t << endl;

    
    while (!removedRoad.empty() && !newRoad.empty()) {
        pair<int, int> oldRoad = removedRoad.front();
        pair<int, int> newConnection = newRoad.front();
        removedRoad.pop();
        newRoad.pop();
        cout << oldRoad.first << " " << oldRoad.second << " " << newConnection.first << " " << newConnection.second << endl;
    }

    return 0;
}
