// #include <bits/stdc++.h>
// using namespace std;
// const long long int N = 1e6+5;
// vector<pair<long long int, long long int>> v[N];
// long long int dis[N];

// class cmp
// {
// public:
//     bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
//     {
//         return a.second > b.second;
//     }
// };

// void djkstra(long long int src)
// {
//     priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
//     pq.push({src, 0});
//     dis[src] = 0;
//     while (!pq.empty())
//     {
//         pair<long long int, long long int> par = pq.top();
//         pq.pop();

//         long long int val = par.first;
//         long long int cost = par.second;

//         for(pair<long long int, long long int> child:v[val]){
//             long long int childVal = child.first;
//             long long int childCost = child.second;
//             if(cost + childCost < dis[childVal]){
//                 dis[childVal] = cost + childCost;
//                 pq.push({ childVal, dis[childVal]});
//             }
//         }
//     }
    
// }

// int main()
// {
//     long long int n, a, b, s, t, x;
//     long long int c, y, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         cin >> a >> b >> c;
//         v[a].push_back({b, c});
//     }

//     for (int i = 0; i < n; i++)
//     {
//         dis[i] = LLONG_MAX;
//     }

//     cin >> s;
//     djkstra(s);

//     cin >> t;
//     while (t--)
//     {
//         cin >> x >> y;
//         if(dis[x] > y) cout << "NO\n";
//         else cout << "YES\n"; 
//     }
    

//     // for (int i = 0; i < n; i++)
//     // {
//     //     for(pair<int, int> child:v[i]){
//     //         cout << i << " " << child.first << " " << child.second << endl;
//     //     }
//     // }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
const long long int INF = LLONG_MAX;
vector<pair<int, int>> v[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<long long int, int> a, pair<long long int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, cmp> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        auto par = pq.top();
        pq.pop();

        long long int cost = par.first;
        int val = par.second;

        if (cost > dis[val]) continue;

        for (pair<int, int> child : v[val]) {
            int childVal = child.first;
            long long int childCost = child.second;

            if (cost + childCost < dis[childVal]) {
                dis[childVal] = cost + childCost;
                pq.push({dis[childVal], childVal});
            }
        }
    }
}

int main() {
    long long int n, e, a, b, c, s, t, x, y;
    cin >> n >> e;

    while (e--) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }

    cin >> s;
    dijkstra(s);

    cin >> t;
    while (t--) {
        cin >> x >> y;

        if (dis[x] <= y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
