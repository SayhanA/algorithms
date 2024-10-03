// #include <bits/stdc++.h>
// using namespace std;
// vector<int> arr[100];
// bool isVis[100];
// int dis_from_src[100];
// int dis_from_dir[100];

// void bfs(int src, int cas)
// {
//     queue<int> q;
//     q.push(src);
//     isVis[src] = false;
//     if (cas == 1)
//     {
//         dis_from_src[src] = 0;
//     }
//     else
//     {
//         dis_from_dir[src] = 0;
//     }

//     while (!q.empty())
//     {
//         int parent = q.front();
//         q.pop();

//         for (int child : arr[parent])
//         {
//             if (!isVis[child])
//             {
//                 q.push(child);
//                 isVis[child] = true;
//                 if (cas == 1)
//                 {
//                     dis_from_src[child] = dis_from_src[parent] + 1;
//                 }
//                 else
//                 {
//                     dis_from_dir[child] = dis_from_dir[parent] + 1;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         int n, r, u, v, s, d;
//         cin >> n >> r;

//         while (r--)
//         {
//             cin >> u >> v;
//             arr[u].push_back(v);
//             arr[v].push_back(u);
//         }

//         cin >> s >> d;

//         for (int i = 0; i < n; i++)
//         {
//             isVis[i] = false;
//             dis_from_src[i] = -1;
//         }
//         bfs(s, 1);

//         for (int i = 0; i < n; i++)
//         {
//             isVis[i] = false;
//             dis_from_dir[i] = -1;
//         }
//         bfs(s, 2);

//         int max_dist = INT_MIN;

//         for (int i = 0; i < n; i++)
//         {
//             int totalDis = dis_from_src[i] + dis_from_dir[i];
//             max_dist = max(max_dist, totalDis);
//         }

//         cout << max_dist << endl;

//         for (int i = 0; i < n; i++)
//         {
//             arr[i].clear();
//         }
        
//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100];  
bool isVis[100];        
int dis_from_src[100];  
int dis_from_dir[100];  


void bfs(int src, int dis[]) {
    queue<int> q;
    q.push(src);
    isVis[src] = true;  
    dis[src] = 0;       

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : arr[parent]) {
            if (!isVis[child]) {
                q.push(child);
                isVis[child] = true;
                dis[child] = dis[parent] + 1;  
            }
        }
    }
}

int main() {
    int t;  
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, r, u, v, s, d;
        cin >> n >> r;  

        
        for (int i = 0; i < n; i++) {
            arr[i].clear();
        }

        while (r--) {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        cin >> s >> d;  

        memset(isVis, false, sizeof(isVis));
        memset(dis_from_src, -1, sizeof(dis_from_src));

        bfs(s, dis_from_src);
        
        memset(isVis, false, sizeof(isVis));
        memset(dis_from_dir, -1, sizeof(dis_from_dir));

        bfs(d, dis_from_dir);
        
        int max_dist = 0;
        for (int i = 0; i < n; i++) {
            if (dis_from_src[i] != -1 && dis_from_dir[i] != -1) {
                max_dist = max(max_dist, dis_from_src[i] + dis_from_dir[i]);
            }
        }

        cout << "Case " << i << ": " << max_dist << endl;
    }
    return 0;
}
