// #include <bits/stdc++.h>
// using namespace std;
// const int Max = 1e5+5;
// int arr[Max];
// int groupSize[Max];

// class Edge{
//     public:
//     int u, v, w;
//     Edge(int u, int v, int w){
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };

// bool cmp(Edge a, Edge b){
//     return a.w < b.w;
// }

// void dsu_init(int n){
//     for (int i = 1; i <= n; i++)
//     {
//         arr[i] = -1;
//         groupSize[i] = 1;
//     }
// }

// int dsu_find(int node){
//     if(arr[node] == -1) return node;
//     return arr[node] = dsu_find(arr[node]);
// }

// void dsu_union(int node1, int node2){
//     int parA = dsu_find(node1);
//     int parB = dsu_find(node2);

//     if(groupSize[parA] > groupSize[parB]){
//         arr[parB] = parA;
//         groupSize[parA] += groupSize[parB];
//     }else{
//         arr[parA] = parB;
//         groupSize[parB] += groupSize[parA];
//     }
// }

// int main(){
//     int n, e, a, b, c, totalcost = 0, redundant = 0;
//     cin >> n >> e;
//     vector<Edge> edgelist;
//     dsu_init(n);

//     while (e--)
//     {
//         cin >> a >> b >> c;
//         edgelist.push_back(Edge(a, b, c));
//     }

//     sort(edgelist.begin(), edgelist.end(), cmp);
//     bool isPossible = true;

//     for(Edge child:edgelist){
//         // cout << child.u << " " << child.v << " " << child.w << endl;

//         int parA = dsu_find(child.u);
//         int parB = dsu_find(child.v);
//         if(parA == parB){
//             redundant += 1;

//             for(Edge child2:edgelist){
//                 if(child.u == child2.v && child.v == child2.u) isPossible = false;
//             }

//         }else{
//             dsu_union(child.u, child.v);
//             totalcost += child.w;
//         }
//     }

//     isPossible ? cout << redundant << " " << totalcost << endl : cout << "Not Possible\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 5;
int arr[Max];
int groupSize[Max];

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node)
{
    if (arr[node] == -1)
        return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union(int node1, int node2)
{
    int parA = dsu_find(node1);
    int parB = dsu_find(node2);

    if (parA != parB)
    {
        if (groupSize[parA] > groupSize[parB])
        {
            arr[parB] = parA;
            groupSize[parA] += groupSize[parB];
        }
        else
        {
            arr[parA] = parB;
            groupSize[parB] += groupSize[parA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgelist;
    dsu_init(n);

    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edgelist.push_back(Edge(a, b, c));
    }

    sort(edgelist.begin(), edgelist.end(), cmp);

    int totalCost = 0, redundant = 0;
    int edgesUsed = 0;

    for (Edge child : edgelist)
    {
        int parA = dsu_find(child.u);
        int parB = dsu_find(child.v);

        if (parA != parB)
        {
            dsu_union(child.u, child.v);
            totalCost += child.w;
            edgesUsed++;
        }
        else
        {

            redundant++;
        }
    }

    // cout << redundant << " " << totalCost << endl;
    
    bool possible = true; 

    for (int i = 1; i <= n; i++)
    {
        if(dsu_find(1) != dsu_find(i)) possible = false;
    }

    possible ? cout << redundant << " " << totalCost << endl : cout << "Not Possible\n";
    
    
    return 0;
}
