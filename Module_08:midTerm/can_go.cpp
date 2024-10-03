#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long int N = 1e6 + 5;
const long long int INF = LLONG_MAX;
vector<pair<int, int>> v[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        auto par = pq.top();
        pq.pop();

        ll cost = par.first;
        int val = par.second;

        for (pair<int, int> child : v[val]) {
            int childVal = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childVal]) {
                dis[childVal] = cost + childCost;
                pq.push({dis[childVal], childVal});
            }
        }
    }
}

int main() {
    ll n, e, a, b, c, s, t, x, y;
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
