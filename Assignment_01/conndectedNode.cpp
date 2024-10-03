#include <bits/stdc++.h>
using namespace std;
const int N = 10e6;
vector<int> v[N];

int main()
{
    int n, e, a, b, q, src;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> q;
    while (q--)
    {
        priority_queue<int> pq;
        cin >> src;
        for(int child:v[src]){
            pq.push(child);
        }
        if(pq.empty()) cout << -1;
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    return 0;
}