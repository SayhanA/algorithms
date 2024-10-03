#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Max = 1e5+5;
ll arr[Max];
ll groupSize[Max];

class Edge{
    public:
    ll u, v, w;
    Edge(ll u, ll v, ll w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

void dsu_init(ll n){
    for (ll i = 1; i <= n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

ll dsu_find(ll node){
    if(arr[node] == -1) return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union(ll node1, ll node2){
    ll parA = dsu_find(node1);
    ll parB = dsu_find(node2);

    if(groupSize[parA] > groupSize[parB]){
        arr[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }
    else{
        arr[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main(){
    ll n, e, a, b, w, totalCost = 0, removedroads = 0;
    cin >> n >> e;
    vector<Edge> EdgeList;
    dsu_init(n);

    while (e--)
    {
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a, b, w));
    }

    sort(EdgeList.begin(), EdgeList.end(), cmp);

    for(Edge child:EdgeList){
        ll parA = dsu_find(child.u);
        ll parB = dsu_find(child.v);

        if(parA != parB){
            dsu_union(child.u, child.v);
            totalCost += child.w;
        }else{
            removedroads++;
        }
    }
    
    bool isPossible = true;
    for (int i = 1; i <= n; i++)
    {
        if(dsu_find(1) != dsu_find(i)) isPossible = false;
    }
    
    if(isPossible) cout << removedroads << " " << totalCost << endl;
    else cout << "Not Possible\n";
    
    return 0;
}